// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DMHUD.generated.h"

/**
 * 
 */
UCLASS()
class DRUNKENMOGUS_API ADMHUD : public AHUD
{
	GENERATED_BODY()


public:

	

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnToggleBuildingMenu(bool bIsShown);

	
};
