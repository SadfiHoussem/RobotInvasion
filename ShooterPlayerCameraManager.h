// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/PlayerCameraManager.h"
#include "ShooterPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTZOMBIE_API AShooterPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_UCLASS_BODY()
	
public:

	/** normal FOV */
	float NormalFOV;

	/** targeting FOV */
	float TargetingFOV;

	/** After updating camera, inform pawn to update 1p mesh to match camera's location&rotation */
	virtual void UpdateCamera(float DeltaTime) override;
	
	
};
