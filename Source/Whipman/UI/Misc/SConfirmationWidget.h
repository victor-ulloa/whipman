// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class WHIPMAN_API SConfirmationWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SConfirmationWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MenuHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments &InArgs);

	FReply OnConfirmationClicked();
	FReply OnCancelClicked();

	TWeakObjectPtr<class AMainMenuHUD> MenuHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
