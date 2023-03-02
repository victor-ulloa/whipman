// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Whip/WhipComponent.h"
#include "DrawDebugHelpers.h"

ABaseCharacter::ABaseCharacter()
{
    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    SkeletalMesh->SetupAttachment(RootComponent);

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("PawnMovement"));
    MovementComponent->UpdatedComponent = RootComponent;

    Whip = CreateDefaultSubobject<UWhipComponent>(TEXT("Whip"));
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController *PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(CharacterMappingContext, 0);
        }
    }
}

void ABaseCharacter::MoveForward(const FInputActionValue &Value)
{
    const FVector2D DirectionalValue = Value.Get<FVector2D>();

    if (GetController() && (DirectionalValue.X != 0.f || DirectionalValue.Y != 0.f))
    {
        FVector Forward = GetActorForwardVector();
        AddMovementInput(Forward, DirectionalValue.Y * Speed * UGameplayStatics::GetWorldDeltaSeconds(this));
        FVector Right = GetActorRightVector();
        AddMovementInput(Right, DirectionalValue.X * Speed * UGameplayStatics::GetWorldDeltaSeconds(this));
    }
}

void ABaseCharacter::Look(const FInputActionValue &Value)
{
    const FVector2D LookAxisValue = Value.Get<FVector2D>();
    if (GetController())
    {
        AddControllerYawInput(LookAxisValue.X * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
        AddControllerPitchInput(LookAxisValue.Y * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
    }
}

void ABaseCharacter::FireWhip(const FInputActionValue &Value)
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

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ABaseCharacter::MoveForward);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Look);
        EnhancedInputComponent->BindAction(WhipAction, ETriggerEvent::Triggered, this, &ABaseCharacter::FireWhip);
    }
}
