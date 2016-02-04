// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "AI_Player.h"


AAI_Player::AAI_Player()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

 
}