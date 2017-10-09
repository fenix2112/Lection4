// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGameModeBase.h"
#include "SpawnObstacleActor.h"
#include "MyWall.h"
#include "GameFramework/GameModeBase.h"
#include "Components/BoxComponent.h"
#include "MyTriggerBox.generated.h"

DECLARE_DELEGATE(TurnOnRedLight);
DECLARE_DELEGATE(TurnOnOrangeLight);
DECLARE_DELEGATE(TurnOnGreenLight);

UCLASS(BlueprintType, Blueprintable)
class MYPROJECT_API AMyTriggerBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerBox();

	TurnOnRedLight TurnOnRedDelegate;
	TurnOnOrangeLight TurnOnOrange;
	TurnOnGreenLight TurnOnGreen;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* TriggerZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMyWall* MyWallObstacle;

	UFUNCTION()
	void NotifyActorBeginOverlap(AActor* OtherActor)override;

	UFUNCTION()
	void InitStopLight();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
