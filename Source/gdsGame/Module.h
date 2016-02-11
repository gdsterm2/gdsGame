// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Module.generated.h"


UCLASS()
class GDSGAME_API AModule : public APaperCharacter
{
	GENERATED_BODY()

public:


	// Sets default values for this pawn's properties
	AModule(const class FObjectInitializer& PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;




	// For telling module to produce resource
	UFUNCTION(BlueprintCallable, Category = "Module")
	void ProduceResource();

	// For telling module to deploy resource (will return true if successful)
	UFUNCTION(BlueprintCallable, Category = "Module")
	bool DeployResource() ;

	// Return the action timer
	UFUNCTION(BlueprintPure, Category = "Module")
	float GetActionTimer() const;

	// Return the action timer count
	UFUNCTION(BlueprintPure, Category = "Module")
	float GetActionTimerCount() const;

	// Return the action cost
	UFUNCTION(BlueprintPure, Category = "Module")
	int32 GetActionCost() const;

	// Sets the resources held by this module
	UFUNCTION(BlueprintCallable, Category = "Module")
	void SetResourceBank(int32 const resources);

	// Return the ammount of resources held by this module
	UFUNCTION(BlueprintPure, Category = "Module")
	int32 GetResourceBank() const;

	// Return whether module producing resource or not
	UFUNCTION(BlueprintPure, Category = "Module")
	bool IsProducingResource() const;

	UFUNCTION(BlueprintPure, Category = "Module")
	TSubclassOf<class AMinion> GetMinion() const;

protected:

	/* The Minion that will be spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AMinion> MinionToSpawn;

	// Spawns the minion 
	UFUNCTION()
	virtual void SpawnMinion();

	// PaperSprite for showing module
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	class UPaperFlipbook* module_visual_;

private:

	TArray<class AMinion*> minionSpawned;

	// Ammount of time needed to produce resource
	float action_timer_;
	// Counts time until action_timer_ is reached
	// To tell when resource has been pproduced
	float action_timer_count_;
	// Cost of producing resource
	int32 action_cost_;
	// Used to tell whether a resource is being produced
	bool producing_resource_;
	// Ammount of resource currently stored
	int32 resource_bank_;	
	
};
