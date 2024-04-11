
#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingNodes/BuildingNode.h"
#include "SnapSocket.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FSnapSocket
{
	GENERATED_BODY()

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	EBuildingNode BuildingNodeType;
};