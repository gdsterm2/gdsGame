// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "DefenceModule.h"

ADefenceModule::ADefenceModule()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperSprite> IconVisual;
		FConstructorStatics()
			: IconVisual(TEXT("/Game/Temp_assists/temp_defenceModule_sprite.temp_defenceModule_sprite"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	module_icon_ = ConstructorStatics.IconVisual.Get();
}

void ADefenceModule::SpawnMinion()
{
	// TODO(Rory) Implement overridden spawn minion function
	// Spawns the attack minion.
}

