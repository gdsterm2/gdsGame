// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "gdsGameGameMode.h"
#include "GameFramework/Actor.h"
#include "Minion_interface.generated.h"

UCLASS()
class GDSGAME_API AMinion_interface : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinion_interface(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	// Spawn a Minion
	virtual void SpawnMinion(bool player, TSubclassOf<class AMinion> MinionToSpawn);

	// To get refrences to the user/enemy player
	void SetReferences(AUser_Player* User, AAI_Player* AI);

protected:


	// Update Minions
	virtual void UpdateMinions();

	// Battle Function
	virtual void Battle(class AMinion* minion_1, class AMinion* minion_2);

	// CleanUp Function
	virtual void CleanUp();

	/* The Minion that will be spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AMinion> TestMinionToSpawn;

	// List of player active minions
	TArray<class AMinion*> player_active_minions;

	// List of player dead minions
	TArray<class AMinion*> player_dead_minions;

	// List of ai active minions
	TArray<class AMinion*> ai_active_minions;

	// List of ai dead minions
	TArray<class AMinion*> ai_dead_minions;

	// List of dead minions
	TArray<class AMinion*> dead_minions;

	AUser_Player* user_player_;
	AAI_Player* ai_player_;

	float timePassed;
	bool changePlayer;
	
};
