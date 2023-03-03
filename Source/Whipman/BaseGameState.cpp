// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Whipman/Environment/BaseLever.h"

void ABaseGameState::RegisterLever(ABaseLever *NewLever)
{
    Levers.Add(NewLever);
}

void ABaseGameState::CheckLeverStates()
{
    AreAllLeversOn = true;
    for (ABaseLever *Lever : Levers)
    {
        AreAllLeversOn &= Lever->LeverOn;
    }
    UE_LOG(LogTemp, Display, TEXT("%d"), Levers.Num());
}
