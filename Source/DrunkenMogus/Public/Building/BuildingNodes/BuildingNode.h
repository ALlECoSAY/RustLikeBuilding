// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Building/UtilsBuilding.h"
#include "WorldObjects/SMStaticWorldObject.h"
#include "BuildingNode.generated.h"

class ABuildingNode;

USTRUCT(BlueprintType, Blueprintable)
struct FBuildingNodeResourceCost
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EResourceType"))
	int32 BuildingCost[(uint8)(EResourceType::MAX)];
	
	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EResourceType"))
	int32 MaintenanceCost[(uint8)(EResourceType::MAX)];

	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EResourceType"))
	int32 RepairCost[(uint8)(EResourceType::MAX)];
	
};


USTRUCT(BlueprintType, Blueprintable)
struct FBuildingNodeInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EBuildingNodeType BuildingNodeType;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABuildingNode> BuildingNodeClass;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> ActualStaticMeshComponent;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BlueprintStaticMeshComponent;

	UPROPERTY(EditAnywhere)
	float MaxSnappingRadius = 0.0f;

	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EBuildingGradeType"))
	FBuildingNodeResourceCost ConstructionResourceCost[(uint8)EBuildingGradeType::MAX];

};


UCLASS(Abstract, Blueprintable, BlueprintType)
class DRUNKENMOGUS_API ABuildingNode : public ASMStaticWorldObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingNode();

#pragma region GET/SET


	
#pragma endregion
	

protected:
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	
#if WITH_EDITOR
	// DebugDraw
	void Debug_Draw(float Time = -1.0f) const;
	void Debug_DrawAnchorSocketsSpheres(TArray<UStaticMeshSocket*>* Sockets) const;
	void Debug_DrawAnchorSocketsText(TArray<UStaticMeshSocket*>* Sockets) const;
#endif

	

public:

	
protected:

	
	

#if WITH_EDITORONLY_DATA

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Debug, meta = (AllowPrivateAccess = "true"))
	bool bDebug = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug|Advanced", meta = (AllowPrivateAccess = "true"))
	bool bDebugDrawAnchorSocketsSpheres = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug|Advanced", meta = (AllowPrivateAccess = "true"))
	bool bDebugDrawAnchorSocketsText = true;

	
#endif

	
};
