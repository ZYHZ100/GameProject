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
		float range;//��������
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float angle;//������Χ���ýǶȱ�ʾ
	UPROPERTY(Category = "WeaponMelee", BlueprintReadWrite)
		float attack_speed;//�����ٶȣ��ù��������ʾ����λs
};
