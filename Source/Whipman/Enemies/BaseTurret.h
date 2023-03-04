// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Whipman/BasePawn.h"
#include "Whipman/Interfaces/Actionable.h"
#include "BaseTurret.generated.h"

class ABaseProjectile;

UCLASS()
class WHIPMAN_API ABaseTurret : public ABasePawn, public IActionable
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
	UPROPERTY(EditAnywhere, Category = "Turret", meta = (AllowPrivateAccess = true))
	float TimeDisabled;
	FTimerHandle FireRateTimerHandle;
	UPROPERTY(EditAnywhere, Category = "Turret", meta = (AllowPrivateAccess = true))
	
	float FireRate = 2.f;
	bool isEnabled = true;

	void Fire();
	virtual void OnOverlap() override;
};
