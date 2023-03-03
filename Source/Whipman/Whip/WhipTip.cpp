// Fill out your copyright notice in the Description page of Project Settings.

#include "WhipTip.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AWhipTip::AWhipTip()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("TipMesh"));
	RootComponent = SphereCollider;
	SphereCollider->SetSimulatePhysics(false);
	SphereCollider->SetNotifyRigidBodyCollision(true);
	SphereCollider->SetWorldScale3D(FVector(2, 2, 2));

	SphereCollider->BodyInstance.SetCollisionProfileName("BlockAllDynamic");

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->ProjectileGravityScale = 0;
}

void AWhipTip::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovementComp->SetVelocityInLocalSpace(FireVelocity);
}

void AWhipTip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}