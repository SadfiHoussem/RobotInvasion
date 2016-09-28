// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "ShooterCharacterMovement.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTZOMBIE_API UShooterCharacterMovement : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()
	
	virtual float GetMaxSpeed() const override;
	
	
};
