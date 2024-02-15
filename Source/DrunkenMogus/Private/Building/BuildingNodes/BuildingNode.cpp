// Fill out your copyright notice in the Description page of Project Settings.


#include "Building/BuildingNodes/BuildingNode.h"

#include "Engine/StaticMeshSocket.h"
#include "GameInstances/DMGameInstance.h"

// Sets default values
ABuildingNode::ABuildingNode()
{
	
	
}


float ABuildingNode::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
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

	//get anchor sockets by tag
	const TArray<UStaticMeshSocket*> CenterSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(GameInst->GetSocketNameByType(EBuildingSocketType::Center).ToString());
	const TArray<UStaticMeshSocket*> SideSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(GameInst->GetSocketNameByType(EBuildingSocketType::Side).ToString());
	const TArray<UStaticMeshSocket*> CornerSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(GameInst->GetSocketNameByType(EBuildingSocketType::Corner).ToString());

	TArray<UStaticMeshSocket*> AllAnchorSockets[(uint8)EBuildingSocketType::MAX] = {CenterSockets, SideSockets, CornerSockets};

	if (bDebugDrawAnchorSockets)
	{
		Debug_DrawAnchorSockets(AllAnchorSockets);
	}

	//get snap sockets by tag
	const TArray<UStaticMeshSocket*> WallSnapSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(EnumHelpers::EnumToString(EBuildingNode::Wall));
	const TArray<UStaticMeshSocket*> SquareFoundationSnapSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(EnumHelpers::EnumToString(EBuildingNode::SquareFoundation));
	const TArray<UStaticMeshSocket*> TriangleFoundationSnapSockets = GetStaticMeshComponent()->GetStaticMesh()->GetSocketsByTag(EnumHelpers::EnumToString(EBuildingNode::TriangleFoundation));

	TArray<UStaticMeshSocket*> AllSnapSockets[(uint8)EBuildingNode::MAX] = {WallSnapSockets, SquareFoundationSnapSockets, TriangleFoundationSnapSockets};
	
	if (bDebugDrawSnapSockets)
	{
		Debug_DrawSnapSockets(AllSnapSockets);
	}

	
}

void ABuildingNode::Debug_DrawSnapSockets(TArray<UStaticMeshSocket*>* Sockets) const
{
	for ( int i = 0; i < (uint8)EBuildingNode::MAX; ++i)
	{
		for (const auto& Socket : Sockets[i])
		{
			const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
			DrawDebugSphere(GetWorld(), SocketLocation, 5.0f, 6, FColor::Magenta, false, 0, 1, 2.f);
			DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
		}
	}
	
}

void ABuildingNode::Debug_DrawAnchorSockets(TArray<UStaticMeshSocket*>* Sockets) const
{
	for (const auto& Socket : Sockets[(uint8)EBuildingSocketType::Center])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
		DrawDebugSphere(GetWorld(), SocketLocation, 15.0f, 12, FColor::Red, false, 0, 1, 2.f);
		DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
		
	}

	for (const auto& Socket : Sockets[(uint8)EBuildingSocketType::Side])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
		DrawDebugSphere(GetWorld(), SocketLocation, 10.0f, 12, FColor::Green, false, 0, 1, 1.5f);
		DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
		
	}

	for (const auto& Socket : Sockets[(uint8)EBuildingSocketType::Corner])
	{
		const FVector SocketLocation = Socket->RelativeLocation + GetActorLocation();
		DrawDebugSphere(GetWorld(), SocketLocation, 7.0f, 12, FColor::Blue, false, 0, 1, 1.f);
		DrawDebugString(GetWorld(), SocketLocation, Socket->Tag, nullptr, FColor::Black, 0, false, 0.75f);
	}
}

#endif


