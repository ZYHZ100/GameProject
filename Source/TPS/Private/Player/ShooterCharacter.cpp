// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterCharacter.h"
#include "TPS.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
// Sets default values
AShooterCharacter::AShooterCharacter()
{
    
    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;
    
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    //set the third person ....
    GetMesh()->bOnlyOwnerSee = true;
    GetMesh()->bOwnerNoSee = false;
    GetMesh()->bReceivesDecals = true;
    GetMesh()->bCastDynamicShadow=true;
    //骨骼动画的更新在渲染时
    GetMesh()->MeshComponentUpdateFlag=EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
    //make the TPS mesh update group set as PrePhysics
    GetMesh()->PrimaryComponentTick.TickGroup=TG_PrePhysics;
    //set the mesh to be responsive to all types
    GetMesh()->SetCollisionObjectType(ECC_Pawn);
    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetMesh()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Block);
    GetMesh()->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    //set the capsule component of the character to be responsive to only projectiles
    GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_PROJECTILE,ECR_Block);
    GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON,ECR_Ignore);
    GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_PICKUP,ECR_Ignore);
    
    bUseControllerRotationPitch=false;
    bUseControllerRotationYaw=false;
    bUseControllerRotationRoll=false;
    
    GetCharacterMovement()->bOrientRotationToMovement=true;
    GetCharacterMovement()->RotationRate=FRotator(0.0f,540.0f,0.0f);
    GetCharacterMovement()->JumpZVelocity=600.0f;
    GetCharacterMovement()->AirControl=0.2f;
    
    //Camera object?
    
    CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    //CameraBoom->AttachTo(RootComponent);
    //CameraBoom->TargetOffset = FVector(0.f, 0.f, 0.f);
    //CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, BaseEyeHeight));
    //CameraBoom->SetRelativeRotation(FRotator(-10.f, 0.f, 0.f));
    CameraBoom->SetupAttachment(RootComponent); // attach it to the third person mesh
    CameraBoom->TargetArmLength = 300.f;
    CameraBoom->bEnableCameraLag = false;
    CameraBoom->bEnableCameraRotationLag = false;
    CameraBoom->bUsePawnControlRotation= true; // let the controller handle the view rotation
    
    //camera following the object?
    FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation=false;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
    //RootComponent->SetWorldLocation(FVector(0, 0, 0));
	
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    //the message is binded here (these are configured in editor in the input of project setting)
    PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AShooterCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AShooterCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("Turn"),this,&AShooterCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&AShooterCharacter::AddControllerPitchInput);

}

void AShooterCharacter::MoveForward(float value){
    //get the direction of moveing forward and move
    if(Controller!=nullptr){
        bool bLimitRotation=(GetCharacterMovement()->IsMovingOnGround()||GetCharacterMovement()->IsFalling());
        const FRotator Rotation=bLimitRotation?GetActorRotation():Controller->GetControlRotation();
        const FVector Direction =FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction,value);
    }
    
}
void AShooterCharacter::MoveRight(float value){
    //get the direction of moveing right and move
    if(Controller!=nullptr){
        // find out which way is right
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        
        // get right vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        // add movement in that direction
        AddMovementInput(Direction, value);
    }
}
