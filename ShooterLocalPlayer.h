// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/LocalPlayer.h"
#include "ShooterPersistentUser.h"
#include "ShooterLocalPlayer.generated.h"

/**
 * 
 */
UCLASS( transient)
class ROBOTZOMBIE_API UShooterLocalPlayer : public ULocalPlayer
{
	GENERATED_UCLASS_BODY()
	
public:

	virtual void SetControllerId(int32 NewControllerId) override;

	virtual FString GetNickname() const;

	class UShooterPersistentUser* GetPersistentUser() const;

	/** Initializes the PersistentUser */
	void LoadPersistentUser();

private:
	/** Persistent user data stored between sessions (i.e. the user's savegame) */
	UPROPERTY()
	class UShooterPersistentUser* PersistentUser;
	
	
};
