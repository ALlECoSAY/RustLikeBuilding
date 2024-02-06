// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Components/Movement/DMCharacterMovementComponent.h"



void UDMCharacterMovementComponent::CallMovementUpdateDelegate(float DeltaSeconds, const FVector& OldLocation,
	const FVector& OldVelocity)
{
	Super::CallMovementUpdateDelegate(DeltaSeconds, OldLocation, OldVelocity);

	
	
}
