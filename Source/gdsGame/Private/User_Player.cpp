// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "User_Player.h"

#include "Player_Interface.h"

AUser_Player::AUser_Player()
{
	PrimaryActorTick.bCanEverTick = true;
	timer_ = 0;
	delay_ = 10;
	can_press_ = true;
}

void AUser_Player::Tick(float DeltaSeconds)
{	

	Super::Tick(DeltaSeconds);
	timer_ += DeltaSeconds;

	if (timer_ >= delay_)
	{
	can_press_ = true ;
	
	}
}

// Called to bind functionality to input
void AUser_Player::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	if (can_press_) {

		// Check for User Input to buid
		InputComponent->BindAction("Modual1-Build-Unit", IE_Pressed, this, &APlayer_Interface::build_mod_one);
		InputComponent->BindAction("Modual2-Build-Unit", IE_Released, this, &APlayer_Interface::build_mod_two);
		InputComponent->BindAction("Modual3-Build-Unit", IE_Released, this, &APlayer_Interface::build_mod_three);

		// Check for User Spawn to buid
		InputComponent->BindAction("Modual1-Spawn-Unit", IE_Released, this, &APlayer_Interface::spawn_mod_one);
		InputComponent->BindAction("Modual2-Spawn-Unit", IE_Released, this, &APlayer_Interface::spawn_mod_two);
		InputComponent->BindAction("Modual3-Spawn-Unit", IE_Released, this, &APlayer_Interface::spawn_mod_three);
		can_press_ = false;
	}
}

