// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Building/UtilsBuilding.h"
#include "WorldObjects/SMStaticWorldObject.h"
#include "BuildingNode.generated.h"

class AStaticMeshActor;
class ABuildingNode;

USTRUCT(BlueprintType, Blueprintable)
struct FBuildingNodeResourceCost
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EResource"))
	int32 ConstructionCost[(uint8)(EResource::MAX)];
	
	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EResource"))
	int32 MaintenanceCost[(uint8)(EResource::MAX)];

	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EResource"))
	int32 RepairCost[(uint8)(EResource::MAX)];
	
};


USTRUCT(BlueprintType, Blueprintable)
struct FBuildingNodeInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EBuildingNode BuildingNodeType;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABuildingNode> BuildingNodeClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AStaticMeshActor> BlueprintBuildingNodeClass;

	UPROPERTY(EditAnywhere)
	float MaxSnappingRadius = 0.0f;

	UPROPERTY(EditAnywhere, meta = (ArraySizeEnum = "EBuildingGrade"))
	FBuildingNodeResourceCost BuildingNodeResourceCost[(uint8)EBuildingGrade::MAX];

};


UCLASS(Abstract, Blueprintable, BlueprintType)
class DRUNKENMOGUS_API ABuildingNode : public ASMStaticWorldObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingNode();

#pragma region GET/SET

	FORCEINLINE EBuildingNode GetBuildingNodeType() const { return BuildingNodeType; }
	FORCEINLINE EBuildingGrade GetBuildingGradeType() const { return BuildingGradeType; }
	
#pragma endregion
	

protected:
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	


	

public:

	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|Info", meta = (AllowPrivateAccess = "true"))
	EBuildingNode BuildingNodeType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|Info", meta = (AllowPrivateAccess = "true"))
	EBuildingGrade BuildingGradeType;

#pragma region Debug
public:
#if WITH_EDITOR
	// DebugDraw	
	void Debug_Draw(float Time = -1.0f) const;
	void Debug_DrawSnapSockets(TArray<UStaticMeshSocket*>* Sockets) const;
	void Debug_DrawAnchorSockets(TArray<UStaticMeshSocket*>* Sockets) const;
#endif
#if WITH_EDITORONLY_DATA

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Debug, meta = (AllowPrivateAccess = "true"))
	bool bDebug = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug|Advanced", meta = (AllowPrivateAccess = "true"))
	bool bDebugDrawAnchorSockets = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug|Advanced", meta = (AllowPrivateAccess = "true"))
	bool bDebugDrawSnapSockets = true;
	
#endif
#pragma endregion

};
