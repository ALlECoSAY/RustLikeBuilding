// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "DMCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API UDMCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	
	virtual void InitCheatManager() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building")
	TArray<TSubclassOf<UCheatManagerExtension>> CheatManagerExtensionsClasses;

};
