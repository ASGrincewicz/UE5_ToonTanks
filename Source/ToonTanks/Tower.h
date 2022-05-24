// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	ATower();
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();

protected:
	virtual void BeginPlay() override;
	virtual void CheckFireCondition() override;

private:
	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRange = 300.f;

	bool InFireRange();
};
