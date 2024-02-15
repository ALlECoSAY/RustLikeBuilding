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


USTRUCT()
struct FBuildingGraphArc
{
	GENERATED_BODY()

	UPROPERTY()
	ABuildingNode* EndNode;

	UPROPERTY()
	EBuildingNode ArcType;
};




UCLASS()
class DRUNKENMOGUS_API UBuildingGraph : public UObject
{
	GENERATED_BODY()

public:

	// return TotalMaintenanceCost array
	FORCEINLINE const int32* GetTotalMaintenanceCost() const { return TotalMaintenanceCost; }

	const int32* UpdateFromCurrentTotalMaintenanceCost();

	const int32* UpdateTotalMaintenanceCost(ABuildingNode* Node, bool bAdd);
	
public:

	// All nodes in the graph
	UPROPERTY()
	TArray<TObjectPtr<ABuildingNode>> Nodes;

	
	TMultiMap<TObjectPtr<ABuildingNode>,TArray<FBuildingGraphArc>> Arcs;
	
	UPROPERTY()
	int32 TotalMaintenanceCost[(uint8)(EResource::MAX)];

	UPROPERTY()
	TObjectPtr<ADMToolCupboard> ToolCupboard;
		
	
};
