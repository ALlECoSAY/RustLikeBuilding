// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "DMGameMode.h"
#include "OpenWorldDMGameMode.generated.h"


class UBuildingGraph;
/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API AOpenWorldDMGameMode : public ADMGameMode
{
	GENERATED_BODY()


public:

	


protected:


	UPROPERTY()
	TArray<TObjectPtr<UBuildingGraph>> BuildingGraphs;

	
};
