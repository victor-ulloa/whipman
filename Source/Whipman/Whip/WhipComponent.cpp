// Fill out your copyright notice in the Description page of Project Settings.


#include "WhipComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "WhipTip.h"

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
void UWhipComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
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
	UE_LOG(LogTemp, Display, TEXT("%f %f %f"), TargetLocation.X, TargetLocation.Y, TargetLocation.Z);
	WhipState = EWhipState::Firing;
	FVector StartLocation =  GetStartLocation();
	FVector VectorDirection = (TargetLocation - StartLocation);
	VectorDirection.Normalize();

	FActorSpawnParameters SpawnInfo;
	FTransform ActorTransform  = FTransform(StartLocation);
	AWhipTip *WhipTip = GetWorld()->SpawnActorDeferred<AWhipTip>(AWhipTip::StaticClass(), ActorTransform);
	WhipTip->FireVelocity = VectorDirection * FireSpeed;
	UGameplayStatics::FinishSpawningActor(WhipTip, ActorTransform);
}

FVector UWhipComponent::GetStartLocation()
{
	FVector TransformedDirection = UKismetMathLibrary::TransformDirection(GetOwner()->GetActorTransform(), WhipOffset);
	FVector StartingLocation = TransformedDirection + GetOwner()->GetActorLocation();
    return StartingLocation;
}
