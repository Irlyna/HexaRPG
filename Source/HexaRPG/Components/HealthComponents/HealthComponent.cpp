// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponents/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UHealthComponent::TakeDamage(float DamageAmount)
{
	if (IsDead)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0, MaxHealth);

	if (CurrentHealth == 0)
	{
		Die();
	}

	// Call the Event
	OnHealthChangedEvent.Broadcast(CurrentHealth, MaxHealth);
}

void UHealthComponent::Heal(float HealAmount)
{
	if (IsDead)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0, MaxHealth);

	// Call the Event
	OnHealthChangedEvent.Broadcast(CurrentHealth, MaxHealth);
}


bool UHealthComponent::Die()
{
	IsDead = true;

	// Call the Event
	OnDeathEvent.Broadcast();

	return IsDead;
}

