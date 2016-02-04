// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "Module.h"
#include "Kismet/KismetMathLibrary.h"

#include "Player_Interface.h"


// Sets default values
APlayer_Interface::APlayer_Interface()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Setting a default value of health
	initial_health = 100;

	// Setting deafult values for AP
	initial_ap = 100;


	// Deafult speed of AP generation
	initial_ap_generation = 1;

	// Default maxium ap value	
	max_ap = 110;

	since_ap_incr = 0;
}

// Called when the game starts or when spawned
void APlayer_Interface::BeginPlay()
{
	Super::BeginPlay();
	current_ap = initial_ap;
	current_health = initial_health;
	ap_generation_speed = initial_ap_generation;


	// Check for a valid World: 
	UWorld* const World = GetWorld();

	if (World)
	{
		// Set the spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;



		// spawn the pickup
		AModule* const SpawnedModul1 = World->SpawnActor<AModule>(moduals_one, FVector(100, 0,100) ,FRotator(0,0,0), SpawnParams);

		AModule* const SpawnedModule2 = World->SpawnActor<AModule>(moduals_two, FVector(200, 0, 200) , FRotator(0, 0, 0), SpawnParams);

		AModule* const SpawnedModule3 = World->SpawnActor<AModule>(moduals_three, FVector(300, 0, 300) , FRotator(0, 0, 0), SpawnParams);

		moduals.Add(SpawnedModul1);
		moduals.Add(SpawnedModule2);
		moduals.Add(SpawnedModule3);

	}
	

}

// Called every frame
void APlayer_Interface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (current_ap < max_ap) 
	{
		// Add time since the last update of AP
		since_ap_incr += DeltaTime;

		// Check if enough time has past since last AP gen
		if (since_ap_incr >= ap_generation_speed)
		{
			// Add to AP

			current_ap++;

			// Reset timer
			since_ap_incr = 0;
		}
	}
}

// Will be called when player has died and needs to be reset	
void APlayer_Interface::reset()
{
	current_ap = initial_ap;
	current_health = initial_health;
	ap_generation_speed = initial_ap_generation;
	since_ap_incr = 0;

}


// Called to bind functionality to input
void APlayer_Interface::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Check for any buid inputs
	InputComponent->BindAction("Modual1-Build-Unit", IE_Released, this, &APlayer_Interface::build_mod_one);
	InputComponent->BindAction("Modual2-Build-Unit", IE_Released, this, &APlayer_Interface::build_mod_two);
	InputComponent->BindAction("Modual3-Build-Unit", IE_Released, this, &APlayer_Interface::build_mod_three);


	InputComponent->BindAction("Modual1-Spawn-Unit", IE_Released, this, &APlayer_Interface::spawn_mod_one);
	InputComponent->BindAction("Modual2-Spawn-Unit", IE_Released, this, &APlayer_Interface::spawn_mod_two);
	InputComponent->BindAction("Modual3-Spawn-Unit", IE_Released, this, &APlayer_Interface::spawn_mod_three);

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
			if (mod->GetActionCost() <= current_ap)
			{
				// Take away AP cost
				current_ap -= mod->GetActionCost();

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

void APlayer_Interface::set_ap(int32 const p)
{
	current_ap = p;
}

int32 APlayer_Interface::get_ap() const
{
	return current_ap;
}
