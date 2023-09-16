// Created by Spring2022_Capstone team

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseUIManager.generated.h"

class UUserWidget;

UCLASS()
class WHIPMAN_API ABaseUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseUIManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> RootWidget;

	// Additional WidgetBluePrints to be created and added to viewport.
	UPROPERTY(EditAnywhere, Category = "Widget")
	TArray<TSubclassOf<UUserWidget>> AdditionalWidgets;
	
	UFUNCTION()
	void DisplayWidget();
	UFUNCTION()
	void DismissWidget();

private:
	UUserWidget *_RootWidget;

};
