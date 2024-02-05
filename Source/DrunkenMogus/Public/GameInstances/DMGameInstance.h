// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Building/UtilsBuilding.h"
#include "Engine/GameInstance.h"
#include "DMGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API UDMGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|Meshes|Sockets", meta = (AllowPrivateAccess = "true"))
	TMap<EBuildingSocketType,FName> SocketTypeToFName;

	


	
};
