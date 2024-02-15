// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldObject.h"
#include "StaticWorldObject.generated.h"

UCLASS()
class DRUNKENMOGUS_API AStaticWorldObject : public AWorldObject
{
	GENERATED_BODY()

public:
	AStaticWorldObject();

protected:
	virtual void BeginPlay() override;


protected:

	/**
	 * Root World Actor to which this* is attached
	 * Used to unlink from the root it in case of destruction
	 */
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AActor> RootActor;

	
	
	
};
