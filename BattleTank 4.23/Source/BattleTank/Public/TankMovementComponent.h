// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;



/**
 * Responsible for driving the tank Tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category="Input")
		void IntendMoveForward(float Throw);

		UFUNCTION(BlueprintCallable, Category = "Input")
			void IntendMoveRight(float Throw);

		UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTrack* LeftTrackToSet, UTankTrack*  RightTrackToSet);

		

private:
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;


	
};
