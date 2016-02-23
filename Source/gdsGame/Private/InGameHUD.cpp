// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "User_Player.h"
#include "InGameHUD.h"
#include "SInGameUI.h"
#include "Kismet/GameplayStatics.h"
#include "gdsGameGameMode.h"
#include "Engine.h"

AInGameHUD::AInGameHUD(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void AInGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(InGameUI, SInGameUI).InGameHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(InGameUI.ToSharedRef()));
	}
}

void AInGameHUD::SetPlayer(class AUser_Player* player_ref)
{
	player_ref_ = player_ref;
}

void AInGameHUD::GenerateResourcePressed(int32 module_num)
{
	// Get game mode from world
	TObjectIterator< APlayerController > ThePC;
	UWorld* TheWorld = ThePC->GetWorld();
	AgdsGameGameMode* MyGM = Cast<AgdsGameGameMode>( UGameplayStatics::GetGameMode(TheWorld));

	// Call game mode produce function
	MyGM->Produce(module_num);
}

void AInGameHUD::SpawnMinionPressed(int32 module_num)
{
	// Get game mode from world
	TObjectIterator< APlayerController > ThePC;
	UWorld* TheWorld = ThePC->GetWorld();
	AgdsGameGameMode* MyGM = Cast<AgdsGameGameMode>(UGameplayStatics::GetGameMode(TheWorld));

	// Call Game mode spawn function
	MyGM->Spawn(module_num);
}


