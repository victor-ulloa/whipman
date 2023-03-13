// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDeathBox.generated.h"

class UBoxComponent;

UCLASS()
class WHIPMAN_API ABaseDeathBox : public AActor
{
	GENERATED_BODY()

	
public:
	ABaseDeathBox();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UBoxComponent *BoxCollider;
	
	UFUNCTION()
	void OnDeathBoxBeginOverlap(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
