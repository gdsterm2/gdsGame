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
	
	//if (timePassed > 1)
	//{
	//	SpawnMinion(changePlayer, TestMinionToSpawn);
	//	timePassed = 0;
	//	if (changePlayer)
	//	{
	//		changePlayer = false;
	//	}
	//	else
	//	{
	//		changePlayer = true;
	//	}
	//}
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

			//TODO: Memory Leak?
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
		FVector new_location = position + FVector(minionIt->get_speed(), 0.0f, 0.0f);

		// Set the minion's new location
		minionIt->SetActorLocation(new_location);
		
		// Check all minions in the ai's active list for collision
		for (AMinion* aiMinionIt : ai_active_minions)
		{
			// If the two minions colliders overlap
			if (minionIt->CapsuleComponent->OverlapComponent(aiMinionIt->CapsuleComponent->GetComponentLocation(), aiMinionIt->CapsuleComponent->GetComponentQuat(), aiMinionIt->CapsuleComponent->GetCollisionShape()))
			{
				// They Collide
				// Call Battle Function
				if (minionIt->alive & aiMinionIt->alive)
				{
					Battle(minionIt, aiMinionIt);
				}
			}
		}
	}

	// For all minions in the ai's active list
	for (AMinion* minionIt : ai_active_minions)
	{
		// Add the minion's movement speed to the current location
		FVector position = minionIt->GetActorLocation();
		FVector new_location = position + FVector(-minionIt->get_speed(), 0.0f, 0.0f);

		// Set the minion's new location
		minionIt->SetActorLocation(new_location);

		// Check all minions in the ai's active list for collision
		for (AMinion* pMinionIt : player_active_minions)
		{
			// If the two minions colliders overlap
			if (minionIt->CapsuleComponent->OverlapComponent(pMinionIt->CapsuleComponent->GetComponentLocation(), pMinionIt->CapsuleComponent->GetComponentQuat(), pMinionIt->CapsuleComponent->GetCollisionShape()))
			{
				// They Collide
				// Call Battle Function
				if (minionIt->alive & pMinionIt->alive)
				{
					Battle(pMinionIt, minionIt);
				}
			}
		}
	}

	CleanUp();
}

void AMinion_interface::Battle(class AMinion* p_minion, class AMinion* ai_minion)
{
	float m1_health = p_minion->get_health();
	float m1_damage = p_minion->get_damange();
	float m2_health = ai_minion->get_health();
	float m2_damage = ai_minion->get_damange();

	do
	{
		m1_health -= m2_damage;
		m2_health -= m1_damage;
	}
	while ((m1_health > 0.0f) & (m2_health > 0.0f));

	if (m1_health <= 0.0)
	{
		p_minion->alive = false;
	}
	else
	{
		p_minion->set_health(m1_health);
	}

	if (m2_health <= 0.0)
	{
		ai_minion->alive = false;
	}
	else
	{
		ai_minion->set_health(m2_health);
	}
}

void AMinion_interface::CleanUp()
{
	int32 x;
	bool pDeath = false;
	bool aiDeath = false;

	// For all minions in the player's active list
	for (AMinion* minionIt : player_active_minions)
	{
		// If the minion has been killed
		if (!minionIt->alive)
		{
			// Add the minion to the list of dead minions
			player_dead_minions.Add(minionIt);

			pDeath = true;
		}
	}

	// For all minions in the ai's active list
	for (AMinion* minionIt : ai_active_minions)
	{
		// If the minion has been killed
		if (!minionIt->alive)
		{
			// Add the minion to the list of dead minions
			ai_dead_minions.Add(minionIt);

			aiDeath = true;
		}
	}

	// If a player's minion died this frame
	if (pDeath)
	{
		// For all minions in the dead list
		for (AMinion* minionIt : player_dead_minions)
		{
			// Find the minion in the active list
			x = player_active_minions.Find(minionIt);

			// Remove the minion from the active list
			player_active_minions.RemoveAt(x);

			// Destroy the actor
			minionIt->Destroy();
		}

		// Empty the list of dead minions
		player_dead_minions.Empty();
	}
	
	// If an ai's minion died this frame
	if (aiDeath)
	{
		// For all minions in the dead list
		for (AMinion* minionIt : ai_dead_minions)
		{
			// Find the minion in the active list
			x = ai_active_minions.Find(minionIt);

			// Remove the minion from the active list
			ai_active_minions.RemoveAt(x);
			
			// Destroy the actor
			minionIt->Destroy();
		}

		// Empty the list of dead minions
		ai_dead_minions.Empty();
	}
}

