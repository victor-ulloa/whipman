// Created by Spring2022_Capstone team

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

class UPanelWidget;
class UImage;
class UTextBlock;
class APlayerCharacter;

UCLASS(Abstract)
class WHIPMAN_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry &MyGeometry, float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere)
	APlayerCharacter* PlayerCharacter;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UPanelWidget *RootPanel;
	// Crosshair
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UImage *Crosshair;
	
private:
	
	UFUNCTION()
	void OnHealthChanged(float HealthValue);

	int MaxLives;
};
