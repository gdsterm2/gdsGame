// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "gdsGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "InGameHUD.h"
#include "EngineUtils.h"


AgdsGameGameMode::AgdsGameGameMode(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	HUDClass = AInGameHUD::StaticClass();
}

void AgdsGameGameMode::Tick(float DeltaTimer)
{
	Super::Tick(DeltaTimer);
	
	switch (current_state)
	{
	case EGame_state::ELoading:
		{
			BuildLevel();
			current_state = EGame_state::EPlaying;
			break;
		}
	case EGame_state::EPlaying:
	{
		break;
	}
	case EGame_state::EGameOver:
	{
		break;
	}
	case EGame_state::EWon:
	{
		break;
	}
	case EGame_state::EUnknown:
	{
		break;
	}
	default:
	{
		break;
	
	}
	
	}
}

EGame_state AgdsGameGameMode::GetCurrentState() const
{
	return current_state;
}
void AgdsGameGameMode::BeginPlay()
{
	
}
void AgdsGameGameMode::SetCurrentState(EGame_state newState)
{
	current_state = newState;
}

void AgdsGameGameMode::BuildLevel()
{

	// Spawn the two players 


	//TODO: Update the start pos to a proper location
	FVector Player_start = FVector(-600,0,0);
	FVector Enemy_start = FVector(600,0,0);

	// If we have set something to spawn:
	if (user_player != NULL && ai_player != NULL)
	{
		// Check for a valid World: 
		UWorld* const World = GetWorld();

		if (World)
		{
			// Set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// Make sure not rotated
			FRotator SpawnRotation = FRotator(0, 0, 0);

			// spawn the Players
			AUser_Player* const Player = World->SpawnActor<AUser_Player>(user_player, Player_start, SpawnRotation, SpawnParams);
			AAI_Player* const AI = World->SpawnActor<AAI_Player>(ai_player, Enemy_start, SpawnRotation, SpawnParams);
			AMinion_interface* const controller = World->SpawnActor<AMinion_interface>(minion_controller_, Enemy_start, SpawnRotation, SpawnParams);

			Player->set_minon_controller(controller);
			AI->set_minon_controller(controller);

			controller->SetReferences(Player, AI);
		}

	}
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (OurPlayerController)
	{

		for (TActorIterator<ACameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (ActorItr->GetName() == "PlayerCam")
			{

				cam = *ActorItr;
			}
		}
		if ((OurPlayerController->GetViewTarget() != cam) && (cam != nullptr))
		{
			// Cut instantly to camera one.
			OurPlayerController->SetViewTarget(cam);
		}

	}
}

void AgdsGameGameMode::Produce(int32 module_num)
{
	UWorld* const World = GetWorld();
	if (World)
	{
		AUser_Player* player = Cast<AUser_Player>(World->GetFirstPlayerController()->GetPawn());
		if (player)
		{
			if (module_num == 0)
			{
				player->build_mod_one();

			}
			else if (module_num == 1)
			{
				player->build_mod_two();

			}
			else if (module_num == 2)
			{
				player->build_mod_three();
			}
		}
	}

}

void AgdsGameGameMode::Spawn(int32 module_num)
{
	UWorld* const World = GetWorld();
	if (World)
	{
		AUser_Player* player = Cast<AUser_Player>(World->GetFirstPlayerController()->GetPawn());
		if (player)
		{
			GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Yellow, TEXT("Attempting spawn"));
			
			if (module_num == 0)
			{
				player->spawn_mod_one();

			}
			else if (module_num == 1)
			{
				player->spawn_mod_two();

			}
			else if (module_num == 2)
			{
				player->spawn_mod_three();
			}
		}
	}
}

