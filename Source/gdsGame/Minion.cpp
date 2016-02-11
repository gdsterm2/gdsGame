// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "PaperFlipbookComponent.h"
#include "Minion.h"
#include "Components/TextRenderComponent.h"


AMinion::AMinion()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set minion to alive
	alive = true;

	// Default intial health
	initial_health = 100;

	// Default intial damage
	initial_damange = 100;

	// Default intial speed
	initial_speed = 10;

	// Setup the assets
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> DefaultAnimationAssist;
		FConstructorStatics()
			: DefaultAnimationAssist(TEXT("/Game/Temp_assists/test_Flipbook.test_Flipbook"))

		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	DefaultAnimation = ConstructorStatics.DefaultAnimationAssist.Get();

	GetCharacterMovement()->GravityScale = 0.0f;

}

// Called when the game starts or when spawned
void AMinion::BeginPlay()
{
	Super::BeginPlay();

	// Set starting damange and health 
	current_health = initial_health;

	damange = initial_damange;

	speed = initial_speed;

}
// Called every frame
void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Getters and Setters //////////////////////////////////////////////

float AMinion::get_health() const
{
	return current_health;
}

float AMinion::get_damange() const
{
	return damange;
}

float AMinion::get_speed() const
{
	return speed;
}


void AMinion::set_health(float const h)
{
	current_health = h;
}

void AMinion::set_damange(float const d)
{
	damange = d;
}

void AMinion::set_speed(float const s)
{
	speed = s;
}
