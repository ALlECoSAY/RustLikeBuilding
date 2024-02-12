// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DMGameState.generated.h"


class UBuildingGraph;
/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API ADMGameState : public AGameState
{
	GENERATED_BODY()



private:

	UPROPERTY()
	TArray<TObjectPtr<UBuildingGraph>> BuildingGraphs;

	
};
