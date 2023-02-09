// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLever.generated.h"

class UBoxComponent;

UCLASS()
class WHIPMAN_API ABaseLever : public AActor
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

private:
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *BasicMesh;
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UBoxComponent *TriggerBox;
};
