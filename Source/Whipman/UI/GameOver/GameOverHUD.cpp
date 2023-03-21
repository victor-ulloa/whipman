// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverHUD.h"
#include "SGameOverWidget.h"
#include "Kismet/GameplayStatics.h"

void AGameOverHUD::BeginPlay()
{
    Super::BeginPlay();
    PlayerOwner->bShowMouseCursor = true;
    ViewportClient = GetWorld()->GetGameViewport();
    GameOverWidget = SNew(SGameOverWidget).GameOverHUD(this);
    ViewportClient->AddViewportWidgetContent(GameOverWidget.ToSharedRef());
}

void AGameOverHUD::ShowUI()
{
    GameOverWidget = SNew(SGameOverWidget).GameOverHUD(this);
    ViewportClient->AddViewportWidgetContent(GameOverWidget.ToSharedRef());
}

void AGameOverHUD::RemoveUI()
{
    ViewportClient->RemoveViewportWidgetContent(GameOverWidget.ToSharedRef());
}

void AGameOverHUD::OpenLevel()
{
    PlayerOwner->bShowMouseCursor = false;
    PlayerOwner->SetInputMode(FInputModeGameOnly());
    RemoveUI();
    UGameplayStatics::OpenLevel(this, "Level");
}

void AGameOverHUD::OpenMainMenu()
{
    RemoveUI();
    UGameplayStatics::OpenLevel(this, "MainMenuLevel");
}
