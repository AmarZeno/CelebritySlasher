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

	UE_LOG(LogTemp, Warning, TEXT("GyroMotion reporting!"));

	GetCameraComponent();
}


// Called every frame
void UGyroMotion::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...

	TransferMotionToCamera();
}

void UGyroMotion::GetCameraComponent() {
	Player->GetComponents(Comps);
	if (Comps.Num() > 0)
	{
		FoundComp = Comps[0];
	}
}

void UGyroMotion::TransferMotionToCamera() {
	FVector Tilt;
	FVector RotationRate;
	FVector Gravity;
	FVector Acceleration;

	GetWorld()->GetFirstPlayerController()->GetInputMotionState(
		OUT Tilt,
		OUT RotationRate,
		OUT Gravity,
		OUT Acceleration);

	FoundComp->AddLocalRotation(FRotator(0, -RotationRate.Y, 0));

	// Print on screen
	/*print(FString::Printf(TEXT("TiltRate X : %f / Y : %f / Z : %f"), Tilt.X, Tilt.Y, Tilt.Z));
	print(FString::Printf(TEXT("RotationRate X : %f / Y : %f / Z : %f"), RotationRate.X, RotationRate.Y, RotationRate.Z));
	print(FString::Printf(TEXT("Gravity X : %f / Y : %f / Z : %f"), Gravity.X, Gravity.Y, Gravity.Z));
	print(FString::Printf(TEXT("Acceleration X : %f / Y : %f / Z : %f"), Acceleration.X, Acceleration.Y, Acceleration.Z));*/

	UE_LOG(LogTemp, Warning, TEXT("RotationRate X : %f / Y : %f / Z : %f"), RotationRate.X, RotationRate.Y, RotationRate.Z);
	UE_LOG(LogTemp, Warning, TEXT("Gravity X : %f / Y : %f / Z : %f"), Gravity.X, Gravity.Y, Gravity.Z);
	UE_LOG(LogTemp, Warning, TEXT("Acceleration X : %f / Y : %f / Z : %f"), Acceleration.X, Acceleration.Y, Acceleration.Z);
}
