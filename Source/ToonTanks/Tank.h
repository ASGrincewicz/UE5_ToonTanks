// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Tank Components")
	class USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, Category = "Tank Components")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere,Category = "Movement")
	float Speed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate;
	
	void Move(float value);

	void Turn(float Value);
	
};
