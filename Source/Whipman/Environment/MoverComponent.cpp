// Fill out your copyright notice in the Description page of Project Settings.

#include "MoverComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoverComponent::UMoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMoverComponent::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
}

// Called every frame
void UMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TargetLocation = OriginalLocation;
	if (ShouldMove)
	{
		TargetLocation = OriginalLocation + MoveOffset;
	}

	FVector CurrentLocation = GetOwner()->GetActorLocation();

	float Speed = MoveOffset.Length() / MoveTime;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner()->SetActorLocation(NewLocation);
}

void UMoverComponent::SetShouldMove(bool NewShouldMove)
{
	if (NewShouldMove)
	{
		UE_LOG(LogTemp, Display, TEXT("TRUE"));
	} else {
		UE_LOG(LogTemp, Display, TEXT("FALSE"));
	}
	
	ShouldMove = NewShouldMove;
}
