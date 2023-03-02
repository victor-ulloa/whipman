// Fill out your copyright notice in the Description page of Project Settings.


#include "WhipTip.h"
#include "Whipman/BaseCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AWhipTip::AWhipTip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("TipMesh"));
	RootComponent = SphereCollider;
	SphereCollider->SetSimulatePhysics(false);
    SphereCollider->SetNotifyRigidBodyCollision(true);
	SphereCollider->SetWorldScale3D(FVector(2, 2, 2));

	SphereCollider->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void AWhipTip::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovementComp->SetVelocityInLocalSpace(FireVelocity);
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AWhipTip::OnOverlapBegin);
}

// Called every frame
void AWhipTip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Display, TEXT("%f %f %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
}


void AWhipTip::OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	// SweepResult.GetActor()->GetName()
	if (SweepResult.GetActor()->IsA(ABaseCharacter::StaticClass())) 
	{
		UE_LOG(LogTemp, Display, TEXT("PLAYER"));
		return;
	}
	UE_LOG(LogTemp, Display, TEXT("HERE"));
}