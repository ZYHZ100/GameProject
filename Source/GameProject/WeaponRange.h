// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "WeaponRange.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AWeaponRange : public AWeapon
{
	GENERATED_BODY()
protected:
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float init_speed;//弹道初速度
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float fall_speed;//弹道下坠速度
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		int32 ammo_id;//对应子弹id
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		int32 magazine;//弹匣容量
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		int32 reserve_ammo;//后备弹容量
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float attack_speed;//攻击速度，用攻击间隔表示，单位s
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float reload_speed;//装弹时间，用攻击间隔表示，单位s
};
