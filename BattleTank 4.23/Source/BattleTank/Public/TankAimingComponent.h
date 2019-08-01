// Copywrite New Gaea Entertainment

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"

// Enums
UENUM()
enum class EFiringStatus :uint8
{
	Reloading,
	Aiming,
	Locked
};
/// Forward declerations
class UTankBarrel;
class UTankTurret;
class AProjectile;
// Holds Parameters for barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// TODO: Add Turret reference

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTurret* TankTurretToSet, UTankBarrel* TankBarrelToSet);
	
	void AimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Fire();
	bool IsBarrelMoving();
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void BeginPlay() override;
	EFiringStatus GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category="State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
private:
	UTankBarrel* Barrel=nullptr;
	UTankTurret* Turret = nullptr;
	FVector AimDirection=FVector::ForwardVector;
	
	void MoveBarrelTowards(const FVector& AimDirection);
	double LastFireTime = 0;


	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000.0f;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	
};
