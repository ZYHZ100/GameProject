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
		float init_speed;//�������ٶ�
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float fall_speed;//������׹�ٶ�
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		int32 ammo_id;//��Ӧ�ӵ�id
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		int32 magazine;//��ϻ����
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		int32 reserve_ammo;//�󱸵�����
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float attack_speed;//�����ٶȣ��ù��������ʾ����λs
	UPROPERTY(Category = "WeaponRanged", BlueprintReadWrite)
		float reload_speed;//װ��ʱ�䣬�ù��������ʾ����λs
};
