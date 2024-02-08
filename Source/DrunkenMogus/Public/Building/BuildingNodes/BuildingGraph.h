// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BuildingGraph.generated.h"

class ABuildingNode;
/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API UBuildingGraph : public UObject
{
	GENERATED_BODY()


public:
	
	UPROPERTY()
	TArray<TObjectPtr<ABuildingNode>> Nodes;
	
};
