// Fill out your copyright notice in the Description page of Project Settings.


#include "WhipTip.h"
#include "Components/SphereComponent.h"
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
	SphereCollider->SetWorldScale3D(FVector(0.2, 0.2, 0.2));

	SphereCollider->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	SphereCollider->OnComponentHit.AddDynamic(this, &AWhipTip::OnCompHit);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void AWhipTip::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovementComp->SetVelocityInLocalSpace(FireVelocity);
}

// Called every frame
void AWhipTip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Display, TEXT("%f %f %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
}

void AWhipTip::OnCompHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	UE_LOG(LogTemp, Display, TEXT("GOT HIT"));
}
