// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

UCLASS()
class GAMEPROJECT_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(Category = "Weapon", BlueprintReadWrite)
		int32 attack_point;
	UPROPERTY(Category = "Weapon", BlueprintReadWrite)
		FString attack_kind;
	UPROPERTY(Category = "Weapon", BlueprintReadWrite)
		FString weapon_kind;//ranged or melee
};
