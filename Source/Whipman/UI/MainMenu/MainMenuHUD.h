// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

class SConfirmationWidget;
class SMainMenuWidget;

UCLASS()
class WHIPMAN_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	TSharedPtr<SMainMenuWidget> MenuWidget;
	TSharedPtr<SConfirmationWidget> ConfirmationWidget;

	virtual void BeginPlay() override;

public:
	void ShowMenu();
	void RemoveMenu();
	void OpenLevel();
	void ShowQuitConfirmation();
	void RemoveQuitConfirmation();
	void ExitGame();

private:
	UGameViewportClient *ViewportClient;
};