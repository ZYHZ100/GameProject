// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "WeaponMelee.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AWeaponMelee : public AWeapon
{
	GENERATED_BODY()
protected:
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float range;//攻击距离
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float angle;//攻击范围，用角度表示
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float attack_speed;//攻击速度，用攻击间隔表示，单位s
};
