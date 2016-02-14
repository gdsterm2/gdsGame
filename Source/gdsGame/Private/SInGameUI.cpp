// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "SInGameUI.h"
#include "SlateOptMacros.h"
#include "Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInGameUI::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Bottom)
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("Produce Resource"))
				.OnClicked(this, &SInGameUI::ProduceResourcePressed)
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("Spawn Minion"))
				.OnClicked(this, &SInGameUI::SpawnMinionPressed) 
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FReply SInGameUI::ProduceResourcePressed()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("ProduceResourcePressed"));
	}

	// Produce resource
	InGameHUD->ProduceResourcePressed();
	return FReply::Handled();
}

FReply SInGameUI::SpawnMinionPressed()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("SpawnMinionPressed"));
	}

	// Spawn minion
	InGameHUD->SpawnMinionPressed();
	return FReply::Handled();
}
	