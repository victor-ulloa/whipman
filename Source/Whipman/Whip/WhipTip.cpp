// Fill out your copyright notice in the Description page of Project Settings.


#include "WhipTip.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AWhipTip::AWhipTip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TipMesh = CreateDefaultSubobject<USphereComponent>(TEXT("TipMesh"));
	RootComponent = TipMesh;

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void AWhipTip::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovementComp->SetVelocityInLocalSpace(FireVelocity);
	UE_LOG(LogTemp, Display, TEXT("%f %f %f"), FireVelocity.X, FireVelocity.Y, FireVelocity.Z);
	UE_LOG(LogTemp, Display, TEXT("SPAWNED"));
}

// Called every frame
void AWhipTip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Display, TEXT("%f %f %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
}

