// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/BuildingNodes/BuildingGraph.h"

#include "Building/BuildingNodes/BuildingNode.h"
#include "GameInstances/DMGameInstance.h"

const int32* UBuildingGraph::UpdateFromCurrentTotalMaintenanceCost()
{
	for (int32 i = 0; i < Nodes.Num(); i++)
	{
		TotalMaintenanceCost[i] = 0;
	}

	const auto GameInstance = CastChecked<UDMGameInstance>(GetWorld()->GetGameInstance());

	for (const auto Node : Nodes)
	{
		const FBuildingNodeInfo* NodeInfo = GameInstance->GetBuildingNodeInfo(Node->GetBuildingNodeType());
		const EBuildingGrade Grade = Node->GetBuildingGradeType();

		const auto NodeMaintenanceCost = NodeInfo->BuildingNodeResourceCost[(uint8)Grade].MaintenanceCost; 

		for (int32 i = 0; i < (uint8)EResource::MAX; i++)
		{
			TotalMaintenanceCost[i] += NodeMaintenanceCost[i];
		}
	}

	return TotalMaintenanceCost;
}

const int32* UBuildingGraph::UpdateTotalMaintenanceCost(ABuildingNode* Node, bool bAdd)
{
	//get gameinstance

	const auto GameInstance = CastChecked<UDMGameInstance>(GetWorld()->GetGameInstance());
	
	const int32 mod = bAdd * -1;

	const FBuildingNodeInfo* NodeInfo = GameInstance->GetBuildingNodeInfo(Node->GetBuildingNodeType());
	const EBuildingGrade Grade = Node->GetBuildingGradeType();

	const auto NodeMaintenanceCost = NodeInfo->BuildingNodeResourceCost[(uint8)Grade].MaintenanceCost; 

	for (int32 i = 0; i < (uint8)EResource::MAX; i++)
	{
		TotalMaintenanceCost[i] += NodeMaintenanceCost[i] * mod;
	}

	return TotalMaintenanceCost;	
}

