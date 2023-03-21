// Fill out your copyright notice in the Description page of Project Settings.

#include "GoalPlatform.h"
#include "Components/BoxComponent.h"
#include "Whipman/BaseGameState.h"
#include "Whipman/PlayerCharacter.h"
#include "MoverComponent.h"
#include "Kismet/GameplayStatics.h"

AGoalPlatform::AGoalPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);

	MoverComponent = CreateDefaultSubobject<UMoverComponent>(TEXT("MoverComponent"));
}

void AGoalPlatform::BeginPlay()
{
	Super::BeginPlay();
	ABaseGameState *LevelGameState = GetWorld()->GetGameState<ABaseGameState>();
	LevelGameState->OnStateUpdatedDelegate.BindUObject(this, &AGoalPlatform::OnStateUpdated);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AGoalPlatform::OnOverlapBegin);
}

void AGoalPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGoalPlatform::OnStateUpdated(bool State)
{
	if (MoverComponent)
	{
		MoverComponent->SetShouldMove(State);
	}
}

void AGoalPlatform::OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (Cast<APlayerCharacter>(otherActor))
	{
		if (GetWorld()->GetGameState<ABaseGameState>()->AreAllLeversOn)
		{
			UGameplayStatics::OpenLevel(this, "WinLevel");
		}
	}
}
