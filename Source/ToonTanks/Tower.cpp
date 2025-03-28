// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (CheckTankInRange())
        RotateTurret(Tank->GetActorLocation());
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
    if (Tank == nullptr) return;

    if (CheckTankInRange() && Tank->bAlive)
        Fire();

}

bool ATower::CheckTankInRange()
{
    if (!Tank)
        return false;

    FVector TankPosition = Tank->GetActorLocation();
	float Distance = FVector::Dist( GetActorLocation(), TankPosition );

    return (Distance <= FireRange);
}