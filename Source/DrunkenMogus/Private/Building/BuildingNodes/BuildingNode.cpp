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
	/*// drawdebug doesn't work with -1 time persistent lines for some reason (reason: OnConstruction incompatibility)
	if (Time!=0)
	{
		Time = TNumericLimits<float>::Max();
	}
	*/

	//todo: optional add engine only debug visual components and update in OnConstruction()
	
	//get sockets
	/*TArray<FName> SocketNames = GetStaticMeshComponent()->GetAllSocketNames();

	for (auto& SocketName : SocketNames)
	{
		FVector SocketLocation = GetStaticMeshComponent()->GetSocketLocation(SocketName);
		DrawDebugSphere(GetWorld(), SocketLocation, 15.0f, 12, FColor::Red, false, Time, 0, 1.5f);
		//Subscribe text
		DrawDebugString(GetWorld(), SocketLocation, SocketName.ToString(), nullptr, FColor::Red, Time, false, 0.75f);
	}
	*/

	const auto ActorLocation = GetActorLocation();

	const auto GameInst = CastChecked<UDMGameInstance>(GetGameInstance());
	
	TMap<EBuildingSocketType, FName> SocketTypeToFName = GameInst->SocketTypeToFName;

	//get sockets by tag
	const TArray<UStaticMeshSocket*> CenterSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(SocketTypeToFName.Find(EBuildingSocketType::Center)->ToString());
	const TArray<UStaticMeshSocket*> SideSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(SocketTypeToFName.Find(EBuildingSocketType::Side)->ToString());
	const TArray<UStaticMeshSocket*> CornerSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(SocketTypeToFName.Find(EBuildingSocketType::Corner)->ToString());

	
	for (auto& Socket : CenterSockets)
	{
		FVector SocketLocation = Socket->RelativeLocation + ActorLocation;
		DrawDebugSphere(GetWorld(), SocketLocation, 15.0f, 12, FColor::Red, false, Time, 1, 2.f);
		//Subscribe text
		DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, Time, false, 0.75f);
	}

	for (auto& Socket : SideSockets)
	{
		FVector SocketLocation = Socket->RelativeLocation + ActorLocation;
		DrawDebugSphere(GetWorld(), SocketLocation, 10.0f, 12, FColor::Green, false, Time, 1, 1.5f);
		//Subscribe text
		DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, Time, false, 0.75f);
	}

	for (auto& Socket : CornerSockets)
	{
		FVector SocketLocation = Socket->RelativeLocation + ActorLocation;
		DrawDebugSphere(GetWorld(), SocketLocation, 7.0f, 12, FColor::Blue, false, Time, 1, 1.f);
		//Subscribe text
		DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, Time, false, 0.75f);
	}
	
}
#endif


