// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "SoundNodeLocalPlayer.h"
#include "SoundDefinitions.h"

#define LOCTEXT_NAMESPACE "SoundNodeLocalPlayer"


USoundNodeLocalPlayer::USoundNodeLocalPlayer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void USoundNodeLocalPlayer::ParseNodes(FAudioDevice* AudioDevice, const UPTRINT NodeWaveInstanceHash, FActiveSound& ActiveSound, const FSoundParseParameters& ParseParams, TArray<FWaveInstance*>& WaveInstances)
{
	// The accesses to the Pawn will be unsafe once we thread audio, deal with this at that point
	check(IsInGameThread());

	UAudioComponent* AudioComponent = ActiveSound.GetAudioComponent();
	AActor* SoundOwner = AudioComponent ? AudioComponent->GetOwner() : NULL;
	APlayerController* PCOwner = Cast<APlayerController>(SoundOwner);
	APawn* PawnOwner = (PCOwner ? PCOwner->GetPawn() : Cast<APawn>(SoundOwner));

	const bool bLocallyControlled = PawnOwner && PawnOwner->IsLocallyControlled() && Cast<APlayerController>(PawnOwner->Controller);
	const int32 PlayIndex = bLocallyControlled ? 0 : 1;

	if (PlayIndex < ChildNodes.Num() && ChildNodes[PlayIndex])
	{
		ChildNodes[PlayIndex]->ParseNodes(AudioDevice, GetNodeWaveInstanceHash(NodeWaveInstanceHash, ChildNodes[PlayIndex], PlayIndex), ActiveSound, ParseParams, WaveInstances);
	}
}

#if WITH_EDITOR
FText USoundNodeLocalPlayer::GetInputPinName(int32 PinIndex) const
{
	return (PinIndex == 0) ? LOCTEXT("LocalPlayerLabel", "Local") : LOCTEXT("RemotePlayerLabel", "Remote");
}
#endif

int32 USoundNodeLocalPlayer::GetMaxChildNodes() const
{
	return 2;
}

int32 USoundNodeLocalPlayer::GetMinChildNodes() const
{
	return 2;
}

#undef LOCTEXT_NAMESPACE

