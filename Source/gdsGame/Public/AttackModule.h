// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module.h"
#include "PaperCharacter.h"
#include "AttackModule.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API AAttackModule : public AModule
{
	GENERATED_BODY()

public:
	// Sets default values for this modules properties
	AAttackModule(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;
	
protected:
	// TODO(Rory) Add the attack minion here, so that it can be spawned


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
