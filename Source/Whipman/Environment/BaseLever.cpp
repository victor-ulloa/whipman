// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLever.h"
#include "Whipman/BaseGameState.h"
#include "Components/BoxComponent.h"

// Sets default values
ABaseLever::ABaseLever()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverMesh"));
	RootComponent = LeverMesh;
}

void ABaseLever::BeginPlay()
{
	Super::BeginPlay();

	LevelGameState = GetWorld()->GetGameState<ABaseGameState>();
	LevelGameState->RegisterLever(this);
}

void ABaseLever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseLever::OnOverlap()
{
	UE_LOG(LogTemp, Display, TEXT("OVERLAP"));
	SwitchState();
	if(LevelGameState) {
		LevelGameState->CheckLeverStates();
	}
}

void ABaseLever::OnInteractable()
{
	UE_LOG(LogTemp, Display, TEXT("Interactable"));
}

void ABaseLever::SwitchState()
{
	LeverOn = !LeverOn;
	ReloadComponent();
}

void ABaseLever::ReloadComponent()
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Pitch = 180;
	SetActorRotation(CurrentRotation);
}
