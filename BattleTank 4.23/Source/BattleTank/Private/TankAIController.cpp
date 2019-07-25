// Copywrite New Gaea Entertainment

#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank.h"


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto pawn=GetWorld()->GetFirstPlayerController()->GetPawn();
	if(pawn!=nullptr)
	{
		return Cast<ATank>(pawn);
	}
	return nullptr;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController not found Player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player %s"), *ControlledTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTicks)
{
	Super::Tick(DeltaTicks);
	if(GetControlledTank() && GetPlayerTank())
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}
