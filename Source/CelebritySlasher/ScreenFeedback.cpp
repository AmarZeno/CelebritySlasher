// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "ScreenFeedback.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values for this component's properties
UScreenFeedback::UScreenFeedback()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth = 100;
	MaxHealth = 100;
}


// Called when the game starts
void UScreenFeedback::BeginPlay()
{
	Super::BeginPlay();
	StartSurvivalDuration = 0;
}


// Called every frame
void UScreenFeedback::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	IncreasePlayerHealth(DeltaTime);
}

float UScreenFeedback::GetMaxHealth()
{
	return MaxHealth;
}

float UScreenFeedback::GetCurrentHealth()
{
	return CurrentHealth;
}

void UScreenFeedback::SetCurrentHealth(float NewHealth)
{
	CurrentHealth = NewHealth;
}

void UScreenFeedback::IncreasePlayerHealth(float DeltaTime) {
	if (GetCurrentHealth() != 100) {
		if (StartSurvivalDuration == 0) {
			StartSurvivalDuration = std::clock();
			OldHealth = GetCurrentHealth();
			print(FString::Printf(TEXT("Start timer : %f"), StartSurvivalDuration));
		}
		SurvivalDuration = (std::clock() - StartSurvivalDuration)/ (float)CLOCKS_PER_SEC;
		print(FString::Printf(TEXT("SurvivalDuration : %f"), SurvivalDuration));

		if (SurvivalDuration > 10 && OldHealth == GetCurrentHealth()) {
			SetCurrentHealth(GetCurrentHealth() + 5);
		}

		if (OldHealth != GetCurrentHealth()) {
			StartSurvivalDuration = 0;
		}
	}
}

