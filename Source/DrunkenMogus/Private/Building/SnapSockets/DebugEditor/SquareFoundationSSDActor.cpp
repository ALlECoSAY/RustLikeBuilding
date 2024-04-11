// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/SnapSockets/DebugEditor/SquareFoundationSSDActor.h"

#include "Building/SnapSockets/DebugEditor/SnapSocketSMComponent.h"
#include "Building/SnapSockets/DebugEditor/SquareFoundationSSSMComponent.h"


// Sets default values
ASquareFoundationSSDActor::ASquareFoundationSSDActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	SquareFoundation0 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("SquareFoundation0"));
	SquareFoundation0->SetupAttachment(RootComponent);
	SnapSockets.Add(SquareFoundation0);
	SquareFoundation1 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("SquareFoundation1"));
	SquareFoundation1->SetupAttachment(RootComponent);
	SnapSockets.Add(SquareFoundation1);
	SquareFoundation2 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("SquareFoundation2"));
	SquareFoundation2->SetupAttachment(RootComponent);
	SnapSockets.Add(SquareFoundation2);
	SquareFoundation3 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("SquareFoundation3"));
	SquareFoundation3->SetupAttachment(RootComponent);
	SnapSockets.Add(SquareFoundation3);

	TriangleFoundation0 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("TriangleFoundation0"));
	TriangleFoundation0->SetupAttachment(RootComponent);
	SnapSockets.Add(TriangleFoundation0);
	TriangleFoundation1 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("TriangleFoundation1"));
	TriangleFoundation1->SetupAttachment(RootComponent);
	SnapSockets.Add(TriangleFoundation1);
	TriangleFoundation2 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("TriangleFoundation2"));
	TriangleFoundation2->SetupAttachment(RootComponent);
	SnapSockets.Add(TriangleFoundation2);
	TriangleFoundation3 = CreateDefaultSubobject<USquareFoundationSSSMComponent>(TEXT("TriangleFoundation3"));
	TriangleFoundation3->SetupAttachment(RootComponent);
	SnapSockets.Add(TriangleFoundation3);
	
}


