// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "UI/Game/DMHUD.h"

#include "Characters/DMCharacter.h"
#include "Components/Character/BuildingComponent.h"
#include "Controllers/DMPlayerController.h"

void ADMHUD::BeginPlay()
{
	Super::BeginPlay();


	//Get the player character
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwningPlayerController());
	const auto PlayerCharacter = CastChecked<ADMCharacter>(PlayerController->GetPawn());

	//bind the toggle building menu delegate
	PlayerCharacter->GetBuildingComponent()->OnToggleBuildingMenuDelegate.BindUObject(this, &ThisClass::OnToggleBuildingMenu);
	
	
}

void ADMHUD::OnToggleBuildingMenu(bool bIsShown)
{
	//todo
}
