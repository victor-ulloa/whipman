// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class AGameOverHUD;

class WHIPMAN_API SGameOverWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGameOverWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<AGameOverHUD>, GameOverHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments &InArgs);

	FReply OnRestartClicked() const;
	FReply OnMainMenuClicked() const;

	TWeakObjectPtr<AGameOverHUD> GameOverHUD;
};
