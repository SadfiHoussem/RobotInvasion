// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "ShooterBot.h"
#include "ShooterAIController.h"

AShooterBot::AShooterBot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIControllerClass = AShooterAIController::StaticClass();

	bIsThirdPerson = true;

	UpdatePawnMeshes();
	
	bUseControllerRotationYaw = true;
}

bool AShooterBot::IsFirstPerson() const
{
	return false;
}

void AShooterBot::FaceRotation(FRotator NewRotation, float DeltaTime)
{
	FRotator CurrentRotation = FMath::RInterpTo(GetActorRotation(), NewRotation, DeltaTime, 8.0f);

	Super::FaceRotation(CurrentRotation, DeltaTime);
}




