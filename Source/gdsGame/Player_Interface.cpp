// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
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
