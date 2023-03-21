// Fill out your copyright notice in the Description page of Project Settings.

#include "SWinWidget.h"
#include "WinHUD.h"

#define LOCTEXT_NAMESPACE "GameOver"

void SWinWidget::Construct(const FArguments &InArgs)
{
    bCanSupportFocus = true;

    WinHUD = InArgs._WinHUD;

    const FText TitleText = LOCTEXT("TitleText", "You Win!");
    const FText RestartText = LOCTEXT("RestartText", "Restart");
    const FText MainMenuText = LOCTEXT("MainMenuText", "Main Menu");

    const FMargin ButtonPadding = FMargin(10.f);
    const FMargin TitlePadding = FMargin(50.f);

    FSlateFontInfo TitleTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
    TitleTextStyle.Size = 60.f;

    FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
    ButtonTextStyle.Size = 40.f;

    ChildSlot [
        SNew(SOverlay)
        + SOverlay::Slot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        [
            SNew(SImage)
            .ColorAndOpacity(FColor::Blue)
        ]

        + SOverlay::Slot()
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        [
            SNew(SVerticalBox)


            // Title text
            + SVerticalBox::Slot()
            .Padding(TitlePadding)
            [
                SNew(STextBlock)
                .Font(TitleTextStyle)
                .Text(TitleText)
                .Justification(ETextJustify::Center)
            ]

            // Restart Level Button
            + SVerticalBox::Slot()
            .Padding(ButtonPadding)
            [
                SNew(SButton)
                .OnClicked(this, &SWinWidget::OnRestartClicked)
                [
                    SNew(STextBlock)
                    .Font(ButtonTextStyle)
                    .Text(RestartText)
                    .Justification(ETextJustify::Center)
                ]
            ]


            // MainMenu Level Button
            + SVerticalBox::Slot()
            .Padding(ButtonPadding)
            [
                SNew(SButton)
                .OnClicked(this, &SWinWidget::OnMainMenuClicked)
                [
                    SNew(STextBlock)
                    .Font(ButtonTextStyle)
                    .Text(MainMenuText)
                    .Justification(ETextJustify::Center)
                ]
            ]
        ]
    ];
}

FReply SWinWidget::OnRestartClicked() const
{
    WinHUD->OpenLevel();
    return FReply::Handled();
}

FReply SWinWidget::OnMainMenuClicked() const
{
    WinHUD->OpenMainMenu();
    return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
