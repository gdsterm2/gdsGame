// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "Minion_interface.h"


// Sets default values
AMinion_interface::AMinion_interface()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinion_interface::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMinion_interface::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

