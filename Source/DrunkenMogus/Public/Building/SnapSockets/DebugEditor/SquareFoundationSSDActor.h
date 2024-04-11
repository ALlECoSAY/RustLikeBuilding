// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "SnapSocketDebugActor.h"
#include "Building/UtilsBuilding.h"
#include "SquareFoundationSSDActor.generated.h"

class USquareFoundationSSSMComponent;

UCLASS()
class DRUNKENMOGUS_API ASquareFoundationSSDActor : public ASnapSocketDebugActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASquareFoundationSSDActor();

	UPROPERTY(EditAnywhere, Category = "SnapSockets|SquareFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> SquareFoundation0;
	UPROPERTY(EditAnywhere, Category = "SnapSockets|SquareFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> SquareFoundation1;
	UPROPERTY(EditAnywhere, Category = "SnapSockets|SquareFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> SquareFoundation2;
	UPROPERTY(EditAnywhere, Category = "SnapSockets|SquareFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> SquareFoundation3;
	
	UPROPERTY(EditAnywhere, Category = "SnapSockets|TriangleFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> TriangleFoundation0;
	UPROPERTY(EditAnywhere, Category = "SnapSockets|TriangleFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> TriangleFoundation1;
	UPROPERTY(EditAnywhere, Category = "SnapSockets|TriangleFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> TriangleFoundation2;
	UPROPERTY(EditAnywhere, Category = "SnapSockets|TriangleFoundation")
	TObjectPtr<USquareFoundationSSSMComponent> TriangleFoundation3;
	

	
};
