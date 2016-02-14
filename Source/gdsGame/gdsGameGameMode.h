// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "User_Player.h"
#include "AI_Player.h"
#include "Minion_interface.h"
#include "gdsGameGameMode.generated.h"

// Enum to store the current stae of gameplay
UENUM(BlueprintType)
enum class EGame_state
{
	ELoading,
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};



/**
 * 
 */
UCLASS()
class GDSGAME_API AgdsGameGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
	virtual void Tick(float DeltaTimer) override;

	virtual void BeginPlay() override;


public:
	AgdsGameGameMode(const class FObjectInitializer& ObjectInitializer);
	/* Returns the current state
		@Prams:
		@Rurns: Current Game state
	*/
	UFUNCTION(BlueprintPure, Category = "State")
	EGame_state GetCurrentState() const;

	/*Sets a new sate
		@Prams: The new game state
		@Rurns: 
	*/
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetCurrentState(EGame_state newState);

protected:

	/* Will load a new level */
	UFUNCTION(BlueprintCallable, Category = "Game")
	void BuildLevel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TSubclassOf<AUser_Player> user_player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =  "Game")
	TSubclassOf<AAI_Player> ai_player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TSubclassOf<AMinion_interface> minion_controller_;

private:

	EGame_state current_state;
	
	AActor* cam;

};
