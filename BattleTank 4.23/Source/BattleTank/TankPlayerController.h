// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.333333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	
	ATank* GetControlledTank() const;

	void BeginPlay() override;
	void AimTowardsCrosshair() const;
	void Tick(float) override;
	bool GetSightRayHitLocation(FVector&  OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector,FVector&) const;
};
