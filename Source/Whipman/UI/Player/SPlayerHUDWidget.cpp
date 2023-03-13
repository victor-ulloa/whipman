// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerHUDWidget.h"
#include "PlayerHUD.h"

#define LOCTEXT_NAMESPACE "PlayerHUD"

void SPlayerHUDWidget::Construct(const FArguments &InArgs)
{
    bCanSupportFocus = true;

    FString CrosshairPath = FPaths::ProjectContentDir() / TEXT("Assets/Vectors/crosshair.svg");
    // thin circle as crosshair

    ChildSlot 
    [
        SNew(SOverlay)

        // Crosshair
        + SOverlay::Slot()
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        [
            SNew(SImage)
            .Image(new FSlateVectorImageBrush(CrosshairPath, FVector2D(128, 128), FLinearColor::Black))
        ]

        // Heart
        
        + SOverlay::Slot()
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Top)
        [
            HeartContainer
        ]

    ];
}

void SPlayerHUDWidget::OnLivesChanged(int Lives)
{
    FString HeartsPath = FPaths::ProjectContentDir() / TEXT("Assets/Vectors/heart.svg");

    while (Lives != HeartContainer->NumSlots())
    {
        if (Lives < HeartContainer->NumSlots()) {
            HeartContainer->RemoveSlot(HeartContainer->GetSlot(HeartContainer->NumSlots() - 1).GetWidget());
        } else {
            TSharedRef<SImage, ESPMode::ThreadSafe> HeartImage = SNew(SImage).Image(new FSlateVectorImageBrush(HeartsPath, FVector2D(128, 128)));
            HeartContainer->AddSlot();
            HeartContainer->GetSlot(HeartContainer->NumSlots() - 1).AttachWidget(HeartImage);
        }
    }
}

#undef LOCTEXT_NAMESPACE