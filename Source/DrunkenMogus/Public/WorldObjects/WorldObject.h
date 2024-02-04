// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldObject.generated.h"

USTRUCT()
struct FPlacementSnappingInfo
{
	GENERATED_BODY(FPlacementSnappingInfo)

	bool bSnapped;
	FTransform Transform;	
	
};


UCLASS()
class DRUNKENMOGUS_API AWorldObject : public AActor
{
	GENERATED_BODY()

public:
	AWorldObject();



	
protected:
	virtual void BeginPlay() override;

	
protected:

	

};
