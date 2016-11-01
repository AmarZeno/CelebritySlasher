// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "LookAtAndMove.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CELEBRITYSLASHER_API ULookAtAndMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULookAtAndMove();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void LookAtCamera();
	
	AActor *Enemy;
};
