// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HexaRPGGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AHexaRPGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AHexaRPGGameMode();
};



