// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TrackPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UTrackPlayer : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UTrackPlayer();

	UPROPERTY(EditAnywhere)

	FBlackboardKeySelector PlayerKey;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
