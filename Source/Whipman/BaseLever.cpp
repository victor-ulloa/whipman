// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLever.h"
#include "Components/BoxComponent.h"

// Sets default values
ABaseLever::ABaseLever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BasicMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BasicMesh"));
	RootComponent = BasicMesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseLever::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseLever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

