// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotZombie.h"
#include "ShooterMenuWidgetStyle.h"


FShooterMenuStyle::FShooterMenuStyle()
{
}

FShooterMenuStyle::~FShooterMenuStyle()
{
}

const FName FShooterMenuStyle::TypeName(TEXT("FShooterMenuStyle"));

const FShooterMenuStyle& FShooterMenuStyle::GetDefault()
{
	static FShooterMenuStyle Default;
	return Default;
}

void FShooterMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	OutBrushes.Add(&HeaderBackgroundBrush);
	OutBrushes.Add(&LeftBackgroundBrush);
	OutBrushes.Add(&RightBackgroundBrush);
}


UShooterMenuWidgetStyle::UShooterMenuWidgetStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


