// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "Minion_interface.h"
#include "Minion.h"


// Sets default values
AMinion_interface::AMinion_interface(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	
	static ConstructorHelpers::FObjectFinder<UBlueprint> Minion_BP_test(TEXT("Blueprint'/Game/Blueprints/Minions/Minion_BP_test.Minion_BP_test'"));
			
	if (Minion_BP_test.Object)
	{
		TestMinionToSpawn = (UClass*)Minion_BP_test.Object->GeneratedClass;
	}

	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinion_interface::BeginPlay()
{
	Super::BeginPlay();

	timePassed = 0;			// debugging var for regularly spawning minions
	changePlayer = true;	// debugging var for regularly alternating spawning minions	
}

// Called every frame
void AMinion_interface::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	timePassed += DeltaTime;	// debugging var for regularly spawning minions
	UpdateMinions();
	
	if (timePassed > 1)
	{
		SpawnMinion(changePlayer, TestMinionToSpawn);
		timePassed = 0;
		if (changePlayer)
		{
			changePlayer = false;
		}
		else
		{
			changePlayer = true;
		}
	}
}

void AMinion_interface::SpawnMinion(bool player, TSubclassOf<class AMinion> MinionToSpawn)
{
	UWorld* const World = GetWorld();

	if (World)
	{
		// Set the spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;

		// Make sure not rotated
		FRotator SpawnRotation = FRotator(0, 0, 0);

		FVector Minion_start;
		
		// if the player has requested the minion
		if (player)
		{
			// Set the start position to the player's home
			Minion_start = FVector(-600, 0, 0);

			// Create the player's minion in the world
			AMinion* const player_minion = World->SpawnActor<AMinion>(MinionToSpawn, Minion_start, SpawnRotation, SpawnParams);

			// Add this minion to the list of active player minions
			player_active_minions.Add(player_minion);
		}
		else // if the ai has requested the minion
		{
			// Set the start position to the ai's home
			Minion_start = FVector(600, 0, 0);

			// Create the ai's minion in the world
			AMinion* const ai_minion = World->SpawnActor<AMinion>(MinionToSpawn, Minion_start, SpawnRotation, SpawnParams);

			// Add this minion to the list of active ai minions
			ai_active_minions.Add(ai_minion);
		}		
	}
}

void AMinion_interface::UpdateMinions()
{
	// For all minions in the player's active list
	for (AMinion* minionIt : player_active_minions)
	{
		// Add the minion's movement speed to the current location
		FVector position = minionIt->GetActorLocation();
		FVector new_location = position + FVector(-minionIt->get_speed(), 0.0f, 0.0f);

		// Set the minion's new location
		minionIt->SetActorLocation(new_location);
	}

	// For all minions in the ai's active list
	for (AMinion* minionIt : ai_active_minions)
	{
		// Add the minion's movement speed to the current location
		FVector position = minionIt->GetActorLocation();
		FVector new_location = position + FVector(minionIt->get_speed(), 0.0f, 0.0f);

		// Set the minion's new location
		minionIt->SetActorLocation(new_location);
	}
}

