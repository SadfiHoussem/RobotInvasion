// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindPOintNearEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTZOMBIE_API UBTTask_FindPOintNearEnemy : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
