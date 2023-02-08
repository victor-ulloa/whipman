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
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController *PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(TankMappingContext, 0);
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
        // AddControllerYawInput(DirectionalValue.X * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
    }
}

void ABaseCharacter::Look(const FInputActionValue &Value)
{
    const FVector2D LookAxisValue = Value.Get<FVector2D>();
    if (GetController()){
        // CONTROL CAMERA WITH MOUSE
        AddControllerYawInput(LookAxisValue.X * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
        AddControllerPitchInput(LookAxisValue.Y * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this));
        
    }
}


void ABaseCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ABaseCharacter::MoveForward);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Look);
    }
}

