// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class CELEBRITYSLASHER_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpeedOfMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ZDidHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ZDidPowerHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ZIsScreaming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ZIsCrawling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ZIsAttacking;

};
