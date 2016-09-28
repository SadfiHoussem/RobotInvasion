// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindPickup.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTZOMBIE_API UBTTask_FindPickup : public UBTTask_BlackboardBase
{
	GENERATED_UCLASS_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
