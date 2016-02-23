// Fill out your copyright notice in the Description page of Project Settings.
// Implementation of the slate UI representing the in game button input

#pragma once

#include "SlateBasics.h"
#include "InGameHUD.h"
#include "Widgets/SCompoundWidget.h"


class GDSGAME_API SInGameUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInGameUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AInGameHUD>, InGameHUD)
	SLATE_END_ARGS()

	// Constructs and lays out the UI widget
	// args arguments structure that contains widget-specific setup info
	void Construct(const FArguments& InArgs);

	// Click handler for the produce resource button
	FReply ProduceResourcePress(int32 module_num);

	// Click handler for the spawn minion button
	FReply SpawnMinionPress(int32 module_num);

	// Stores a weak refrence to the HUD controlling this class
	TWeakObjectPtr<class AInGameHUD> InGameHUD;
};
