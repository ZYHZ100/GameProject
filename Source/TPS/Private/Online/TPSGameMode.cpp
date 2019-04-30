// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSGameMode.h"
#include "Player/MyPlayerState.h"
#include "Player/MySpectatorPawn.h"
#include "Player/MyPlayerController.h"
#include "Player/ShooterCharacter.h"
#include "MyGameState.h"
#include "UI/MyHUD.h"
ATPSGameMode::ATPSGameMode(){
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOB(TEXT("/Game/Blueprints/Pawns/PlayerPawn"));
    if(PlayerPawnOB.Class!=NULL){
        DefaultPawnClass=PlayerPawnOB.Class;
    }
    PlayerControllerClass=AMyPlayerController::StaticClass();
    PlayerStateClass=AMyPlayerState::StaticClass();
    GameStateClass=AMyGameState::StaticClass();
    HUDClass=AMyHUD::StaticClass();
    SpectatorClass=AMySpectatorPawn::StaticClass();
    
    
}
