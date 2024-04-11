// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "UtilsBuilding.h"
#include "WorldObjects/SMStaticWorldObject.h"
#include "DMToolCupboard.generated.h"

class ABuildingGraph;
class AFoundationBuildingNode;

UCLASS()
class DRUNKENMOGUS_API ADMToolCupboard : public ASMStaticWorldObject
{
	GENERATED_BODY()

public:
	ADMToolCupboard();
	
	virtual void Tick(float DeltaTime) override;

	
	
#pragma region GET/SET

	
#pragma endregion

	
protected:
	virtual void BeginPlay() override;



protected:

	UPROPERTY()
	TObjectPtr<ABuildingGraph> BuildingGraph;

	UPROPERTY()
	int32 MaintenanceCost[(uint8)(EResource::MAX)];
	
};
