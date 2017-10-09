// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(InitStopLight);
DECLARE_DELEGATE(TurnOnOrangeLight);
DECLARE_DELEGATE(TurnOnGreenLight);

DECLARE_EVENT(AMyGameModeBase, ReinitStopLightEvent);
DECLARE_EVENT(AMyGameModeBase, RedLightEnabledEvent);


UCLASS(BlueprintType, Blueprintable)
class MYPROJECT_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMyGameModeBase();

	InitStopLight InitStopLightDelegate;
	TurnOnOrangeLight TurnOnOrangeDelegate;
	TurnOnGreenLight TurnOnGreenDelegate;

	
	ReinitStopLightEvent OnReinitStopLight;
	RedLightEnabledEvent OnRedLightEnabled;
	
	/*
	Blueprint events
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnRedLightTurnOn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnYellowLightTurnOn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnGreenLightTurnOn();

	/*
	Functions that changes lights
	*/
	UFUNCTION(BlueprintCallable)
	void RedLightInit();

	UFUNCTION()
	void InitYellowLight();

	UFUNCTION()
	void InitGreenLight();
};
