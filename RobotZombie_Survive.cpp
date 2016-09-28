// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "RobotZombie_Survive.h"
#include "ShooterGameState.h"
#include "ShooterTeamStart.h"
#include "ShooterAIController.h"
#include "RobotZombieCharacter.h"
#include "ShooterPlayerState.h"
#include "ShooterAIController.h"
#include "ShooterHUD.h"
#include "ShooterTeamStart.h"
#include "ShooterGameInstance.h"
#include "Engine.h"



ARobotZombie_Survive::ARobotZombie_Survive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NumRound = 1;
	NumTeams = 2;
	//NumBotPerRound = 6;
	//NumBotSpawnedAndKilled = 0;
	NumBots = 5; // NumBotPerRound
	RemainingTimeBetweenRounds = 0;
	RemainingTimeRoundHUD = 0;
	bDelayedStart = true;
}

void ARobotZombie_Survive::PostLogin(APlayerController* NewPlayer)
{
	// Place player on a team before Super (VoIP team based init, findplayerstart, etc)
	AShooterPlayerState* NewPlayerState = CastChecked<AShooterPlayerState>(NewPlayer->PlayerState);
	NewPlayerState->SetTeamNum(1);

	Super::PostLogin(NewPlayer);
}

void ARobotZombie_Survive::InitGameState()
{
	Super::InitGameState();

	AShooterGameState* const MyGameState = Cast<AShooterGameState>(GameState);
	if (MyGameState)
	{
		MyGameState->NumTeams = NumTeams;
	}
}

bool ARobotZombie_Survive::CanDealDamage(AShooterPlayerState* DamageInstigator, class AShooterPlayerState* DamagedPlayer) const
{
	return DamageInstigator && DamagedPlayer && (DamagedPlayer == DamageInstigator || DamagedPlayer->GetTeamNum() != DamageInstigator->GetTeamNum());
}

void ARobotZombie_Survive::DefaultTimer()
{
	AShooterGameState* const MyGameState = Cast<AShooterGameState>(GameState);
	if (MyGameState && MyGameState->RemainingTime > 0 && !MyGameState->bTimerPaused)
	{
		if (RemainingTimeRoundHUD > 0) {
			RemainingTimeRoundHUD--;
			//GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Green, GetMatchState().ToString());
		}
		if (RemainingTimeBetweenRounds > 0) {
			RemainingTimeBetweenRounds--;
			if (RemainingTimeBetweenRounds == 0) {
				GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, TEXT("Round"));
				GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, FString::FromInt(NumRound));
				MyGameState->RemainingTime = RoundTime;
				RemainingTimeRoundHUD = 2;
				NumBots = NumRound * 5;
				CreateBotControllers();
				StartBots();
			}
		}
	}
	Super::DefaultTimer();
}


void ARobotZombie_Survive::DetermineMatchWinner()
{
	/*AShooterGameState const* const MyGameState = Cast<AShooterGameState>(GameState);
	int32 BestScore = MAX_uint32;
	int32 BestTeam = -1;
	int32 NumBestTeams = 1;

	for (int32 i = 0; i < MyGameState->TeamScores.Num(); i++)
	{
		const int32 TeamScore = MyGameState->TeamScores[i];
		if (BestScore < TeamScore)
		{
			BestScore = TeamScore;
			BestTeam = i;
			NumBestTeams = 1;
		}
		else if (BestScore == TeamScore)
		{
			NumBestTeams++;
		}
	}

	WinnerTeam = (NumBestTeams == 1) ? BestTeam : NumTeams;*/
}

bool ARobotZombie_Survive::IsWinner(AShooterPlayerState* PlayerState) const
{
	return PlayerState && !PlayerState->IsQuitter() && PlayerState->GetTeamNum() == WinnerTeam;
}

bool ARobotZombie_Survive::IsSpawnpointAllowed(APlayerStart* SpawnPoint, AController* Player) const
{
	if (Player)
	{
		AShooterTeamStart* TeamStart = Cast<AShooterTeamStart>(SpawnPoint);
		AShooterPlayerState* PlayerState = Cast<AShooterPlayerState>(Player->PlayerState);

		if (PlayerState && TeamStart && TeamStart->SpawnTeam != PlayerState->GetTeamNum())
		{
			return false;
		}
	}

	return Super::IsSpawnpointAllowed(SpawnPoint, Player);
}

void ARobotZombie_Survive::InitBot(AShooterAIController* AIC, int32 BotNum)
{
	AShooterPlayerState* BotPlayerState = CastChecked<AShooterPlayerState>(AIC->PlayerState);
	BotPlayerState->SetTeamNum(2);

	Super::InitBot(AIC, BotNum);
}