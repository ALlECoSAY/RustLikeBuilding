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


protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

};
