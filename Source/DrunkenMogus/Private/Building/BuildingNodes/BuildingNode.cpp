// Fill out your copyright notice in the Description page of Project Settings.


#include "Building/BuildingNodes/BuildingNode.h"

#include "Engine/StaticMeshSocket.h"
#include "GameInstances/DMGameInstance.h"

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


void ABuildingNode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

#if WITH_EDITOR

	if (bDebug)
	{
		Debug_Draw(0);	
	}
	
#endif

	
}


#if WITH_EDITOR
void ABuildingNode::Debug_Draw(float Time) const
{
	
	const auto GameInst = CastChecked<UDMGameInstance>(GetGameInstance());

	//get sockets by tag
	const TArray<UStaticMeshSocket*> CenterSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(GameInst->GetSocketNameByType(EBuildingSocketType::Center).ToString());
	const TArray<UStaticMeshSocket*> SideSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(GameInst->GetSocketNameByType(EBuildingSocketType::Side).ToString());
	const TArray<UStaticMeshSocket*> CornerSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(GameInst->GetSocketNameByType(EBuildingSocketType::Corner).ToString());

	TArray<UStaticMeshSocket*> AllSockets[(uint8)EBuildingSocketType::MAX] = {CenterSockets, SideSockets, CornerSockets};

	if (bDebugDrawAnchorSocketsSpheres)
	{
		Debug_DrawAnchorSocketsSpheres(AllSockets);
	}

	if (bDebugDrawAnchorSocketsText)
	{
		Debug_DrawAnchorSocketsText(AllSockets);
	}	
}

void ABuildingNode::Debug_DrawAnchorSocketsSpheres(TArray<UStaticMeshSocket*>* Sockets) const
{
	for (auto& Socket : Sockets[(uint8)EBuildingSocketType::Center])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
		DrawDebugSphere(GetWorld(), SocketLocation, 15.0f, 12, FColor::Red, false, 0, 1, 2.f);
		
	}

	for (auto& Socket : Sockets[(uint8)EBuildingSocketType::Side])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
		DrawDebugSphere(GetWorld(), SocketLocation, 10.0f, 12, FColor::Green, false, 0, 1, 1.5f);
		
	}

	for (auto& Socket : Sockets[(uint8)EBuildingSocketType::Corner])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
		DrawDebugSphere(GetWorld(), SocketLocation, 7.0f, 12, FColor::Blue, false, 0, 1, 1.f);
	}
}

void ABuildingNode::Debug_DrawAnchorSocketsText(TArray<UStaticMeshSocket*>* Sockets) const
{
	for (auto& Socket : Sockets[(uint8)EBuildingSocketType::Center])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
			DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
	}

	for (auto& Socket : Sockets[(uint8)EBuildingSocketType::Side])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
			DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
	}

	for (auto& Socket : Sockets[(uint8)EBuildingSocketType::Corner])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
			DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
	}
}
#endif


