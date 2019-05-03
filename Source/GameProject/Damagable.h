// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Damagable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPROJECT_API UDamagable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamagable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	int32 take_damage(FString attack_kind, int32 attack_point, int32 armor_reduce);
	int32 kind2num(FString kind);
protected:
	UPROPERTY(Category = "Damagable", BlueprintReadWrite)
		int32 health;
	UPROPERTY(Category = "Damagable", BlueprintReadWrite)
		int32 armor;
	UPROPERTY(Category = "Damagable", BlueprintReadWrite)
		FString armor_kind;//I means iron,E means energy,B means biomass,B->E->I->B


		
};
