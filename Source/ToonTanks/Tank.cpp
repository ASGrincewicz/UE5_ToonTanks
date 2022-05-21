// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "../../Plugins/Developer/RiderLink/Source/RD/thirdparty/spdlog/include/spdlog/fmt/bundled/core.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 600;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());

	DrawDebugSphere(GetWorld(),GetActorLocation() + FVector(0.f,0.f,200.f),100.f,12,FColor::Red,true,30.f);
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(PlayerControllerRef)
	{
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);
	}
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&ATank::Move);

	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&ATank::Turn);
}

void ATank::Move(float value)
{
	
	FVector DeltaLocation(0.f);	
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaLocation.X = value * Speed * DeltaTime;
	AddActorLocalOffset(DeltaLocation,true);
	UE_LOG(LogTemp,Display,TEXT("Move input value: %f"),value);
}

void ATank::Turn(float Value)
{
	FRotator DeltaRotation(0.f);
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaRotation.Yaw = Value * TurnRate * DeltaTime;
	AddActorLocalRotation(DeltaRotation, true);
}


