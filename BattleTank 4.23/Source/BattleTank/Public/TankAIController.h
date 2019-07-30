// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

		ATankAIController();
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float AcceptanceRadius = 3000;
private:
	void BeginPlay() override;
	void Tick(float) override;

	
};
