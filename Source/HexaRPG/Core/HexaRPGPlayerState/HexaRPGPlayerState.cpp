// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/HexaRPGPlayerState/HexaRPGPlayerState.h"

AHexaRPGPlayerState::AHexaRPGPlayerState()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(FName("HealthComponent"));
}