// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class GAMEPROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(Category = "Projectile", BlueprintReadWrite)
		FString projectile_kind;//×Óµ¯»ò±¬Õ¨Îï
	UPROPERTY(Category = "Projectile", BlueprintReadWrite)
		int32 attack_point;
	UPROPERTY(Category = "Projectile", BlueprintReadWrite)
		FString attack_kind;
	UPROPERTY(Category = "Projectile", BlueprintReadWrite)
		float expolde_range;//±¬Õ¨·¶Î§
};
