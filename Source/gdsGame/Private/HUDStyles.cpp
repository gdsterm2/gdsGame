// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "HUDStyles.h"
#include "SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FHUDStyles::HUDStyleInstance = NULL;

void FHUDStyles::Initialize()
{
	if (!HUDStyleInstance.IsValid())
	{
		HUDStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*HUDStyleInstance);
	}
}

void FHUDStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*HUDStyleInstance);
	ensure(HUDStyleInstance.IsUnique());
	HUDStyleInstance.Reset();
}

FName FHUDStyles::GetStyleSetName()
{
	static FName StyleSetName(TEXT("HUDStyles"));
	return StyleSetName;
}

TSharedRef<FSlateStyleSet> FHUDStyles::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FHUDStyles::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");
	return StyleRef;
}

const ISlateStyle& FHUDStyles::Get()
{
	return *HUDStyleInstance;
}