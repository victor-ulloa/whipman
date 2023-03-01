// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Whipman/BasePawn.h"
#include "Whipman/Misc/BaseProjectile.h"
#include "BaseTurret.generated.h"

UCLASS()
class WHIPMAN_API ABaseTurret : public ABasePawn
{
	GENERATED_BODY()

public:
	ABaseTurret();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *TurretMesh;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<ABaseProjectile> Projectile;

	void Shoot();
};
