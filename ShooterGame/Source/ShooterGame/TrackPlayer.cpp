// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


UTrackPlayer::UTrackPlayer()
{
	NodeName = "Find PlayerTask";
}

EBTNodeResult::Type UTrackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		auto Blackboard = OwnerComp.GetBlackboardComponent();
		Blackboard->SetValueAsObject(PlayerKey.SelectedKeyName, Player);

		return EBTNodeResult::Succeeded;
	}


	return EBTNodeResult::Type();
}
