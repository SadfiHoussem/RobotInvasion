// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "ShooterMenuItemWidgetStyle.h"


FShooterMenuItemStyle::FShooterMenuItemStyle()
{
}

FShooterMenuItemStyle::~FShooterMenuItemStyle()
{
}

const FName FShooterMenuItemStyle::TypeName(TEXT("FShooterMenuItemStyle"));

const FShooterMenuItemStyle& FShooterMenuItemStyle::GetDefault()
{
	static FShooterMenuItemStyle Default;
	return Default;
}

void FShooterMenuItemStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	OutBrushes.Add(&BackgroundBrush);
	OutBrushes.Add(&LeftArrowImage);
	OutBrushes.Add(&RightArrowImage);
}


UShooterMenuItemWidgetStyle::UShooterMenuItemWidgetStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}