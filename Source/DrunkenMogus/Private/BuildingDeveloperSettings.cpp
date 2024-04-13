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

	//BuildingDataTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DrunkenMogus/DataTables/DT_BuildingNodeInfo.DT_BuildingNodeInfo'"));


	
}

FBuildingNodeInfo* UBuildingDeveloperSettings::GetBuildingNodeInfo(EBuildingNode Type) const
{
	FName BuildingNodeName = BuildingNodeToFName.FindRef(Type);  
	const auto Context = TEXT(__FUNCTION__);
	const auto Row = BuildingDataTable.LoadSynchronous()->FindRow<FBuildingNodeInfo>(BuildingNodeName, Context, true);
	check(Row);
	UE_LOG(LogTemp, Warning, TEXT("Row: %s"), *Row->BuildingNodeClass->GetName())
	return Row;
}
