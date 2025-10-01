// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

// Event declaration exposed to Blueprints
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedEvent, float, NewCurrentHealth, float, DefaultMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HEXARPG_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnDeathEvent OnDeathEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedEvent OnHealthChangedEvent;
	
	UPROPERTY()
	float MaxHealth = 100.0f;

	UPROPERTY()
	float CurrentHealth = 100.0f;

	UPROPERTY()
	bool IsDead = false;

	UFUNCTION()
	void TakeDamage(float DamageAmount);

	UFUNCTION()
	void Heal(float HealAmount);

	UFUNCTION()
	bool Die();
};
