// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EaseMover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDPTERM2PROJECT_API UEaseMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEaseMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	FVector StartLocation;
	FVector TargetLocation;
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, Category = "Move")
	float StartTime = 0.0f; // The time the movement started
	
	UPROPERTY(EditAnywhere, Category = "Move")
	float MoveTime = 1.0f; // The total time the movement should take
	
	UPROPERTY(EditAnywhere, Category="Move")
	FVector MoveOffset;
	
	UPROPERTY(EditAnywhere, Category="Move")
	bool BMoveReverse = false;

	UPROPERTY(EditAnywhere, Category="Move")
	bool BContinuousMovement = false;

	FVector SmoothstepInterp(const FVector& Current, const FVector& Target, float Alpha); // Function for ease motion
	void MasterMove(float DeltaTime);
	void FMoveReverse(float DeltaTime);
	void FMoveForward(float DeltaTime);
	void FContinuousMove(float DeltaTime);


	// Rotate variables and functions
	FRotator StartRotation;
	FRotator TargetRotation;
	FRotator CurrentRotation;

	UPROPERTY(EditAnywhere, Category="Rotate")
	FRotator RotateOffset;

	UPROPERTY(EditAnywhere, Category="Rotate", meta=(ClampMin="0", ClampMax="1000", UIMin="0", UIMax="1000"))
	float RotationTime = 1.0f;

	UPROPERTY(EditAnywhere, Category="Rotate")
	bool BRotateReverse = false;

	UPROPERTY(EditAnywhere, Category="Rotate")
	bool BContinuousRotation = false;
	
	void MasterRotate(float DeltaTime);
	void FRotateReverse(float DeltaTime);
	void FRotateForward(float DeltaTime);
	void FContinuousRotate(float DeltaTime);
};
