// Fill out your copyright notice in the Description page of Project Settings.

#include "GoalPlatform.h"
#include "Components/BoxComponent.h"
#include "Whipman/BaseGameState.h"
#include "Whipman/PlayerCharacter.h"
#include "MoverComponent.h"

// Sets default values
AGoalPlatform::AGoalPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);

	MoverComponent = CreateDefaultSubobject<UMoverComponent>(TEXT("MoverComponent"));
}

// Called when the game starts or when spawned
void AGoalPlatform::BeginPlay()
{
	Super::BeginPlay();
	ABaseGameState *LevelGameState = GetWorld()->GetGameState<ABaseGameState>();
	LevelGameState->OnStateUpdatedDelegate.BindUObject(this, &AGoalPlatform::OnStateUpdated);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AGoalPlatform::OnOverlapBegin);
}

// Called every frame
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
			UE_LOG(LogTemp, Display, TEXT("WINS"));
		}
	}
}
