// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "WorldObjects/SMStaticWorldObject.h"


ASMStaticWorldObject::ASMStaticWorldObject()
{

	
	
	// Create a static mesh component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	
	
}

