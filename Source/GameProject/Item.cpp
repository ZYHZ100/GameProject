// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::set_item(int32 item_id_in, FString item_name_in, int32 amount_in)
{
	item_id = item_id_in;
	item_name = item_name_in;
	amount = amount_in;
}

