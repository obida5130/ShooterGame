// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UUWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;

public:
	void UpdateHealthPercent(float HealthPercent);
};
