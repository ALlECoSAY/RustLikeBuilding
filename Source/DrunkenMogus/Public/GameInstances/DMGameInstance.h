// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Building/UtilsBuilding.h"
#include "Engine/GameInstance.h"
#include "DMGameInstance.generated.h"

struct FBuildingNodeInfo;
/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API UDMGameInstance : public UGameInstance
{
	GENERATED_BODY()


protected:
	virtual void Init() override;

	


public:

#pragma region GET/SET

	FORCEINLINE TObjectPtr<UDataTable> GetBuildingDataTable() const { return BuildingDataTable; }
	FORCEINLINE FName GetSocketNameByType(EBuildingSocketType Type) const { return SocketTypeToFName[Type]; }
	FORCEINLINE FBuildingNodeInfo* GetBuildingNodeInfo(EBuildingNode Type) const { return BuildingNodesInfos[(uint8)Type]; }
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|Meshes|Sockets", meta = (AllowPrivateAccess = "true"))
	TMap<EBuildingSocketType,FName> SocketTypeToFName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> BuildingDataTable;

	FBuildingNodeInfo* BuildingNodesInfos[(uint8)EBuildingNode::MAX];


};
