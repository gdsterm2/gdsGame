// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "Module.h"
#include "Kismet/KismetMathLibrary.h"
#include "PaperFlipbookComponent.h"
#include "Player_Interface.h"
// Sets default values
APlayer_Interface::APlayer_Interface()
{
	
		// Setup the assets
		struct FConstructorStatics
		{
			ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> home_base_assit;
			FConstructorStatics()
				: home_base_assit(TEXT("/Game/Temp_assists/temp_homeBase_Flipbook.temp_homeBase_Flipbook"))
			{
			}
		};
		static FConstructorStatics ConstructorStatics;

		home_base = ConstructorStatics.home_base_assit.Get();
		GetSprite()->SetFlipbook(home_base);

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Setting a default value of health
	initial_health = 100;

	// Setting deafult values for AP
	initial_action_points= 100;


	// Deafult speed of AP generation
	initial_action_points_generation = 1;

	// Default maxium ap value	
	max_action_points= 110;

	since_action_points_incr = 0;

	// turnning off gravity
	GetCharacterMovement()->GravityScale = 0.0f;

	GetSprite()->SetIsReplicated(true);
	bReplicates = true;

}

// Called when the game starts or when spawned
void APlayer_Interface::BeginPlay()
{
	Super::BeginPlay();
	current_action_points= initial_action_points;
	current_health = initial_health;
	action_points_generation_speed = initial_action_points_generation;


	// Check for a valid World: 
	UWorld* const World = GetWorld();

	if (World)
	{
		// Set the spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;

		// TODO: Work out location for 3 modules temp info placed for now

		// spawn the pickup
		AModule* const SpawnedModul1 = World->SpawnActor<AModule>(moduals_one, FVector(25, 0,50) ,FRotator(0,0,0), SpawnParams);

		AModule* const SpawnedModule2 = World->SpawnActor<AModule>(moduals_two, FVector(25, 0, -50) , FRotator(0, 0, 0), SpawnParams);

		AModule* const SpawnedModule3 = World->SpawnActor<AModule>(moduals_three, FVector(0, 0, 0) , FRotator(0, 0, 0), SpawnParams);

		moduals.Add(SpawnedModul1);
		moduals.Add(SpawnedModule2);
		moduals.Add(SpawnedModule3);

	}
	

}

// Called every frame
void APlayer_Interface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (current_action_points< max_action_points) 
	{
		// Add time since the last update of AP
		since_action_points_incr += DeltaTime;

		// Check if enough time has past since last AP gen
		if (since_action_points_incr >= action_points_generation_speed)
		{
			// Add to action_points

			current_action_points++;

			// Reset timer
			since_action_points_incr = 0;
		}
	}
}

// Will be called when player has died and needs to be reset	
void APlayer_Interface::reset()
{
	current_action_points = initial_action_points;
	current_health = initial_health;
	action_points_generation_speed = initial_action_points_generation;
	since_action_points_incr = 0;

}


// Called to bind functionality to input
void APlayer_Interface::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);


}
void APlayer_Interface::build_minion(class AModule* mod)
{

	//TODO:  Currently crashes maybe to do with interaction with module check when modules compplete!
	// Check Module is present
	if (mod)
	{
		// Make sure module is not already producing 

		if (!mod->IsProducingResource())
		{

			// Check player has enough to buy 
			if (mod->GetActionCost() <= current_action_points)
			{
				// Take away action_points cost
				current_action_points -= mod->GetActionCost();

				// Start building Minion
				mod->ProduceResource();
			}
		}
	}
	mod->ProduceResource();
}
void APlayer_Interface::spawn_minion(AModule * mod)
{
	// Spawn minion based on module 

	//mod->DeployResource();
}
void APlayer_Interface::build_mod_one()
{
	// Send Build info to Modual One
//	build_minion(moduals[0]);

}

void APlayer_Interface::build_mod_two()
{
	// Send Build info to Modual two
//	build_minion(moduals[1]);
}

void APlayer_Interface::build_mod_three()
{
	// Send Build info to Modual three
//	build_minion(moduals[2]);
}

void APlayer_Interface::spawn_mod_one()
{
	// Spawn minion based on module one
//	spawn_minion(moduals[0]);
}

void APlayer_Interface::spawn_mod_two()
{
	// Spawn minion based on module two

//	spawn_minion(moduals[1]);

}

void APlayer_Interface::spawn_mod_three()
{
	// Spawn minion based on module three

//	spawn_minion(moduals[2]);

}

void APlayer_Interface::set_health(int32 const h)
{
	current_health = h;
}

int32 APlayer_Interface::get_health() const
{
	return current_health;
}

void APlayer_Interface::set_action_points(int32 const p)
{
	current_action_points = p;
}

int32 APlayer_Interface::get_action_points() const
{
	return current_action_points;
}
