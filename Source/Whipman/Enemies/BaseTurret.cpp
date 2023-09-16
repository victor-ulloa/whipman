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

void ABaseTurret::Fire()
{
    if (!isEnabled)
    {
        return;
    }
    GetWorld()->SpawnActor<ABaseProjectile>(Projectile, SpawnPoint->GetComponentLocation(), GetActorRotation());
}

void ABaseTurret::OnOverlap()
{
    if (isEnabled)
    {
        isEnabled = false;
        FTimerHandle DisabledTimerHandle;
        GetWorldTimerManager().SetTimer(DisabledTimerHandle, FTimerDelegate::CreateLambda([this] { isEnabled = true; }), TimeDisabled, false);
    }
}
