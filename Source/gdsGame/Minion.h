// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "Minion.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API AMinion : public APaperCharacter
{
	GENERATED_BODY()
public:
	AMinion();
		
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	/*	Get the current health of the minions
	@reurn: Health value
	*/
	UFUNCTION(BlueprintPure, Category = "Minion")
		float get_health() const;

	/*	Get the current damage of the minion
	@reurn: damange value
	*/
	UFUNCTION(BlueprintPure, Category = "Minion")
		float get_damange() const;

	/*	Get the current speed of the minion
	@reurn: speed value
	*/
	UFUNCTION(BlueprintPure, Category = "Minion")
		float get_speed() const;

	/*	Set's the health of the minion
	@prams: h - New value of health of minion
	*/
	UFUNCTION(BlueprintCallable, Category = "Minion")
		void set_health(float const h);


	/*	Set's the damange of the player
	@prams: d - New value of damage of minion
	*/
	UFUNCTION(BlueprintCallable, Category = "Minion")
		void set_damange(float const d);


	/*	Set's the movement speed of the minion
	@prams: s - New value of speed of minion
	*/
	UFUNCTION(BlueprintCallable, Category = "Minion")
		void set_speed(float const s);

	bool alive;
	

protected:
	// The animation to play while running around
	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* DefaultAnimation;

	// Start health value of a minion 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Minion", Meta = (BluePrintProtected))
		float initial_health;

	// The starting damange value of a minion
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Minion", Meta = (BluePrintProtected))
		float initial_damange;

	// The starting damange value of a minion
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Minion", Meta = (BluePrintProtected))
		float initial_speed;

	


private:

	// current health value of the minion
	UPROPERTY(VisibleAnywhere, Category = "Minion")
	class UPaperFlipbook* CurrentAnimation;


	// current health value of the minion
	UPROPERTY(VisibleAnywhere, Category = "Minion")
		float current_health;

	// current damange of the minion
	UPROPERTY(VisibleAnywhere, Category = "Minion")
		float damange;

	// current speed of the minion
	UPROPERTY(VisibleAnywhere, Category = "Minion")
		float speed;

	
};
