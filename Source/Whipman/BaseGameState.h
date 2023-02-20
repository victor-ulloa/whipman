// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "BaseLever.h"
#include "BaseGameState.generated.h"

/**
 * 
 */
UCLASS()
class WHIPMAN_API ABaseGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "GameConfigs")
	TArray<ABaseLever*> Levers;
};
