// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "ShooterGame_Mode.h"
#include "ShooterPlayerController_Menu.h"
#include "ShooterGameSession.h"



AShooterGame_Mode::AShooterGame_Mode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerControllerClass = AShooterPlayerController_Menu::StaticClass();
}

void AShooterGame_Mode::RestartPlayer(class AController* NewPlayer)
{
	// don't restart
}

/** Returns game session class to use */
TSubclassOf<AGameSession> AShooterGame_Mode::GetGameSessionClass() const
{
	return AShooterGameSession::StaticClass();
}

