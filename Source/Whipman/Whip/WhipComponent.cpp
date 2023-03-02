// Fill out your copyright notice in the Description page of Project Settings.

#include "WhipComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "WhipTip.h"
#include "WhipCable.h"
#include "Whipman/PlayerCharacter.h"
#include "Whipman/Interfaces/Actionable.h"

// Sets default values for this component's properties
UWhipComponent::UWhipComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UWhipComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UWhipComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UWhipComponent::IsInUse()
{
	return WhipState != EWhipState::ReadyToFire;
}

void UWhipComponent::FireWhip(FVector TargetLocation)
{
	WhipState = EWhipState::Firing;

	FVector StartLocation = GetStartLocation();
	FVector VectorDirection = (TargetLocation - StartLocation);
	VectorDirection.Normalize();

	// Spawn and attach tip

	FActorSpawnParameters SpawnInfo;
	FTransform ActorTransform = FTransform(StartLocation);
	WhipTip = GetWorld()->SpawnActorDeferred<AWhipTip>(AWhipTip::StaticClass(), ActorTransform);
	WhipTip->FireVelocity = VectorDirection * FireSpeed;
	WhipTip->SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &UWhipComponent::OnOverlapBegin);
	WhipTip->SphereCollider->SetCollisionProfileName(TEXT("OverlapAll"));
	UGameplayStatics::FinishSpawningActor(WhipTip, ActorTransform);

	// Spawn and attach cable

	WhipCable = GetWorld()->SpawnActor<AWhipCable>(AWhipCable::StaticClass(), StartLocation, UKismetMathLibrary::MakeRotFromX(VectorDirection));
	WhipCable->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepWorldTransform);
	WhipCable->CableComponent->EndLocation = FVector::ZeroVector;
	WhipCable->CableComponent->SetAttachEndTo(WhipTip, TEXT(""));
	WhipCable->CableComponent->CableWidth = 1.25f;
	WhipCable->CableComponent->bEnableStiffness = true;
	WhipCable->CableComponent->SubstepTime = 0.005f;
	WhipCable->CableComponent->SetCollisionProfileName(TEXT("OverlapAll"));

	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &UWhipComponent::CancelWhip, WhipTimer, false);
}

void UWhipComponent::CancelWhip()
{
	if (WhipTip && WhipCable)
	{
		WhipTip->Destroy();
		WhipTip = nullptr;

		WhipCable->Destroy();
		WhipCable = nullptr;

		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &UWhipComponent::CancelWhip, WhipTimer, false);
		WhipState = EWhipState::Cooldown;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &UWhipComponent::ResetStatus, Cooldown, false);
	}
}

void UWhipComponent::ResetStatus()
{
	WhipState = EWhipState::ReadyToFire;
}

FVector UWhipComponent::GetStartLocation()
{
	FVector TransformedDirection = UKismetMathLibrary::TransformDirection(GetOwner()->GetActorTransform(), WhipOffset);
	FVector StartingLocation = TransformedDirection + GetOwner()->GetActorLocation();
	return StartingLocation;
}

void UWhipComponent::OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (SweepResult.GetActor()->IsA(APlayerCharacter::StaticClass()))
	{
		return;
	}
	IActionable *object = Cast<IActionable>(SweepResult.GetActor());
	if (object)
	{
		object->OnOverlap();
	}
	CancelWhip();
}