// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

protected:
	// Spawn a Minion
	virtual void SpawnMinion(bool player, TSubclassOf<class AMinion> MinionToSpawn);

	// Update Minions
	virtual void UpdateMinions();

	/* The Minion that will be spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AMinion> TestMinionToSpawn;

	// List of player active minions
	TArray<class AMinion*> player_active_minions;

	// List of ai active minions
	TArray<class AMinion*> ai_active_minions;

	float timePassed;
	bool changePlayer;
	
};
