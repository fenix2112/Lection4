// Fill out your copyright notice in the Description page of Project Settings.

#include "MyWall.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMyWall::AMyWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObstacleBox = CreateDefaultSubobject<UStaticMeshComponent>("Obstacle");
	ConstructorHelpers::FObjectFinder<UStaticMesh> BoxVisualAsset(TEXT("StaticMesh'/Game/Geometry/Cube.Cube'"));
	if (BoxVisualAsset.Object)
	{
		ObstacleBox->SetStaticMesh(BoxVisualAsset.Object);
	}

	RootComponent = ObstacleBox;

	SetActorEnableCollision(false);
	RootComponent->bVisible = false;

}

// Called when the game starts or when spawned
void AMyWall::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* StartGameMode = GetWorld()->GetAuthGameMode();
	AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(StartGameMode);
	if (MyGameMode)
	{
		MyGameMode->OnRedLightEnabled.AddUObject(this, &AMyWall::WallShow);
		MyGameMode->OnReinitStopLight.AddUObject(this, &AMyWall::WallHide);
	}

	WallHide();
}

// Called every frame
void AMyWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyWall::WallHide()
{

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, FString("Hide wall"));

	SetActorEnableCollision(false);
	RootComponent->SetVisibility(false, true);
	
}

void AMyWall::WallShow()
{
	RootComponent->SetVisibility(true, true);
	SetActorEnableCollision(true);
}