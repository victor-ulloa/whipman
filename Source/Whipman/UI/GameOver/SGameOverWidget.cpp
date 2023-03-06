// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameOverWidget.h"
#include "GameOverHUD.h"

#define LOCTEXT_NAMESPACE "GameOver"

void SGameOverWidget::Construct(const FArguments &InArgs)
{
    bCanSupportFocus = true;

    GameOverHUD = InArgs._GameOverHUD;

    ChildSlot [
        SNew(SOverlay)
        + SOverlay::Slot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        [
            SNew(SImage)
            .ColorAndOpacity(FColor::Blue)
        ]
    ];
}

#undef LOCTEXT_NAMESPACE