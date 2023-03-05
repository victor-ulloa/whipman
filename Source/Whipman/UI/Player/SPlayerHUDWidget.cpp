// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerHUDWidget.h"
#include "PlayerHUD.h"

#define LOCTEXT_NAMESPACE "PlayerHUD"

void SPlayerHUDWidget::Construct(const FArguments &InArgs)
{
    bCanSupportFocus = true;

    FString ImagePath = FPaths::ProjectContentDir() / TEXT("Assets/Images/crosshair.svg");
    FName BrushName = FName(*ImagePath);
    UE_LOG(LogTemp, Display, TEXT("TEST"));
    UE_LOG(LogTemp, Display, TEXT("%s"), *ImagePath);

    ChildSlot [
        SNew(SOverlay)
        + SOverlay::Slot()
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        [
            SNew(SImage)
            .Image(new FSlateVectorImageBrush(ImagePath, FVector2D(128, 128), FLinearColor::Black))
        ]

    ];
}

#undef LOCTEXT_NAMESPACE