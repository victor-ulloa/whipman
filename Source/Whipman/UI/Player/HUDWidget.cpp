// Created by Spring2022_Capstone team

#include "HUDWidget.h"
#include "Components/Image.h"
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
    }
	
}

void UHUDWidget::NativeTick(const FGeometry &MyGeometry, float DeltaTime)
{
    Super::NativeTick(MyGeometry, DeltaTime);
}

void UHUDWidget::OnHealthChanged(float HealthValue)
{
    Heart_1->SetVisibility((HealthValue >= 1) ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    Heart_2->SetVisibility((HealthValue >= 2) ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    Heart_3->SetVisibility((HealthValue >= 3) ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
