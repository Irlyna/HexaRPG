// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HealthComponents/HealthComponent.h"
#include "GameFramework/PlayerState.h"
#include "HexaRPGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class HEXARPG_API AHexaRPGPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AHexaRPGPlayerState();
	
	UPROPERTY()
	UHealthComponent* HealthComponent;
};
