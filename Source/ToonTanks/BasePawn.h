// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();

private:
	UPROPERTY(VisibleAnywhere, Category = "Physics", meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, Category = "Mesh", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, Category = "Mesh", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, Category = "Combat", meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")	
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")	
	class UParticleSystem* DestructionParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase* DestructionSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> DestructionCameraShakeClass;

protected:
	void RotateTurret(FVector LookAtTarget);

	void Fire();
};
