// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RobotZombieGameMode.h"
#include "RobotZombie_Survive.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTZOMBIE_API ARobotZombie_Survive : public ARobotZombieGameMode
{
	GENERATED_UCLASS_BODY()

	/** setup team changes at player login */
	void PostLogin(APlayerController* NewPlayer) override;

	/** initialize replicated game data */
	virtual void InitGameState() override;

	/** can players damage each other? */
	virtual bool CanDealDamage(AShooterPlayerState* DamageInstigator, AShooterPlayerState* DamagedPlayer) const override;

	/** select best spawn point for player */
	//virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	/** update remaining time */
	virtual void DefaultTimer() override;

	/** Time Between Round*/
	int32 RemainingTimeBetweenRounds;

	/** Time displaying Round*/
	int32 RemainingTimeRoundHUD;

	/** number of round */
	int32 NumRound;

protected:

	/** number of teams */
	int32 NumTeams;

	/** best team */
	int32 WinnerTeam;

	/** number of bots per round */
	int32 NumBotPerRound;

	/** number of bots spawned and killed */
	int32 NumBotSpawnedAndKilled;

	/** pick team with least players in or random when it's equal */
	//int32 ChooseTeam(AShooterPlayerState* ForPlayerState) const;

	/** check who won */
	virtual void DetermineMatchWinner() override;

	/** check if PlayerState is a winner */
	virtual bool IsWinner(AShooterPlayerState* PlayerState) const override;

	/** check team constraints */
	virtual bool IsSpawnpointAllowed(APlayerStart* SpawnPoint, AController* Player) const;

	/** initialization for bot after spawning */
	virtual void InitBot(AShooterAIController* AIC, int32 BotNum) override;
	
	
};
