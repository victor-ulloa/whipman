// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverHUD.h"
#include "SGameOverWidget.h"

void AGameOverHUD::BeginPlay()
{
    Super::BeginPlay();
    PlayerOwner->bShowMouseCursor = true;
    UGameViewportClient *ViewportClient = GetWorld()->GetGameViewport();
    GameOverWidget = SNew(SGameOverWidget).GameOverHUD(this);
    ViewportClient->AddViewportWidgetContent(GameOverWidget.ToSharedRef());
}
