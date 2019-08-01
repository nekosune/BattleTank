// Copywrite New Gaea Entertainment


#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetPawn();
	//this->bCanEverTick = true;
	if(!ensure(ControlledTank))
	{
		return;
	}
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if(ensure(AimingComponent))
		FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::AimTowardsCrosshair() const
{
	if(!GetPawn())
	{
		return;
	}
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent))
		return;
	FVector HitLocation; // Out Parameter
	bool bGotSight = GetSightRayHitLocation(HitLocation);
	UE_LOG(LogTemp, Warning, TEXT("Hit something: %i"), bGotSight);
	if(bGotSight)
	{
		AimingComponent->AimAt(HitLocation);
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

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		
		return GetLookVectorHitLocation(LookDirection, HitLocation);
		
	}
	
	return false;
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


