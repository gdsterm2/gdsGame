// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "Module.h"


// Sets default values
AModule::AModule() :
	action_timer_count_(0.0f),
	resource_bank_(0)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cube = CreateDefaultSubobject<UBoxComponent>(TEXT("CUBE"));
}

// Called when the game starts or when spawned
void AModule::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AModule::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// If producing resouce
	if (producing_resource_)
	{
		// Increment resource timer count by delta time
		action_timer_count_ += DeltaTime;

		// Check if timer has been reached
		if (action_timer_count_ >= action_timer_)
		{
			// Increment resources and reset timer	
			action_timer_count_ = 0.0f;
			resource_bank_++;
			producing_resource_ = false;
		}
	}
}

// Called to bind functionality to input
void AModule::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AModule::ProduceResource()
{
	// Check we aren't already producing resource
	if (!producing_resource_)
	{
		producing_resource_ = true;
	}
}

bool AModule::DeployResource() const
{
	// Check we have resources to be deployed
	if (resource_bank_ > 0)
	{
		resource_bank_--;
		// Deploy was successful, return true
		return true;
	}
	else
	{
		// No resources to deploy, return false
		return false;
	}
}

float AModule::GetActionTimer() const
{
	return action_timer_;
}

float AModule::GetActionTimerCount() const
{
	return action_timer_count_;
}

int32 AModule::GetActionCost() const
{
	return action_cost_;
}

void AModule::SetResourceBank(int32 const resources)
{
	resource_bank_ = resources;
}

int32 AModule::GetResourceBank() const
{
	return resource_bank_;
}

void AModule::SetModuleType(ModuleType const type)
{
	module_type_ = type;

	// TODO(Rory) Update module appearance when type is updated
}

AModule::ModuleType AModule::GetModuleType() const
{
	return module_type_;
}

bool AModule::IsProducingResource() const
{
	return producing_resource_;
}
