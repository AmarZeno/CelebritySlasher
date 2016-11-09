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
	
}


// Called every frame
void UScreenFeedback::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

float UScreenFeedback::GetMaxHealth()
{
	return 100;
}

float UScreenFeedback::GetCurrentHealth()
{
	return CurrentHealth;
}

void UScreenFeedback::SetCurrentHealth(float NewHealth)
{
	CurrentHealth = NewHealth;
}

