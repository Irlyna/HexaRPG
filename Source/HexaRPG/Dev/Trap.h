// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Trap.generated.h"

/**
 * 
 */
UCLASS()
class HEXARPG_API ATrap : public ATriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Damage", meta=(ExposeOnSpawn=true))
	float DamageAmount = 25.0f;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
	
protected:
	virtual void BeginPlay() override;
};

