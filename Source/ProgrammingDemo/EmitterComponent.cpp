// Fill out your copyright notice in the Description page of Project Settings.

#include "EmitterComponent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UEmitterComponent::UEmitterComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	ProjectileClass = AProjectile::StaticClass();
}


// Called when the game starts
void UEmitterComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UEmitterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UEmitterComponent::Fire()
{
	SpawnProjectile();
}

void UEmitterComponent::SpawnProjectile()
{
	AActor* owner = GetOwner();

	FVector location = GetComponentLocation();
	FRotator rotation = GetComponentRotation();
	FActorSpawnParameters spawnParameters;
	spawnParameters.Owner = owner;
	spawnParameters.Instigator = owner->GetInstigator();

	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, location, rotation);
}

