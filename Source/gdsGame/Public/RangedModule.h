// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module.h"
#include "RangedModule.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API ARangedModule : public AModule
{
	GENERATED_BODY()

public:
	ARangedModule(const class FObjectInitializer& PCIP);
	
protected:
	// TODO(Rory) Add the ranged minion here, so that it can be spawned
	
	// Spawns the minion 
	UFUNCTION()
	virtual void SpawnMinion() override;

	// Asset to overlay the sprite on the module class
	UPROPERTY(VisibleAnywhere, Category = "Visual")
	UPaperFlipbook* module_flipbook_;

	// Asset to overlay the sprite on the module class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	UPaperFlipbookComponent* module_icon_;
	
};
