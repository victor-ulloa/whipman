// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTurret.h"
#include "Whipman/Misc/BaseProjectile.h"
#include "TimerManager.h"

ABaseTurret::ABaseTurret()
{
    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
    TurretMesh->SetupAttachment(RootComponent);
    
}

void ABaseTurret::BeginPlay()
{
    Super::BeginPlay();
    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ABaseTurret::Fire, FireRate, true);
}

void ABaseTurret::CheckFireCondition()
{

}

void ABaseTurret::Fire()
{  
    FVector Location = SpawnPoint->GetComponentLocation();
    GetWorld()->SpawnActor<ABaseProjectile>(Projectile, SpawnPoint->GetComponentLocation(), GetActorRotation());
}
