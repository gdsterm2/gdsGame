// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateWidgetStyleContainerBase.h"
#include "SlateWidgetStyle.h"
#include "SlateBasics.h"
#include "GlobalHUDStyle.generated.h"

// Provides a group of global style settings for our game
USTRUCT()
struct FGlobalStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	// Stores a list of slate brushes we are using
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;

	// Stores the typename for our widget style
	static const FName TypeName;

	// Retrieves the type name for our global style, which will be used by our style set to load the right file
	virtual const FName GetTypeName() const override;

	// Allows us to set default values for our various styles
	static const FGlobalStyle& GetDefault();
	
	// Style that defines the appearance of all HUD buttons
	UPROPERTY(EditAnywhere, Category = "Appearance")
	FButtonStyle HUDButtonStyle;

	// Style that defines all text on our HUD buttons
	UPROPERTY(EditAnywhere, Category = "Appearance")
	FTextBlockStyle HUDButtonTextStyle;
};


// Provides a widget style container to allow us to edit properties in-editor
UCLASS(hideCategories = Object, MinimalAPI)
class UGlobalHUDStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_UCLASS_BODY()

public:
	// This is our actual style object
	UPROPERTY(EditAnywhere, Category = "Appearance", meta = (ShowOnlyInnerProperties))
	FGlobalStyle HUDStyle;

	// Retrieves the style that this container manages
	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast<const struct FSlateWidgetStyle*>(&HUDStyle);
	}
};