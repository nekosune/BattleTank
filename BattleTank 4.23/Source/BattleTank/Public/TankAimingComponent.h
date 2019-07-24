// Copywrite New Gaea Entertainment

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// TODO: Add Turret reference

	void AimAt(FVector hitLocation, float LaunchSpeed);
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:
	UStaticMeshComponent* Barrel=nullptr;
	void MoveBarrelTowards(const FVector& AimDirection);
		
};
