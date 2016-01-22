// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "gdsGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API AgdsGameGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
	virtual void Tick(float DeltaTimer) override;
	
	
};
