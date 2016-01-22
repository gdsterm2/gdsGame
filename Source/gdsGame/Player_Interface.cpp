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
}

// Called when the game starts or when spawned
void APlayer_Interface::BeginPlay()
{
	Super::BeginPlay();
	current_ap = initial_ap;
	current_health = initial_health;

}

// Called every frame
void APlayer_Interface::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

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
