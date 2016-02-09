// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "AttackModule.h"

AAttackModule::AAttackModule()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperSprite> IconVisual;
		FConstructorStatics()
			: IconVisual(TEXT("/Game/Temp_assists/temp_attackModule_sprite.temp_attackModule_sprite"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	module_icon_ = ConstructorStatics.IconVisual.Get();
}


void AAttackModule::SpawnMinion()
{
	// TODO(Rory) Implement overridden spawn minion function
	// Spawns the attack minion.
}