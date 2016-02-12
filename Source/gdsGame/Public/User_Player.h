// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Player_Interface.h"
#include "User_Player.generated.h"

/**
 * 
 */
UCLASS()
class GDSGAME_API AUser_Player : public APlayer_Interface
{
	GENERATED_BODY()

public:
	AUser_Player();

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	float delay_;
	float timer_;
	bool can_press_;
 
};
