// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "DefenceModule.h"

ADefenceModule::ADefenceModule(const class FObjectInitializer& PCIP) : Super(PCIP)
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

	// Retreive the reference to the blueprint for the defence minion
	static ConstructorHelpers::FObjectFinder<UBlueprint> Minion_Defence_0_BP(TEXT("Blueprint'/Game/Blueprints/Minions/Minion_Defence_0_BP.Minion_Defence_0_BP'"));

	// If the retrieval was successful set it as this module's minion
	if (Minion_Defence_0_BP.Object)
	{
		MinionToSpawn = (UClass*)Minion_Defence_0_BP.Object->GeneratedClass;
	}
}

void ADefenceModule::SpawnMinion()
{
	// TODO(Rory) Implement overridden spawn minion function
	// Spawns the attack minion.
}

