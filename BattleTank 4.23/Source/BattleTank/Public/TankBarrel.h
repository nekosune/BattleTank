// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * hidecategories=("Collision")
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 10;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationInDegrees = 40;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationInDegrees = 0;
};
