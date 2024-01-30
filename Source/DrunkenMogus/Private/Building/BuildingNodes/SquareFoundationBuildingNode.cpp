// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/BuildingNodes/SquareFoundationBuildingNode.h"


// Sets default values
ASquareFoundationBuildingNode::ASquareFoundationBuildingNode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASquareFoundationBuildingNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquareFoundationBuildingNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

