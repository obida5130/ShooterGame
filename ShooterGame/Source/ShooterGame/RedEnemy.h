// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "RedEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API ARedEnemy : public AEnemy
{
	GENERATED_BODY()

public:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
