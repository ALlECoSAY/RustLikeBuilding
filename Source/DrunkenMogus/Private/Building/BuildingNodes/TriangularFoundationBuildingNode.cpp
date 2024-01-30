// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/BuildingNodes/TriangularFoundationBuildingNode.h"


// Sets default values
ATriangularFoundationBuildingNode::ATriangularFoundationBuildingNode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATriangularFoundationBuildingNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriangularFoundationBuildingNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

