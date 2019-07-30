// Copywrite New Gaea Entertainment


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forwaard, throw: %f"), Throw);
	if (!ensure(LeftTrack) || !ensure(RightTrack))
	{
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	if (!ensure(LeftTrack) || !ensure(RightTrack))
	{
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if(!ensure(LeftTrackToSet) || !ensure(RightTrackToSet))
	{
		return;
	}
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	
	IntendMoveForward(ForwardThrow);

	auto Cross = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendMoveRight(Cross.Z);
//	UE_LOG(LogTemp, Warning, TEXT("moving tank %s with vector %s"), *TankName,*AIForwardIntention.ToString());

}
