// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"
#include "SPlayerHUDWidget.h"

void APlayerHUD::BeginPlay()
{
    Super::BeginPlay();
    ViewportClient = GetWorld()->GetGameViewport();
    ShowMenu();
}

void APlayerHUD::ShowMenu()
{
    PlayerHUDWidget = SNew(SPlayerHUDWidget).PlayerHUD(this);
    ViewportClient->AddViewportWidgetContent(PlayerHUDWidget.ToSharedRef());
}

void APlayerHUD::RemoveMenu()
{
    ViewportClient->RemoveViewportWidgetContent(PlayerHUDWidget.ToSharedRef());
}

void APlayerHUD::OnLivesChanged(int Lives)
{
    PlayerHUDWidget.ToSharedRef()->OnLivesChanged(Lives);
}