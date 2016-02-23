// Fill out your copyright notice in the Description page of Project Settings.
// Implementation of a HUD that will embed the in game slate UI

#pragma once

#include "GameFramework/HUD.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API AInGameHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	// Initializes the slate UI and adds it as widget content to the game viewport
	virtual void PostInitializeComponents() override;

public:
	void SetPlayer(class AUser_Player* player_ref);

	// Called by SInGame whenever the generate resource button is pressed
	//UFUNCTION(BlueprintImplementableEvent, Category = "InGameHUD")
	void GenerateResourcePressed(int32 module_num);

	// Called by SInGame whenever the spawn minion button is pressed
	//UFUNCTION(BlueprintImplementableEvent, Category = "InGameHUD")
	void SpawnMinionPressed(int32 module_num);

private:
	// Refrence to the in game slate UI
	TSharedPtr<class SInGameUI> InGameUI;

	// Refrence to the player
	class AUser_Player* player_ref_;
};
