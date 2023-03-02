// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EWhipState.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum EWhipState
{
     ReadyToFire         UMETA(DisplayName = "ReadyToFire"),
     Firing              UMETA(DisplayName = "Firing"),
     Cooldown            UMETA(DisplayName = "Cooldown"),
};