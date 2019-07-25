// Copywrite New Gaea Entertainment


#include "Public/TankTurret.h"

void UTankTurret::Turn(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw+ RotationChange;
	auto Rotation = FMath::Clamp<float>(RawNewRotation, -360, 360);
	SetRelativeRotation(FRotator(0, Rotation, 0));
}
