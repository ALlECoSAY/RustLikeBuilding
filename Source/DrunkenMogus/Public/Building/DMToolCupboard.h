// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "WorldObjects/SMStaticWorldObject.h"
#include "DMToolCupboard.generated.h"

class AFoundationBuildingNode;

UCLASS()
class DRUNKENMOGUS_API ADMToolCupboard : public ASMStaticWorldObject
{
	GENERATED_BODY()

public:
	ADMToolCupboard();
	
	virtual void Tick(float DeltaTime) override;

#pragma region GET/SET

	FORCEINLINE AFoundationBuildingNode* GetFoundationBuildingNode() const { return FoundationBuildingNode; }
	FORCEINLINE void SetFoundationBuildingNode(AFoundationBuildingNode* Value) { FoundationBuildingNode = Value; }
	
#pragma endregion

	
protected:
	virtual void BeginPlay() override;


protected:

	UPROPERTY()
	TObjectPtr<AFoundationBuildingNode> FoundationBuildingNode;
	
};
