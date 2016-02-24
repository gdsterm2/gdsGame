// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "HUDStyles.h"

// Custom implementation of the default game module
class FgdsGameGameModule : public FDefaultGameModuleImpl
{
	// Called whenever the module is starting up. In here we unregister any style sets
	// (Which may have been added my other modules) sharing our
	// Style set's name, then initialize ours
	virtual void StartupModule() override
	{
		// Hot reload hack
		FSlateStyleRegistry::UnRegisterSlateStyle(FHUDStyles::GetStyleSetName());
		FHUDStyles::Initialize();
	}

	// Called whenever the module is shutting down. Here, we tell our HUD Style to shutdown
	virtual void ShutdownModule() override
	{
		FHUDStyles::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FgdsGameGameModule, gdsGame, "gdsGame" );
