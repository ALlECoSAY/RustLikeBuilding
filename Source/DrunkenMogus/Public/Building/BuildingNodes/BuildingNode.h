// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldObjects/SMStaticWorldObject.h"
#include "BuildingNode.generated.h"

class ABuildingNode;

USTRUCT(BlueprintType, Blueprintable)
struct FBuildingNodeInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABuildingNode> BuildingNodeClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Preview", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> ActualStaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Preview", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> BlueprintStaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MaxSnappingRadius = 0.0f;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//float MinSnappingRadius = 0.0f; //if not 0, then does sphere trace
	
	// Cost of building this node
	// Cost of maintaining this node
	//TArray<UBuildingResource>

	//

	
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
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;
	
	virtual void Tick(float DeltaSeconds) override;
	
#if WITH_EDITOR
	// DebugDrawAnchorPoints
	void Debug_DrawAnchorSockets(float Time = -1.0f); 
#endif

	

public:

	
protected:

	
	

#if WITH_EDITORONLY_DATA

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Debug, meta = (AllowPrivateAccess = "true"))
	bool bDrawDebugAnchors = false;
	
#endif

	
};
