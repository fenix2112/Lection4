// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"



AMyGameModeBase::AMyGameModeBase() {

	InitStopLightDelegate.BindUObject(this, &AMyGameModeBase::RedLightInit);
}

/************************************************************************/
/* turn on red light                                                    */
/************************************************************************/
void AMyGameModeBase::RedLightInit()
{
	// event in BP
	OnRedLightTurnOn();
	OnRedLightEnabled.Broadcast();

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyGameModeBase::InitYellowLight, 3);
}

/************************************************************************/
/* turn on yellow light                                                */
/************************************************************************/
void AMyGameModeBase::InitYellowLight()
{
	// event in BP
	OnYellowLightTurnOn();

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyGameModeBase::InitGreenLight, 3);

	TurnOnOrangeDelegate.ExecuteIfBound();
}

/************************************************************************/
/* turn on green light                                                                     */
/************************************************************************/
void AMyGameModeBase::InitGreenLight()
{
	TurnOnGreenDelegate.ExecuteIfBound();

	// event in BP
	OnGreenLightTurnOn();
	OnReinitStopLight.Broadcast();
}
