// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "InGameHUD.h"
#include "SInGameUI.h"
#include "Engine.h"

AInGameHUD::AInGameHUD(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void AInGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(InGameUI, SInGameUI).InGameHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(InGameUI.ToSharedRef()));
	}
}

void AInGameHUD::GenerateResourcePressed()
{

}

void AInGameHUD::SpawnMinionPressed()
{

}


