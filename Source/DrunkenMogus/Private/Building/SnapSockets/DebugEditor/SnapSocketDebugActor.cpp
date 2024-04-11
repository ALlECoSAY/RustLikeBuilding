// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/SnapSockets/DebugEditor/SnapSocketDebugActor.h"

#include "Building/SnapSockets/DebugEditor/SnapSocketSMComponent.h"


// Sets default values
ASnapSocketDebugActor::ASnapSocketDebugActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	
}

void ASnapSocketDebugActor::BeginPlay()
{
	Super::BeginPlay();

}

void ASnapSocketDebugActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);


	FlushPersistentDebugLines(GetWorld());
	for (auto& SnapSocket : SnapSockets)
	{
		// draw debug sphere
		DrawDebugSphere(GetWorld(), SnapSocket->GetComponentLocation(), 10.f, 12, FColor::Red, true, -1);
		
	}
	
	
}


