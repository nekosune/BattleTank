// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

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
