// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "SnapSocketSMComponent.h"
#include "SquareFoundationSSSMComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class DRUNKENMOGUS_API USquareFoundationSSSMComponent : public USnapSocketSMComponent
{
	GENERATED_BODY()

public:

	virtual int32 GetAvailableSocketsBitmask() const override { return ~(SquareFoundationBitMask); }
		
	UPROPERTY(EditAnywhere, Category = SnapSockets, meta = (Bitmask, BitmaskEnum = "ESquareFoundationSocket"))
	int32 SquareFoundationBitMask;
	
};
