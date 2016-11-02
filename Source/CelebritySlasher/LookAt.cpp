// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "LookAt.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values for this component's properties
ULookAt::ULookAt()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULookAt::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("LookAt reporting!"));

	Enemy = GetOwner();
}


// Called every frame
void ULookAt::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	LookAtCamera();
}

void ULookAt::LookAtCamera()
{

	// Solution 1
	//FVector LocationDifference = Enemy->GetActorLocation() - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//LocationDifference.Normalize();

	//FRotator EnemyRot = FRotationMatrix::MakeFromX(LocationDifference).Rotator();
	////Enemy->SetActorRotation(EnemyRot);

	//Enemy->SetActorRelativeRotation(EnemyRot);

	//print(FString::Printf(TEXT("Rotation %f , %f, %f"), EnemyRot.Pitch ,EnemyRot.Yaw, EnemyRot.Roll));



	// Solution 2
	// Look toward focus
	FVector FocalPoint = Enemy->GetActorLocation();
	if (!FocalPoint.IsZero())
	{
		FVector Direction = FocalPoint - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		FRotator NewControlRotation = Direction.Rotation();

		// Hack adding 90 to correct the offset
		NewControlRotation.Yaw = FRotator::ClampAxis(NewControlRotation.Yaw + 90);

		Enemy->SetActorRelativeRotation(NewControlRotation);

	}
}

