// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Whipman/Environment/BaseLever.h"
#include "BaseGameState.generated.h"

DECLARE_DELEGATE_OneParam(FOnStateUpdated, bool);
UCLASS()
class WHIPMAN_API ABaseGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	FOnStateUpdated OnStateUpdatedDelegate;

	UPROPERTY(EditAnywhere, Category = "GameConfigs")
	TArray<ABaseLever*> Levers;

	void RegisterLever(ABaseLever *NewLever);
	void CheckLeverStates();

	UPROPERTY(EditAnywhere, Category = "State")
	bool AreAllLeversOn = false;
	
};
