// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuHUD.h"
#include "SMainMenuWidget.h"
#include "Whipman/UI/Misc/SConfirmationWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();
    ViewportClient = GetWorld()->GetGameViewport();
    ShowMenu();
}

void AMainMenuHUD::ShowMenu()
{
    MenuWidget = SNew(SMainMenuWidget).MenuHUD(this);
    ViewportClient->AddViewportWidgetContent(MenuWidget.ToSharedRef());
    UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
}

void AMainMenuHUD::RemoveMenu()
{
    ViewportClient->RemoveViewportWidgetContent(MenuWidget.ToSharedRef());
}

void AMainMenuHUD::OpenLevel()
{
    PlayerOwner->bShowMouseCursor = false;
    PlayerOwner->SetInputMode(FInputModeGameOnly());
    RemoveMenu();
    UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
    UGameplayStatics::OpenLevel(this, "Level");
}

void AMainMenuHUD::ShowQuitConfirmation()
{
    ConfirmationWidget = SNew(SConfirmationWidget).MenuHUD(this);
    ViewportClient->AddViewportWidgetContent(ConfirmationWidget.ToSharedRef(), 1);
}

void AMainMenuHUD::RemoveQuitConfirmation()
{
    ViewportClient->RemoveViewportWidgetContent(ConfirmationWidget.ToSharedRef());
}

void AMainMenuHUD::ExitGame()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}
