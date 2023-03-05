// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerHUDWidget.h"
#include "PlayerHUD.h"

#define LOCTEXT_NAMESPACE "PlayerHUD"

void SPlayerHUDWidget::Construct(const FArguments &InArgs)
{
    bCanSupportFocus = true;

    PlayerHUD = InArgs._PlayerHUD;
    ChildSlot [
        SNew(SOverlay)
    ];
}

#undef LOCTEXT_NAMESPACE