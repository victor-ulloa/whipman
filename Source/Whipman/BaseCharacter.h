// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "BaseCharacter.generated.h"

/**
 * 
 */

class USkeletalMesh;

UCLASS()
class WHIPMAN_API ABaseCharacter : public ABasePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseCharacter();

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	USkeletalMeshComponent *SkeletalMesh;
	
};
