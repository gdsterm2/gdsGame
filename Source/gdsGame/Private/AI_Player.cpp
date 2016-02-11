// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "AI_Player.h"


AAI_Player::AAI_Player() : since_last_buid_try(0)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentModTrying = 0;


	how_often_try_build = 1;


}
AAI_Player::~AAI_Player()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called every frame
void AAI_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	since_last_buid_try += DeltaTime;

	if (since_last_buid_try > how_often_try_build)
	{
		since_last_buid_try = 0;
		try_build_minions();

	}
 
}

void AAI_Player::SetupPlayerInputComponent(UInputComponent * InputComponent)
{

	Super::SetupPlayerInputComponent(InputComponent);

}

void AAI_Player::try_build_minions()
{
	// Check if it can buy something 
	if (currentModTrying == 0)
	{
		build_mod_one();

	}
	else if (currentModTrying == 1)
	{
		build_mod_two();

	}
	else if (currentModTrying == 2)
	{
		build_mod_three();
		

	}
	else
	{
		spawn_mod_one();
		spawn_mod_two();

		spawn_mod_three();
		currentModTrying = 0;
		return;
	}

	currentModTrying++;

}