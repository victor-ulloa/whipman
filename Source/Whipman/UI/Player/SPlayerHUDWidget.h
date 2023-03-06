// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class APlayerHUD;

class WHIPMAN_API SPlayerHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlayerHUDWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<APlayerHUD>, PlayerHUD)

	SLATE_END_ARGS()

	TWeakObjectPtr<APlayerHUD> PlayerHUD;

	TSharedRef<SHorizontalBox, ESPMode::ThreadSafe> HeartContainer = SNew(SHorizontalBox);

	void OnLivesChanged(int Lives);

	void Construct(const FArguments &InArgs);
};
