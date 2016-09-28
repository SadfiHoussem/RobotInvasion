// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "ShooterMenuSoundsWidgetStyle.h"


FShooterMenuSoundsStyle::FShooterMenuSoundsStyle()
{
}

FShooterMenuSoundsStyle::~FShooterMenuSoundsStyle()
{
}

const FName FShooterMenuSoundsStyle::TypeName(TEXT("FShooterMenuSoundsStyle"));

const FShooterMenuSoundsStyle& FShooterMenuSoundsStyle::GetDefault()
{
	static FShooterMenuSoundsStyle Default;
	return Default;
}

void FShooterMenuSoundsStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}


UShooterMenuSoundsWidgetStyle::UShooterMenuSoundsWidgetStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


