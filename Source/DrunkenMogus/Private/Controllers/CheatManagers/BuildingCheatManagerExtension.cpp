// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Controllers/CheatManagers/BuildingCheatManagerExtension.h"

#include "Building/BuildingNodes/BuildingNode.h"
#include "Kismet/GameplayStatics.h"

void UBuildingCheatManagerExtension::DrawDebugBuildingNode(int32 bEnableDebug)
{

	TArray<AActor*> BuildingNodes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildingNode::StaticClass(), BuildingNodes);

	for (const auto BuildingNode : BuildingNodes)
	{
		ABuildingNode* Node = CastChecked<ABuildingNode>(BuildingNode);
		Node->bDebug = (bool)bEnableDebug;
	}
	
}
