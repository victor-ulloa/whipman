// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoverComponent.h"
#include "GoalPlatform.generated.h"

class UBoxComponent;

UCLASS()
class WHIPMAN_API AGoalPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGoalPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *PlatformMesh;
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UBoxComponent *BoxCollider;
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UMoverComponent *MoverComponent;

	UFUNCTION()
	void OnStateUpdated(bool State);
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	
};
