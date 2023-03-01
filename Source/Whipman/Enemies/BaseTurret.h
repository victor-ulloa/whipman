// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Whipman/BasePawn.h"
#include "BaseTurret.generated.h"

class ABaseProjectile;

UCLASS()
class WHIPMAN_API ABaseTurret : public ABasePawn
{
	GENERATED_BODY()

public:
	ABaseTurret();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *TurretMesh;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<ABaseProjectile> Projectile;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;

	void CheckFireCondition();
	void Fire();
};
