// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	// Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
		float TankMaxDrivingForce = 400000;

};
