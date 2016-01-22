// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Player_Interface.generated.h"


// TODO: Add Spawn Modual 

// TODO: Add Unit Moduals

UCLASS()
class GDSGAME_API APlayer_Interface : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayer_Interface();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	/*	Set's the health of the player 
		@prams: h - New value of health of player
	*/
	UFUNCTION(BlueprintCallable, Category = "Player")
	void set_health(int32 const h);

	/*	Get the current health of the player
		@reurn: Health value 
	*/
	UFUNCTION(BlueprintPure, Category = "Player")
	int32 get_health() const;


	/*	Set's the AP value of the player
		@prams: p - New value of AP of player
	*/
	UFUNCTION(BlueprintCallable, Category = "Player")
	void set_ap(int32 const p);

	/*	Get the current AP of the player
		@reurn: AP value
	*/
	UFUNCTION(BlueprintPure, Category = "Player")
	int32 get_ap() const;

protected:

	// Holds the players health 
	UPROPERTY(VisibleAnywhere, Category = "Player")
	int32 current_health;
	
	// Holds the current AP
	UPROPERTY(VisibleAnywhere, Category = "Player")
	int32 current_ap;
	
	
	// Starting Health of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", Meta = (BluePrintProtected))
	int32 initial_health;

	// Starting AP of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", Meta = (BluePrintProtected))
	int32 initial_ap;


	// The max AP of the player can achive
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player", Meta = (BluePrintProtected))
	int32 max_ap;

	// The speed AP will be generated
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player", Meta = (BluePrintProtected = "true"))
	float ap_generation_speed;
	
private:

	// The time since the last AP Increase 
	float since_ap_incr;

};
