// Copywrite New Gaea Entertainment

#include "Public/Tank.h"
#include "Engine/World.h"


void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}