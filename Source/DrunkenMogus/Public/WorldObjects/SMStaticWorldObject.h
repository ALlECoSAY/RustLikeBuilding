// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "StaticWorldObject.h"
#include "SMStaticWorldObject.generated.h"

UCLASS()
class DRUNKENMOGUS_API ASMStaticWorldObject : public AStaticWorldObject
{
	GENERATED_BODY()


public:
	ASMStaticWorldObject();

#pragma region GET/SET

	FORCEINLINE TObjectPtr<UStaticMeshComponent> GetStaticMeshComponent() const { return StaticMeshComponent; }
	FORCEINLINE void SetStaticMeshComponent(TObjectPtr<UStaticMeshComponent> val) { StaticMeshComponent = val; }

#pragma endregion

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

};
