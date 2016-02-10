// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "DefenceModule.h"

ADefenceModule::ADefenceModule()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> IconVisual;
		FConstructorStatics()
			: IconVisual(TEXT("/Game/Temp_assists/temp_defenceModule_flipbook.temp_defenceModule_flipbook"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	module_flipbook_ = ConstructorStatics.IconVisual.Get();

	module_icon_ = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("ModuleIcon"));

	module_icon_->SetFlipbook(module_flipbook_);
	module_icon_->AttachTo(RootComponent);
}

void ADefenceModule::SpawnMinion()
{
	// TODO(Rory) Implement overridden spawn minion function
	// Spawns the attack minion.
}

