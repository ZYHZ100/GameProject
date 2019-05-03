// Fill out your copyright notice in the Description page of Project Settings.

#include "Damagable.h"

// Sets default values for this component's properties
UDamagable::UDamagable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamagable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDamagable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UDamagable::take_damage(FString attack_kind, int32 attack_point, int32 armor_reduce)//伤害计算公式
{
	int32 useful = 0;
	int32 attack_kind_temp = kind2num(attack_kind);
	int32 armor_kind_temp = kind2num(armor_kind);
	useful = attack_kind_temp - armor_kind_temp;
	if (useful == -2) {
		useful = 1;
	}
	if (useful == 2) {
		useful = -1;
	}
	float hurt_reduce = armor / (armor + 200);
	int32 damage = int32(attack_point * armor_reduce*(1 + 0.15*useful));


	return damage;//返回造成的伤害值（int32型）
}

int32 UDamagable::kind2num(FString kind)
{
	FString cmp_temp = "B";
	if (kind == cmp_temp) {
		return 3;
	}
	cmp_temp = "E";
	if (kind == cmp_temp) {
		return 2;
	}
	cmp_temp = "I";
	if (kind == cmp_temp) {
		return 1;
	}
	return -1;
}

