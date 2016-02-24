// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "SInGameUI.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "GlobalHUDStyle.h"
#include "HUDStyles.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInGameUI::Construct(const FArguments& InArgs)
{
	InGameHUD = InArgs._InGameHUD;
	HUDStyle = &FHUDStyles::Get().GetWidgetStyle<FGlobalStyle>("UI");

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&HUDStyle->HUDButtonStyle)
				.TextStyle(&HUDStyle->HUDButtonTextStyle)
				.Text(FText::FromString("Produce module 1"))
				.OnClicked(this, &SInGameUI::ProduceResourcePress, 0)
			]
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&HUDStyle->HUDButtonStyle)
				.TextStyle(&HUDStyle->HUDButtonTextStyle)
				.Text(FText::FromString("Spawn from module 1"))
				.OnClicked(this, &SInGameUI::SpawnMinionPress, 0)
			]
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&HUDStyle->HUDButtonStyle)
				.TextStyle(&HUDStyle->HUDButtonTextStyle)
				.Text(FText::FromString("Produce module 2"))
				.OnClicked(this, &SInGameUI::ProduceResourcePress, 1)
			]
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&HUDStyle->HUDButtonStyle)
				.TextStyle(&HUDStyle->HUDButtonTextStyle)
				.Text(FText::FromString("Spawn from module 2"))
				.OnClicked(this, &SInGameUI::SpawnMinionPress, 1)
			]
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&HUDStyle->HUDButtonStyle)
				.TextStyle(&HUDStyle->HUDButtonTextStyle)
				.Text(FText::FromString("Produce module 3"))
				.OnClicked(this, &SInGameUI::ProduceResourcePress, 2)
			]
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&HUDStyle->HUDButtonStyle)
				.TextStyle(&HUDStyle->HUDButtonTextStyle)
				.Text(FText::FromString("Spawn from module 3"))
				.OnClicked(this, &SInGameUI::SpawnMinionPress, 2)
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FReply SInGameUI::ProduceResourcePress(int32 module_num)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("ProduceResourcePressed"));
	}

	// Produce resource
	InGameHUD->GenerateResourcePressed(module_num);
	return FReply::Handled();
}

FReply SInGameUI::SpawnMinionPress(int32 module_num)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("SpawnMinionPressed"));
	}

	// Spawn minion
	InGameHUD->SpawnMinionPressed(module_num);
	return FReply::Handled();
}
	