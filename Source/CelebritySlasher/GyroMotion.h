// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GyroMotion.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CELEBRITYSLASHER_API UGyroMotion : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGyroMotion();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
		
	AActor* Player;

	UPROPERTY(EditAnywhere)
	TArray<UCameraComponent*> Comps;

	UPROPERTY(EditAnywhere)
	UCameraComponent* FoundComp;

	void TransferMotionToCamera();

	void GetCameraComponent();
};
