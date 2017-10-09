// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGameModeBase.h"
#include "Engine/CollisionProfile.h"
#include "MyWall.generated.h"


DECLARE_DELEGATE(TurnOnGreenLight);

UCLASS()
class MYPROJECT_API AMyWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWall();

	TurnOnGreenLight TurnOnGreenDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ObstacleBox;

	UFUNCTION()
	void WallHide();

	UFUNCTION()
	void WallShow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
