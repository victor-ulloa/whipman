// Created by Spring2022_Capstone team

#include "HUDWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Whipman/PlayerCharacter.h"

void UHUDWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));

    if (PlayerCharacter)
    {
        PlayerCharacter->OnHealthChangedDelegate.BindUObject(this, &UHUDWidget::OnHealthChanged);
        MaxLives = PlayerCharacter->GetMaxLives();
    }
	
}

void UHUDWidget::NativeTick(const FGeometry &MyGeometry, float DeltaTime)
{
    Super::NativeTick(MyGeometry, DeltaTime);
}

void UHUDWidget::OnHealthChanged(float HealthValue)
{
    
}
