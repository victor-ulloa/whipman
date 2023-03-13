// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseDeathBox.h"
#include "Components/BoxComponent.h"
#include "Whipman/PlayerCharacter.h"

ABaseDeathBox::ABaseDeathBox()
{
    BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;
}

void ABaseDeathBox::BeginPlay()
{
    Super::BeginPlay();
    BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ABaseDeathBox::OnDeathBoxBeginOverlap);
    
}

void ABaseDeathBox::OnDeathBoxBeginOverlap(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if (APlayerCharacter* playerCharacter = Cast<APlayerCharacter>(otherActor))
	{
		playerCharacter->OnPlayerHit();
	}
}
