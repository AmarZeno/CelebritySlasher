// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "LookAtAndMove.h"


// Sets default values for this component's properties
ULookAtAndMove::ULookAtAndMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULookAtAndMove::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("LookAt and move reporting!"));

	Enemy = GetOwner();
}


// Called every frame
void ULookAtAndMove::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void ULookAtAndMove::LookAtCamera()
{
	/*FRotator *EnemyRot = FRotationMatrix::MakeFromX(Enemy->GetActorLocation() - actorLoc).Rotator();
	Enemy->SetActorRotation(EnemyRot);*/
}
