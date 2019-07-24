// Copywrite New Gaea Entertainment


#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	//this->bCanEverTick = true;
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"),*ControlledTank->GetName());
	}
	
}

void ATankPlayerController::AimTowardsCrosshair() const
{
	if (!GetControlledTank())
		return;
	FVector HitLocation; // Out Parameter
	if(GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	const auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		
		if(GetLookVectorHitLocation(LookDirection, HitLocation))
		{
			
		}
		
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraLocation, 
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector Direction,FVector& HitLocation) const
{
	FHitResult HitResult;
	auto startPos = PlayerCameraManager->GetCameraLocation();
	auto endPos = startPos + (Direction * LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		startPos, 
		endPos, 
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
	
}


