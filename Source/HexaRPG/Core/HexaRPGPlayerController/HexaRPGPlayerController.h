// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/PlayerHUD/PlayerHUD.h"
#include "HexaRPGPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;
class UInputAction;
struct FInputActionValue;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class AHexaRPGPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;
	
	UPROPERTY(EditAnywhere, Category="Widget|HUD")
	TSubclassOf<UPlayerHUD> HUDClass;

	UPROPERTY()
	UPlayerHUD* HUDRef;

	/** Pointer to the mobile controls widget */
	TObjectPtr<UUserWidget> MobileControlsWidget;
	
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	// virtual void OnPossess(APawn* InPawn) override;

public:
	UFUNCTION()
	void HandleDeath();

	UFUNCTION()
	void HandleHealthChanged(float CurrentHealth, float MaxHealth);
};
