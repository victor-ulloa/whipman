// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Whipman/PlayerCharacter.h"

ABaseProjectile::ABaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;
	ProjectileMovementComponent->ProjectileGravityScale = .0f;
}

void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
}

void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseProjectile::OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalizedImpulse, const FHitResult &Hit)
{
	if (APlayerCharacter *Player = Cast<APlayerCharacter>(OtherActor))
	{
		Player->OnPlayerHit();
	}
	Destroy();
}
