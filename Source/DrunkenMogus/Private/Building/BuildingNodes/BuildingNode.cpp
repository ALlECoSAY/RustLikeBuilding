// Fill out your copyright notice in the Description page of Project Settings.


#include "Building/BuildingNodes/BuildingNode.h"

// Sets default values
ABuildingNode::ABuildingNode()
{
	
	
}


// Called when the game starts or when spawned
void ABuildingNode::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	
}

void ABuildingNode::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
}

void ABuildingNode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

#if WITH_EDITOR

	if (bDrawDebugAnchors)
	{
		Debug_DrawAnchorSockets(0);	
	}
	
#endif

	
}


#if WITH_EDITOR
void ABuildingNode::Debug_DrawAnchorSockets(float Time)
{
	/*// drawdebug doesn't work with -1 time persistent lines for some reason
	if (Time!=0)
	{
		Time = TNumericLimits<float>::Max();
	}
	*/

	//todo: optional add engine only debug visual components and update in OnConstruction()
	
	//get sockets
	TArray<FName> SocketNames = GetStaticMeshComponent()->GetAllSocketNames();

	for (auto& SocketName : SocketNames)
	{
		FVector SocketLocation = GetStaticMeshComponent()->GetSocketLocation(SocketName);
		DrawDebugSphere(GetWorld(), SocketLocation, 15.0f, 12, FColor::Red, false, Time, 0, 1.5f);
		//Subscribe text
		DrawDebugString(GetWorld(), SocketLocation, SocketName.ToString(), nullptr, FColor::Red, Time, false, 0.75f);

	}
}
#endif


