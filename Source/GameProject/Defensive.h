// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Defensive.generated.h"

UCLASS()
class GAMEPROJECT_API ADefensive : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADefensive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY(Category = "Defensive", BlueprintReadWrite)
		bool attackable;
	UPROPERTY(Category = "Defensive", BlueprintReadWrite)
		FString defensive_type;//Trap or Turret
	UPROPERTY(Category = "Defensive", BlueprintReadWrite)
		int32 attack_point;
	UPROPERTY(Category = "Defensive", BlueprintReadWrite)
		FString attack_kind;
	UPROPERTY(Category = "Defensive", BlueprintReadWrite)
		float attack_speed;//¹¥»÷ËÙ¶È£¬ÓÃ¹¥»÷¼ä¸ô±íÊ¾£¬µ¥Î»s
	UPROPERTY(Category = "Defensive", BlueprintReadWrite)
		float range;//¹¥»÷¾àÀë
};
