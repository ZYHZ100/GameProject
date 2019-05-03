// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class GAMEPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void set_item(int32 item_id_in, FString item_name_in, int32 amount_in);
protected:
	UPROPERTY(Category = "Item", BlueprintReadOnly)
		int32 item_id;
	UPROPERTY(Category = "Item", BlueprintReadOnly)
		FString item_name;
	UPROPERTY(Category = "Item", BlueprintReadWrite)
		int32 amount;
};
