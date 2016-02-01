// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Module.generated.h"

UENUM(BlueprintType)
enum class EModuleUnitType
{
	ATTACK,
	DEFENCE,
	RANGED
};

UCLASS()
class GDSGAME_API AModule : public APawn
{
	GENERATED_BODY()

public:


	// Sets default values for this pawn's properties
	AModule();

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

	// Set the type of this module
	UFUNCTION(BlueprintCallable, Category = "Module")
	void SetModuleType(EModuleUnitType const type);

	// Return the module type
	UFUNCTION(BlueprintPure, Category = "Module")
	EModuleUnitType GetModuleType() const;

	// Return whether module producing resource or not
	UFUNCTION(BlueprintPure, Category = "Module")
	bool IsProducingResource() const;



protected:

	/* The Minion that will be spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AMinion> MinionToSpawn;

	// Spawns the minion 
	UFUNCTION()
	void SpawnMinion();


	//TODO(Rory) Update this to display representation of module type
	UPROPERTY(VisibleAnywhere, Category = "Cube")
	UShapeComponent *cube;

	EModuleUnitType module_type_;

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
