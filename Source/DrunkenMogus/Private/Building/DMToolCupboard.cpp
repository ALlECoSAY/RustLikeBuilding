// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Building/DMToolCupboard.h"


// Sets default values
ADMToolCupboard::ADMToolCupboard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADMToolCupboard::BeginPlay()
{
	Super::BeginPlay();

	//Spawn deffered to set core node

	
	
}

// Called every frame
void ADMToolCupboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

