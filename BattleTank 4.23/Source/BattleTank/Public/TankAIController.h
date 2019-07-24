// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	void BeginPlay() override;
	void Tick(float) override;
};
