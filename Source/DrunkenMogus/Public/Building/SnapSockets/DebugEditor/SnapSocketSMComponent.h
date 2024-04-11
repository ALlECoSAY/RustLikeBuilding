// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingNodes/BuildingNode.h"

#include "SnapSocketSMComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class DRUNKENMOGUS_API USnapSocketSMComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	virtual int32 GetAvailableSocketsBitmask() const {PURE_VIRTUAL();return 0;};

	UPROPERTY(EditAnywhere, Category = SnapSockets)
	EBuildingNode BuildingNodeType;
	
};
