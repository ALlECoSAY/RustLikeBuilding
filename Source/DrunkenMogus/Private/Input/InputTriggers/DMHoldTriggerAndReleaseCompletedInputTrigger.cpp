// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Input/InputTriggers/DMHoldTriggerAndReleaseCompletedInputTrigger.h"

#include "EnhancedPlayerInput.h"


ETriggerState UDMHoldTriggerAndReleaseCompletedInputTrigger::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
{
	// Update HeldDuration and derive base state
	ETriggerState State = Super::UpdateState_Implementation(PlayerInput, ModifiedValue, DeltaTime);

	// Trigger when HeldDuration reaches the threshold
	bool bIsFirstTrigger = !bTriggered;
	bTriggered = HeldDuration >= HoldTimeThreshold;
	if (bTriggered)
	{
		return (bIsFirstTrigger || !bIsOneShot) ? ETriggerState::Triggered : ETriggerState::Ongoing;
	}
	// Complete on release
	if (IsActuated(LastValue))
	{
		return ETriggerState::None;
	}

	return State;
}