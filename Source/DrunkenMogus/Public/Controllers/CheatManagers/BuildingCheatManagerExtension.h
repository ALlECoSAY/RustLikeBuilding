// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "BuildingCheatManagerExtension.generated.h"

/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API UBuildingCheatManagerExtension : public UCheatManagerExtension
{
	GENERATED_BODY()


	UFUNCTION(Exec)
	void DrawDebugBuildingNode(int32 bEnableDebug);
	

	
};
