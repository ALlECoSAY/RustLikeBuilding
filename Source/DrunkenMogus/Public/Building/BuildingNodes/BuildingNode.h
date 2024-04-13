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

	UPROPERTY(EditAnywhere)
	TMap<EResource,uint32> ConstructionCost;
	
	UPROPERTY(EditAnywhere)
	TMap<EResource,uint32> MaintenanceCost;

	UPROPERTY(EditAnywhere)
	TMap<EResource,uint32> RepairCost;
	
};


USTRUCT(BlueprintType, Blueprintable)
struct FBuildingNodeInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EBuildingNode BuildingNodeType = EBuildingNode::MAX;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABuildingNode> BuildingNodeClass = nullptr;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AStaticMeshActor> BlueprintBuildingNodeClass = nullptr;

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

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	

	
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
