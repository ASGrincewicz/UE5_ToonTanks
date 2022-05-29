// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

//Forward Declarations;
class UCapsuleComponent;
class UParticleSystem;
class USoundBase;
UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	void HandleDestruction();
protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

	FTimerHandle FireRateTimerHandle;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRate = 2.0f;
	virtual void CheckFireCondition();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = true))
	UHealthComponent* HealthComponent;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = true))
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Pawn Components", meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category= "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* DeathSound;
};
