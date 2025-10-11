// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev/Trap.h"

#include "Interfaces/IDamageable.h"

void ATrap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATrap::OnOverlapBegin);
}

void ATrap::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Trap overlap triggered with: %s"), *OtherActor->GetName());
	if (!OtherActor || OtherActor == this) return;

	if (OtherActor->Implements<UDamageableInterface>())
	{
		IDamageableInterface::Execute_ApplyDamage(OtherActor, DamageAmount);
	}
}
