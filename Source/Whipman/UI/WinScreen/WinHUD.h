// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WinHUD.generated.h"

class SWinWidget;

UCLASS()
class WHIPMAN_API AWinHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	TSharedPtr<SWinWidget> WinWidget;

public:
	void ShowUI();
	void RemoveUI();
	void OpenLevel();
	void OpenMainMenu();

private:
	UGameViewportClient *ViewportClient;
	
};
