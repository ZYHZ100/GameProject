// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class TPS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()
    AShooterCharacter();

public:
	// Sets default values for this character's properties	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category=Camera)
    float BaseTurnRate;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category=Camera)
    float BaseLookUpRate;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    void MoveForward(float value);
    void MoveRight(float value);
    
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category=Camera,meta=(AllowPrivateAccess="true"))
    class UCameraComponent* FollowCamera;
    UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Camera,meta=(AllowPrivateAccess="true"))
    class USpringArmComponent* CameraBoom;
    //USkeletalMeshComponent

};
