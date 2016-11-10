// Fill out your copyright notice in the Description page of Project Settings.

#include "CelebritySlasher.h"
#include "ScreenFeedback.h"

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
			StartSurvivalDuration = DeltaTime;
			OldHealth = GetCurrentHealth();
		}
		SurvivalDuration = StartSurvivalDuration - DeltaTime;
		if (SurvivalDuration > 10 && OldHealth == GetCurrentHealth()) {
			SetCurrentHealth(GetCurrentHealth() + 5);
			StartSurvivalDuration = 0;
		}
		else {
			StartSurvivalDuration = 0;
		}
	}
}

