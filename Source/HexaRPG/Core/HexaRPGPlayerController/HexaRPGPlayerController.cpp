// Copyright Epic Games, Inc. All Rights Reserved.


#include "HexaRPGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "HexaRPG.h"
#include "HexaRPGGameMode.h"
#include "Core/HexaRPGPlayerState/HexaRPGPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PlayerHUD/PlayerHUD.h"
#include "Widgets/Input/SVirtualJoystick.h"

void AHexaRPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);
		} else {

			UE_LOG(LogHexaRPG, Error, TEXT("Could not spawn mobile controls widget."));
		}
	}

	if (AHexaRPGPlayerState* const& HexaRPGPlayerState = Cast<AHexaRPGPlayerState>(GetPlayerState<AHexaRPGPlayerState>()))
	{
		if (HUDClass)
		{
			HUDRef = CreateWidget<UPlayerHUD>(this, HUDClass);
			HUDRef->AddToViewport();
			
			// First initialization
			HUDRef->UpdateHealthBar(
				HexaRPGPlayerState->HealthComponent->CurrentHealth,
				HexaRPGPlayerState->HealthComponent->MaxHealth
			);

			// Subscribe to the Events
			HexaRPGPlayerState->HealthComponent->OnDeathEvent.AddDynamic(this, &AHexaRPGPlayerController::HandleDeath);
			HexaRPGPlayerState->HealthComponent->OnHealthChangedEvent.AddDynamic(this, &AHexaRPGPlayerController::HandleHealthChanged);
		};
	}
}

void AHexaRPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

void AHexaRPGPlayerController::HandleDeath()
{
	if (GetWorld())
	{
		if (AHexaRPGGameMode* GameMode = Cast<AHexaRPGGameMode>(GetWorld()->GetAuthGameMode()))
		{
			GameMode->GameOver();
		}
	}
}

void AHexaRPGPlayerController::HandleHealthChanged(float const CurrentHealth, float const MaxHealth)
{
	if (HUDRef)
	{
		HUDRef->UpdateHealthBar(CurrentHealth, MaxHealth);
	}
}

