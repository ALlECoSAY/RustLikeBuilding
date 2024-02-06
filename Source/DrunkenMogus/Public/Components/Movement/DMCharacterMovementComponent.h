// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DMCharacterMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRUNKENMOGUS_API UDMCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()


	virtual void CallMovementUpdateDelegate(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;
	
};
