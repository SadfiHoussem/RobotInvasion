// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController_Menu.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTZOMBIE_API AShooterPlayerController_Menu : public APlayerController
{
	GENERATED_UCLASS_BODY()

		/** After game is initialized */
		virtual void PostInitializeComponents() override;
	
};
