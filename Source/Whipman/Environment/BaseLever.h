// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Whipman/Interfaces/Actionable.h"
#include "BaseLever.generated.h"

class UBoxComponent;

UCLASS()
class WHIPMAN_API ABaseLever : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseLever();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "State")
	bool LeverOn = false;

private:
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *LeverMesh;

	virtual void OnOverlap() override;

	void SwitchState();
	void ReloadComponent();
};
