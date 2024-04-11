// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "SnapSocketDebugActor.generated.h"


class USnapSocketSMComponent;

UCLASS(Blueprintable, BlueprintType)
class DRUNKENMOGUS_API ASnapSocketDebugActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASnapSocketDebugActor();

	

	virtual void BeginPlay() override;
	
	virtual void OnConstruction(const FTransform& Transform) override;

#pragma region


	

	
	
	UPROPERTY()
	TArray<TObjectPtr<USnapSocketSMComponent>> SnapSockets;
};
