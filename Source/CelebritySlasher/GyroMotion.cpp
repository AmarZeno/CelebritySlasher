// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "GyroMotion.h"
#include <math.h>


#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)
#define OUT

// Sets default values for this component's properties
UGyroMotion::UGyroMotion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGyroMotion::BeginPlay()
{
	Super::BeginPlay();

	Player = GetOwner();

	GravityX = -0.2;

	GravityY = -0.2;

	UE_LOG(LogTemp, Warning, TEXT("GyroMotion reporting!"));

	Player->GetComponents(Comps);
	if (Comps.Num() > 0)
	{
		FoundComp = Comps[0];
		//do stuff with FoundComp

	
	}
}


// Called every frame
void UGyroMotion::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...

	FVector Tilt;
	FVector RotationRate;
	FVector Gravity;
	FVector Acceleration;

	GetWorld()->GetFirstPlayerController()->GetInputMotionState(
		OUT Tilt,
		OUT RotationRate,
		OUT Gravity,
		OUT Acceleration);

	//if ((GravityX - (roundf(Gravity.X * 10 * 10) / 10) > 2) || (GravityX - (roundf(Gravity.X * 10 * 10) / 10) < -2)) {
	//	GravityX = -2 + roundf(Gravity.X * 10 * 10) / 10;
	//}

	//if ((GravityY - (roundf(-Gravity.Y * 10 * 10) / 10) > 2) || (GravityY - (roundf(-Gravity.Y * 10 * 10) / 10) < -2)) {
	//	GravityY = -2 + roundf(-Gravity.Y * 10 * 10) / 10;
	//}

	/*if ((GravityX - (roundf(RotationRate.X * 10 * 10) / 10) > 0.2) || (GravityX - (roundf(RotationRate.X * 10 * 10) / 10) < -0.2)) {
		GravityX = -0.2 + roundf(RotationRate.X * 10 * 10) / 10;
	}

	if ((GravityY - (roundf(-RotationRate.Y * 10) / 10) > 0.2) || (GravityY - (roundf(-RotationRate.Y * 10) / 10) < -0.2)) {
		GravityY = -0.2 + roundf(-RotationRate.Y * 10) / 10;
	}*/

//	Player->SetActorRotation(FRotator(GravityX, GravityY, 0));

	//Player->AddActorLocalRotation(FRotator(-RotationRate.X, -RotationRate.Y, -RotationRate.Z));

	FoundComp->AddLocalRotation(FRotator(-RotationRate.X, -RotationRate.Y, 0));

	//Player->GetComponentsByClass(UCameraComponent);

	//Player->setactorlocalrotat AddActorLocalRotation(FRotator(Gravity.X, Gravity.Y, Gravity.Z));
	print(FString::Printf(TEXT("TiltRate X : %f / Y : %f / Z : %f"), Tilt.X, Tilt.Y, Tilt.Z));
	print(FString::Printf(TEXT("RotationRate X : %f / Y : %f / Z : %f"), RotationRate.X, RotationRate.Y, RotationRate.Z));
	print(FString::Printf(TEXT("Gravity X : %f / Y : %f / Z : %f"), Gravity.X, Gravity.Y, Gravity.Z));
	print(FString::Printf(TEXT("Acceleration X : %f / Y : %f / Z : %f"), Acceleration.X, Acceleration.Y, Acceleration.Z));

	UE_LOG(LogTemp, Warning, TEXT("RotationRate X : %f / Y : %f / Z : %f"), RotationRate.X, RotationRate.Y, RotationRate.Z);
	UE_LOG(LogTemp, Warning, TEXT("Gravity X : %f / Y : %f / Z : %f"), Gravity.X, Gravity.Y, Gravity.Z);
	UE_LOG(LogTemp, Warning, TEXT("Acceleration X : %f / Y : %f / Z : %f"), Acceleration.X, Acceleration.Y, Acceleration.Z);
}

