// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterPlayer.generated.h"

UCLASS()
class GAMEPROJECT_API ACharacterPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
		void change_health_add(float changed_num);
	UFUNCTION()
		void change_armor_add(float changed_num);
	UFUNCTION()
		void change_move_add(float changed_num);
	UFUNCTION()
		void change_build_add(float changed_num);
	UFUNCTION()
		bool add_strenth();
	UFUNCTION()
		bool add_agility();
	UFUNCTION()
		bool add_stamina();
	UFUNCTION()
		bool get_exp(int32 exp_num);

protected:
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		int32 level;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		int32 exp;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		float health_add;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		float armor_add;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		float move_speed_add;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		float build_speed;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		float build_speed_add;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		int32 attribute_point;
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		int32 strength;//affect recoil,melee weapon attack
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		int32 agility;//affect ranged weapon attack and move speed
	UPROPERTY(Category = "CharacterPlayer", BlueprintReadWrite)
		int32 stamina;//affect health and armor
};
