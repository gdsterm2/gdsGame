// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Player_Interface.h"
#include "AI_Player.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API AAI_Player : public APlayer_Interface
{
	GENERATED_BODY()
public:

	AAI_Player();
	~AAI_Player();

	virtual void Tick(float DeltaSeconds) override;

	
protected:

	void try_build_minions();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", Meta = (BluePrintProtected))
	float how_often_try_build;

private:

	int32 currentModTrying;

	float since_last_buid_try;

};
