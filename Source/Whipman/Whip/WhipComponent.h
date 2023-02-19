// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EWhipState.h"
#include "WhipComponent.generated.h"

class AWhipTip;
class AWhipCable;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WHIPMAN_API UWhipComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWhipComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsInUse();
	void FireWhip(FVector TargetLocation);
	void CancelWhip();
	FVector GetStartLocation();

private:
	UPROPERTY(EditAnywhere, Category = "Whip")
	FVector WhipOffset;
	UPROPERTY(EditAnywhere, Category = "Whip")
	float FireSpeed = 5000;
	UPROPERTY(EditAnywhere, Category = "Whip")
	float WhipTimer = 0.25f;
	UPROPERTY(EditAnywhere, Category = "Whip")
	TEnumAsByte<EWhipState> WhipState;

	UPROPERTY(EditAnywhere, Category = "Whip")
	AWhipTip *WhipTip = nullptr;
	UPROPERTY(EditAnywhere, Category = "Whip")
	AWhipCable *WhipCable = nullptr;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
