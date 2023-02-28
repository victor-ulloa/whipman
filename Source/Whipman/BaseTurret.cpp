// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTurret.h"

ABaseTurret::ABaseTurret()
{
    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
    TurretMesh->SetupAttachment(RootComponent);
}
