// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLever.h"
#include "Components/BoxComponent.h"

// Sets default values
ABaseLever::ABaseLever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverMesh"));
	RootComponent = LeverMesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetCollisionProfileName("TriggerLever");
	
}

// Called when the game starts or when spawned
void ABaseLever::BeginPlay()
{
	Super::BeginPlay();
	
	// TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseLever::OnOverlapBegin);
}

// Called every frame
void ABaseLever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// void ABaseLever::OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
// {
// 	SwitchState();
// }

void ABaseLever::OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
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
