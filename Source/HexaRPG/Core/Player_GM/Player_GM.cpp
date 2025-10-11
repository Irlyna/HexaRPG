// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Player_GM/Player_GM.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void APlayer_GM::GameOver()
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
