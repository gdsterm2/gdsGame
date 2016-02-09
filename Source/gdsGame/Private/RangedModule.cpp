// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "RangedModule.h"

ARangedModule::ARangedModule()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperSprite> IconVisual;
		FConstructorStatics()
			: IconVisual(TEXT("/Game/Temp_assists/temp_rangedModule_sprite.temp_rangedModule_sprite"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	module_icon_ = ConstructorStatics.IconVisual.Get();
}

void ARangedModule::SpawnMinion()
{
	// TODO(Rory) Implement overridden spawn minion function
	// Spawns the ranged minion.
}


