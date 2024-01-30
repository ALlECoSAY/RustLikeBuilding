// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "FoundationBuildingNode.h"
#include "SquareFoundationBuildingNode.generated.h"

UCLASS()
class DRUNKENMOGUS_API ASquareFoundationBuildingNode : public AFoundationBuildingNode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASquareFoundationBuildingNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
