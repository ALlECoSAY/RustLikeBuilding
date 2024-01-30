// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/BuildingNodes/WallSuperstructureBuildingNode.h"


// Sets default values
AWallSuperstructureBuildingNode::AWallSuperstructureBuildingNode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWallSuperstructureBuildingNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallSuperstructureBuildingNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

