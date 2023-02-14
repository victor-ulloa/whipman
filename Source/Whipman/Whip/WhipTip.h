// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WhipTip.generated.h"

UCLASS()
class WHIPMAN_API AWhipTip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWhipTip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
