// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SHOOTERGAME_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(EditAnywhere)
		class UBoxComponent* SpawnArea;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ARedEnemy> RedEnemyClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABlueEnemy> BlueEnemyClass;

	UPROPERTY(EditAnywhere)
		float Difficulty;

	UPROPERTY(EditAnywhere)
		float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere)
		float SpawnDelayRangeHigh;

	UPROPERTY(EditAnywhere)
		float SpawnDelay;

	FTimerHandle TimerHandle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnEnemy();
};
