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
		float range;//¹¥»÷¾àÀë
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float angle;//¹¥»÷·¶Î§£¬ÓÃ½Ç¶È±íÊ¾
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float attack_speed;//¹¥»÷ËÙ¶È£¬ÓÃ¹¥»÷¼ä¸ô±íÊ¾£¬µ¥Î»s
};
