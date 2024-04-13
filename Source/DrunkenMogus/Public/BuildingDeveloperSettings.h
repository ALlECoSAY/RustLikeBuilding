// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Building/UtilsBuilding.h"
#include "Engine/DeveloperSettings.h"
#include "BuildingDeveloperSettings.generated.h"

struct FBuildingNodeInfo;
/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Building System"))
class DRUNKENMOGUS_API UBuildingDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	virtual void PostInitProperties() override;
	
public:
	
	FBuildingNodeInfo* GetBuildingNodeInfo(EBuildingNode Type) const;

	FORCEINLINE FName GetSocketNameByType(EBuildingSocketType Type) const { return SocketTypeToFName[Type]; }
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = Building)
	TSoftObjectPtr<UDataTable> BuildingDataTable;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = Building)
	EBuildingNode DefaultBuildingNode;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = Building)
	TMap<EBuildingSocketType,FName> SocketTypeToFName;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = Building)
	TMap<EBuildingNode,FName> BuildingNodeToFName;
	
	
};
