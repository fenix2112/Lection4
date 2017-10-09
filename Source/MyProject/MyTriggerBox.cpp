// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerBox.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	RootComponent = TriggerZone;
}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// detects if the car entered the trigger box
void AMyTriggerBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AMyTriggerBox::InitStopLight();
}

void AMyTriggerBox::InitStopLight()
{
	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->InitStopLightDelegate.ExecuteIfBound();
	}
}

