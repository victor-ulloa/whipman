// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Whip/WhipComponent.h"

APlayerCharacter::APlayerCharacter()
{
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(RootComponent);
    Camera->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
    Camera->bUsePawnControlRotation = true;

	Whip = CreateDefaultSubobject<UWhipComponent>(TEXT("Whip"));
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(WhipAction, ETriggerEvent::Triggered, this, &APlayerCharacter::FireWhip);
    }
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController *PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(CharacterMappingContext, 0);
        }
    }
}

void APlayerCharacter::Move(const FInputActionValue &Value)
{
    const FVector2D DirectionalValue = Value.Get<FVector2D>();

    if (GetController() && (DirectionalValue.X != 0.f || DirectionalValue.Y != 0.f))
    {
        AddMovementInput(GetActorForwardVector(), DirectionalValue.Y * Speed * UGameplayStatics::GetWorldDeltaSeconds(this));
        AddMovementInput(GetActorRightVector(), DirectionalValue.X * Speed * UGameplayStatics::GetWorldDeltaSeconds(this));
    }
}

void APlayerCharacter::Look(const FInputActionValue &Value)
{
    const FVector2D LookAxisValue = Value.Get<FVector2D>();
    if (GetController())
    {
        AddControllerYawInput(LookAxisValue.X * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
        AddControllerPitchInput(LookAxisValue.Y * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
    }
}

void APlayerCharacter::FireWhip(const FInputActionValue &Value)
{
	if (!Whip->IsInUse())
    {
        FHitResult HitResult;
        FVector StartLocation = Camera->GetComponentLocation();
        FVector EndLocation = Camera->GetForwardVector() * WhipRange + StartLocation;
        FCollisionQueryParams TraceParams;

        GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);
        // DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 5.f);
        FVector TargetLocation = EndLocation;
        if (AActor *HitActor = HitResult.GetActor())
        {
            TargetLocation = HitResult.ImpactPoint;
        }
        Whip->FireWhip(TargetLocation);
    }
}
