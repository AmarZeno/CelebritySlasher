// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "MoveTowardsPlayer.h"


// Sets default values for this component's properties
UMoveTowardsPlayer::UMoveTowardsPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveTowardsPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Move Towards reporting!"));

	Enemy = GetOwner();
}


// Called every frame
void UMoveTowardsPlayer::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	MoveTowardsPlayer();
}

void UMoveTowardsPlayer::MoveTowardsPlayer() {
	FVector LocationDifference = Enemy->GetActorLocation() - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	LocationDifference.Normalize();

	Enemy->SetActorLocation(FVector(Enemy->GetActorLocation().X - LocationDifference.X, Enemy->GetActorLocation().Y, Enemy->GetActorLocation().Z));
}

