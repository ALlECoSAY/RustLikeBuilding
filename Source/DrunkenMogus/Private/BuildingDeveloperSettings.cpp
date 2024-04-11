// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "BuildingDeveloperSettings.h"

#include "Building/BuildingNodes/BuildingNode.h"

void UBuildingDeveloperSettings::PostInitProperties()
{
	Super::PostInitProperties();


	//todo (mb excessive) preload load BuildingNodeInfo datatable

	
	/*//BuildingDataTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DrunkenMogus/DataTables/DT_BuildingNodeInfo.DT_BuildingNodeInfo'"));
	check(BuildingDataTable);
	
	FString Context = TEXT(__FUNCTION__);
	TArray<FBuildingNodeInfo*> OutRows;
	GetBuildingDataTable()->GetAllRows(Context, OutRows);

	
	check(OutRows.Num() == (uint8)EBuildingNode::MAX);
	
	auto BuildingTypeIterateCheck = 0;
	
	//Copy to the local array
	for (const auto Row : OutRows)
	{
		check(BuildingTypeIterateCheck == (uint8)Row->BuildingNodeType);
		BuildingNodesInfos[BuildingTypeIterateCheck]=Row;
		++BuildingTypeIterateCheck;
	}
	*/

	BuildingDataTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DrunkenMogus/DataTables/DT_BuildingNodeInfo.DT_BuildingNodeInfo'"));
}
