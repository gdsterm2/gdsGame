// Fill out your copyright notice in the Description page of Project Settings.

#include "gdsGame.h"
#include "Module.h"
#include "Minion.h"
#include "Engine.h"


// Sets default values
AModule::AModule(const class FObjectInitializer& PCIP) :
	Super(PCIP),
	action_timer_count_(0.0f),
	resource_bank_(0)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Get visual for module
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UPaperFlipbook> HexagonVisual;
		FConstructorStatics()
			: HexagonVisual(TEXT("/Game/Temp_assists/temp_homeBase_Flipbook.temp_homeBase_Flipbook"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;
	module_visual_ = ConstructorStatics.HexagonVisual.Get();
	GetSprite()->SetFlipbook(module_visual_);

}

// Called when the game starts or when spawned
void AModule::BeginPlay()
{
	Super::BeginPlay();
//	SpawnMinion();
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
void AModule::SpawnMinion()
{
	// If we have set something to spawn:
	if (MinionToSpawn != NULL)
	{
		// Check for a valid World: 
		UWorld* const World = GetWorld();

		if (World)
		{
			// Set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
		
			// TODO: add a location for the spawn 
			FVector SpawnLocation = FVector(0, 0, 0);

			// Make sure not rotated
			FRotator SpawnRotation = FRotator(0, 0, 0);

			// spawn the pickup
			AMinion* const SpawnMinion = World->SpawnActor<AMinion>(MinionToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

			minionSpawned.Add(SpawnMinion);
		}
	}
}

void AModule::TouchRecieved()
{
	touch_recieved_ = true;

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Touch recieved"));
}

void AModule::ProduceResource()
{
	// Check we aren't already producing resource
	if (!producing_resource_)
	{
		producing_resource_ = true;
	}
}

bool AModule::DeployResource() 
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

bool AModule::IsProducingResource() const
{
	return producing_resource_;
}

TSubclassOf<class AMinion> AModule::GetMinion() const
{
	return MinionToSpawn;
}

void AModule::SetTouchReceived(bool touch)
{
	touch_recieved_ = touch;
}

bool AModule::GetTouchReceived()
{
	return touch_recieved_;
}

