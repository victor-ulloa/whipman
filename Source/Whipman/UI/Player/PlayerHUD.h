// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class SPlayerHUDWidget;


UCLASS()
class WHIPMAN_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	TSharedPtr<SPlayerHUDWidget> PlayerHUDWidget;

	void ShowMenu();
	void RemoveMenu();
	void OnLivesChanged(int Lives);

private:
	UGameViewportClient *ViewportClient;
};
