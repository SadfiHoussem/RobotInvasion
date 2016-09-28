// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "ShooterHUD.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS(config=game)
class ROBOTZOMBIE_API AShooterPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()
	
public:	
	/** sets spectator location and rotation */
	UFUNCTION(reliable, client)
	void ClientSetSpectatorCamera(FVector CameraLocation, FRotator CameraRotation);

	/** notify player about started match */
	UFUNCTION(reliable, client)
	void ClientGameStarted();

	/** set infinite ammo cheat */
	void SetInfiniteAmmo(bool bEnable);

	/** set infinite clip cheat */
	void SetInfiniteClip(bool bEnable);

	/** set health regen cheat */
	void SetHealthRegen(bool bEnable);


	/** toggle InGameMenu handler */
	//void OnToggleInGameMenu();

	/** Show the in-game menu if it's not already showing */
	//void ShowInGameMenu();

	/** Hides scoreboard if currently diplayed */
	//void OnConditionalCloseScoreboard();

	/** Toggles scoreboard */
	//void OnToggleScoreboard();

	/** shows scoreboard */
	//void OnShowScoreboard();

	/** hides scoreboard */
	//void OnHideScoreboard();

	/** get infinite ammo cheat */
	bool HasInfiniteAmmo() const;

	/** get infinite clip cheat */
	bool HasInfiniteClip() const;

	/** get health regen cheat */
	bool HasHealthRegen() const;

	/** get gode mode cheat */
	//bool HasGodMode() const;

	/** check if gameplay related actions (movement, weapon usage, etc) are allowed right now */
	bool IsGameInputAllowed() const;

	/** Returns a pointer to the shooter game hud. May return NULL. */
	AShooterHUD * GetShooterHUD() const;

	/** Returns the persistent user record associated with this player, or null if there is't one. */
	class UShooterPersistentUser* GetPersistentUser() const;

	/** is game menu currently active? */
	//bool IsGameMenuVisible() const;

	/** Associate a new UPlayer with this PlayerController. */
	virtual void SetPlayer(UPlayer* Player);

	/** Informs that player fragged someone */
	void OnKill();


protected:

	/** infinite ammo cheat */
	UPROPERTY(Transient, Replicated)
		uint8 bInfiniteAmmo : 1;

	/** infinite clip cheat */
	UPROPERTY(Transient, Replicated)
		uint8 bInfiniteClip : 1;

	/** health regen cheat */
	UPROPERTY(Transient, Replicated)
		uint8 bHealthRegen : 1;

	/** god mode cheat */
	UPROPERTY(Transient, Replicated)
		uint8 bGodMode : 1;

	/** if set, gameplay related actions (movement, weapn usage, etc) are allowed */
	uint8 bAllowGameActions : 1;

	/** true for the first frame after the game has ended */
	uint8 bGameEndedFrame : 1;

	/** stores pawn location at last player death, used where player scores a kill after they died **/
	FVector LastDeathLocation;

	/** shooter in-game menu */
	TSharedPtr<class FShooterIngameMenu> ShooterIngameMenu;

	/** try to find spot for death cam */
	bool FindDeathCameraSpot(FVector& CameraLocation, FRotator& CameraRotation);

	//Begin AActor interface

	/** after all game elements are created */
	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
	//End AActor interface

	//Begin AController interface

	/** update camera when pawn dies */
	virtual void PawnPendingDestroy(APawn* P) override;

	//End AController interface

	// Begin APlayerController interface

	/** sets up input */
	virtual void SetupInputComponent() override;

	/**
	* Called from game info upon end of the game, used to transition to proper state.
	*
	* @param EndGameFocus Actor to set as the view target on end game
	* @param bIsWinner true if this controller is on winning team
	*/
	//virtual void GameHasEnded(class AActor* EndGameFocus = NULL, bool bIsWinner = false) override;

	/** Causes the player to commit suicide */
	UFUNCTION(exec)
	virtual void Suicide();
	
	/** Notifies the server that the client has suicided */
	UFUNCTION(reliable, server, WithValidation)
		void ServerSuicide();

	// End APlayerController interface

	FName	ServerSayString;

	// Timer used for updating friends in the player tick.
	float ShooterFriendUpdateTimer;

	// For tracking whether or not to send the end event
	bool bHasSentStartEvents;

private:

	/** Handle for efficient management of ClientStartOnlineGame timer */
	FTimerHandle TimerHandle_ClientStartOnlineGame;
	
	
};
