// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "BlueEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API ABlueEnemy : public AEnemy
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
