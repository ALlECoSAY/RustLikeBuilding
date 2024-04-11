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

	FORCEINLINE FName GetSocketNameByType(EBuildingSocketType Type) const { return SocketTypeToFName[Type]; }
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<UDataTable> BuildingDataTable;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|Meshes|Sockets", meta = (AllowPrivateAccess = "true"))
	TMap<EBuildingSocketType,FName> SocketTypeToFName;

	
};
