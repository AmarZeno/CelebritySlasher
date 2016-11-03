// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	AActor *Enemy;

	void MoveTowardsPlayer();

	//UPROPERTY(EditAnywhere)
	//TArray<UCharacterMovementComponent*> Comps;

	//UPROPERTY(EditAnywhere)
	//	UCharacterMovementComponent* FoundComp;
};
