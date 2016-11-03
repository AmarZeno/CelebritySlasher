// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "MoveTowardsPlayer.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)
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

	Enemy = dynamic_cast<AEnemyCharacter*>(GetOwner());
	
	RandomActionValue = FMath::FRandRange(0.0f, 3.f);
}


// Called every frame
void UMoveTowardsPlayer::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	MoveTowardsPlayer();
	TriggerZombieAction();
}

void UMoveTowardsPlayer::MoveTowardsPlayer() {
	LocationDifference = Enemy->GetActorLocation() - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	LocationDifference.Normalize();

	//Enemy->SetActorRelativeLocation(FVector(Enemy->GetActorLocation().X - LocationDifference.X, Enemy->GetActorLocation().Y, Enemy->GetActorLocation().Z));

	// Add velocity to the enemy character
	Enemy->SpeedOfMovement = -0.5;
}

void UMoveTowardsPlayer::TriggerZombieAction()
{
	//print(FString::Printf(TEXT("Location Difference : %f"), Enemy->GetActorLocation().X - LocationDifference.X));
	// -4700 Magic number to stop the zombie near the character
	if (Enemy->GetActorLocation().X - LocationDifference.X < -4700) {
		// Stop moving
		Enemy->SpeedOfMovement = 0;

		if (RandomActionValue < 2) {
			Enemy->ZIsScreaming = true;
		}
		else {
			Enemy->ZIsAttacking = true;
		}
	}
}

