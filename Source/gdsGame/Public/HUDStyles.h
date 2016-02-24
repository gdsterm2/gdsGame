// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"

/**
 * 
 */
class FHUDStyles
{
public:
	// Initilaizes the value of MenuStyleInstance 
	// and registers it with slate style registry
	static void Initialize();

	// Unregisters the slate style slate
	// and resets the MenuStyleInstance pointer
	static void Shutdown();

	// Retrieves a refrence to the slate style
	// pointed to by MenuStyleInstance
	static const class ISlateStyle& Get();

	// Retrieves the name of the style set
	static FName GetStyleSetName();

private:
	// Creates the style set
	static TSharedRef<class FSlateStyleSet> Create();

	// Singleton instance used for our style set
	static TSharedPtr<class FSlateStyleSet> HUDStyleInstance;
};
