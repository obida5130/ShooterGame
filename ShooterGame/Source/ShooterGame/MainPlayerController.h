// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RestartWidget.h"
#include "UWidget.h"
#include "MainPlayerController.generated.h"
/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class URestartWidget> BP_RestartWidget;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UWidget> BP_UWidget;
private:
	UPROPERTY()
		class URestartWidget* RestartWidget;
	UPROPERTY()
		class UWidget* UWidget;

protected:
	virtual void BeginPlay() override;

public:
	void ShowRestartWidget();

	void HideRestartWidget();

	void UpdateHealthPercent(float HealthPercent);
};
