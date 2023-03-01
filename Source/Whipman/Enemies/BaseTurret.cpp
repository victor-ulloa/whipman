// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTurret.h"
#include "Whipman/Misc/BaseProjectile.h"

ABaseTurret::ABaseTurret()
{
    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
    TurretMesh->SetupAttachment(RootComponent);
}

void ABaseTurret::Shoot()
{  
    // GetWorld()->SpawnActor(Projectile, SpawnPoint->GetComponentLocation());
}
