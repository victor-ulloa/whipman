// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class AWinHUD;

class WHIPMAN_API SWinWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWinWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<AWinHUD>, WinHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments &InArgs);

	FReply OnRestartClicked() const;
	FReply OnMainMenuClicked() const;

	TWeakObjectPtr<AWinHUD> WinHUD;
};
