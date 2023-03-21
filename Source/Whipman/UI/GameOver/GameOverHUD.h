// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameOverHUD.generated.h"

class SGameOverWidget;

UCLASS()
class WHIPMAN_API AGameOverHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	TSharedPtr<SGameOverWidget> GameOverWidget;

public:
	void ShowUI();
	void RemoveUI();
	void OpenLevel();
	void OpenMainMenu();

private:
	UGameViewportClient *ViewportClient;

};
