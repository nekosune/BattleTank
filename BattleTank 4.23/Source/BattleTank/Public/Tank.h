// Copywrite New Gaea Entertainment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

protected:
	void BeginPlay() override;
private:
	// Sets default values for this pawn's properties
	ATank();
};
