// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterPlayer.h"

// Sets default values
ACharacterPlayer::ACharacterPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterPlayer::change_health_add(float changed_num) {
	health_add += changed_num;
}

void ACharacterPlayer::change_armor_add(float changed_num) {
	armor_add += changed_num;
}

void ACharacterPlayer::change_move_add(float changed_num) {
	move_speed_add += changed_num;
}

void ACharacterPlayer::change_build_add(float changed_num) {
	build_speed_add += changed_num;
}


bool ACharacterPlayer::add_strenth() {
	if (attribute_point >= 1)
	{
		strength++;
		attribute_point--;
		return true;//见下
	}
	else
	{
		return false;
	}
}

bool ACharacterPlayer::add_agility() {
	if (attribute_point >= 1)
	{
		agility++;
		attribute_point--;
		return true;//见下
	}
	else
	{
		return false;
	}
}

bool ACharacterPlayer::add_stamina() {
	if (attribute_point >= 1)
	{
		stamina++;
		attribute_point--;
		return true;//加点成功，来个特效
	}
	else
	{
		return false;//加点不成功，来个提示
	}
}

bool ACharacterPlayer::get_exp(int32 exp_num)
{
	exp += exp_num;
	int64 exp_need = (2LL << level) * 100;
	if (exp >= exp_need)
	{
		exp -= exp_need;
		level++;
		attribute_point += 3;
		return true;//触发升级特效
	}
	return false;//不触发升级特效
}


