// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "SuperstructureBuildingNode.h"
#include "WallSuperstructureBuildingNode.generated.h"

UCLASS()
class DRUNKENMOGUS_API AWallSuperstructureBuildingNode : public ASuperstructureBuildingNode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWallSuperstructureBuildingNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
