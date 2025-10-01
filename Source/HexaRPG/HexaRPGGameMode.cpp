// Copyright Epic Games, Inc. All Rights Reserved.

#include "HexaRPGGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AHexaRPGGameMode::AHexaRPGGameMode()
{
	// stub
}

void AHexaRPGGameMode::GameOver()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController && GameOverWidgetClass)
	{
		if (GameOverSound)
		{
			UGameplayStatics::SpawnSound2D(this, GameOverSound);
		}

		UUserWidget* GameOverWidget = CreateWidget<UUserWidget>(
			PlayerController,
			GameOverWidgetClass
		);

		if (GameOverWidget)
		{
			GameOverWidget->AddToViewport();

			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(GameOverWidget->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			PlayerController->SetInputMode(InputMode);
			PlayerController->bShowMouseCursor = true;
		}
	}
}
