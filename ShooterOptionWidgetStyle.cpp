// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "ShooterOptionWidgetStyle.h"


FShooterOptionsStyle::FShooterOptionsStyle()
{
}

FShooterOptionsStyle::~FShooterOptionsStyle()
{
}

const FName FShooterOptionsStyle::TypeName(TEXT("FShooterOptionsStyle"));

const FShooterOptionsStyle& FShooterOptionsStyle::GetDefault()
{
	static FShooterOptionsStyle Default;
	return Default;
}

void FShooterOptionsStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
}


UShooterOptionsWidgetStyle::UShooterOptionsWidgetStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

