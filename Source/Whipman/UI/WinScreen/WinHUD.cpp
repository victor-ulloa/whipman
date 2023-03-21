// Fill out your copyright notice in the Description page of Project Settings.

#include "WinHUD.h"
#include "SWinWidget.h"
#include "Kismet/GameplayStatics.h"

void AWinHUD::BeginPlay()
{
    Super::BeginPlay();
    PlayerOwner->bShowMouseCursor = true;
    ViewportClient = GetWorld()->GetGameViewport();
    WinWidget = SNew(SWinWidget).WinHUD(this);
    ViewportClient->AddViewportWidgetContent(WinWidget.ToSharedRef());
}

void AWinHUD::ShowUI()
{
    WinWidget = SNew(SWinWidget).WinHUD(this);
    ViewportClient->AddViewportWidgetContent(WinWidget.ToSharedRef());
}

void AWinHUD::RemoveUI()
{
    ViewportClient->RemoveViewportWidgetContent(WinWidget.ToSharedRef());
}

void AWinHUD::OpenLevel()
{
    PlayerOwner->bShowMouseCursor = false;
    PlayerOwner->SetInputMode(FInputModeGameOnly());
    RemoveUI();
    UGameplayStatics::OpenLevel(this, "Level");
}

void AWinHUD::OpenMainMenu()
{
    RemoveUI();
    UGameplayStatics::OpenLevel(this, "MainMenuLevel");
}