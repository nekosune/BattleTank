// Copywrite New Gaea Entertainment


#include "Public/TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange ;
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationInDegrees, MaxDegreesPerSecond);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}
