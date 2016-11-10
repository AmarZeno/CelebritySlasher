// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include <cstdio>
#include <ctime>
#include "ScreenFeedback.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CELEBRITYSLASHER_API UScreenFeedback : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScreenFeedback();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


	float StartTimer;

	float ElapsedTimer;


	UPROPERTY(BlueprintReadWrite, Category = "Health")
	float CurrentHealth;

	UPROPERTY(BlueprintReadWrite, Category = "Health")
	float MaxHealth;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float NewHealth);

	void IncreasePlayerHealth(float Health);

	float OldHealth;

	float SurvivalDuration;

	std::clock_t StartSurvivalDuration;
};
