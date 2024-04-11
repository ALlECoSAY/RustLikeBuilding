// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Building/UtilsBuilding.h"
#include "UObject/Object.h"
#include "BuildingGraph.generated.h"

class ADMToolCupboard;
class ABuildingNode;

/**
 * 
 */





UCLASS()
class DRUNKENMOGUS_API ABuildingGraph : public AActor
{
	GENERATED_BODY()

public:

	
public:

	UPROPERTY()
	TArray<TObjectPtr<ABuildingNode>> Nodes;
	
	UPROPERTY()
	TObjectPtr<ADMToolCupboard> ToolCupboard;

	
};
