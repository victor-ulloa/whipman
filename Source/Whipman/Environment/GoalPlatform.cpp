// Fill out your copyright notice in the Description page of Project Settings.

#include "GoalPlatform.h"
#include "Components/BoxComponent.h"
#include "Whipman/BaseGameState.h"

// Sets default values
AGoalPlatform::AGoalPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGoalPlatform::BeginPlay()
{
	Super::BeginPlay();
	ABaseGameState *LevelGameState = GetWorld()->GetGameState<ABaseGameState>();
	LevelGameState->OnStateUpdatedDelegate.BindUObject(this, &AGoalPlatform::OnStateUpdated);
}

// Called every frame
void AGoalPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGoalPlatform::OnStateUpdated(bool State)
{
	if (State)
	{
		UE_LOG(LogTemp, Display, TEXT("ACTIVATE PLATFORM"));
	}
}
