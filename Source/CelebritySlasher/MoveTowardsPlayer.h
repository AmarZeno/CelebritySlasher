// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnemyCharacter.h"
#include "Components/ActorComponent.h"
#include "MoveTowardsPlayer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CELEBRITYSLASHER_API UMoveTowardsPlayer : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveTowardsPlayer();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	AEnemyCharacter *Enemy;

	FVector LocationDifference;

	float RandomActionValue;

	void MoveTowardsPlayer();

	void TriggerZombieAction();

	//UPROPERTY(EditAnywhere)
	//TArray<UCharacterMovementComponent*> Comps;

	//UPROPERTY(EditAnywhere)
	//	UCharacterMovementComponent* FoundComp;
};
