// Copywrite New Gaea Entertainment

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
// Holds Parameters for barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// TODO: Add Turret reference


	
	void AimAt(FVector hitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

private:
	UTankBarrel* Barrel=nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(const FVector& AimDirection);
		
};
