// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Components/Character/BuildingComponent.h"

#include "Characters/DMCharacter.h"


// Sets default values for this component's properties
UBuildingComponent::UBuildingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}


// Called when the game starts
void UBuildingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...


	const auto Character = CastChecked<ADMCharacter>(GetOwner());
	
	Character->OnUpdateLookDelegate.BindUObject(this, &UBuildingComponent::OnCameraLocationUpdate);
	
	

	
}

void UBuildingComponent::InitiateBuilding()
{
	

	
}

void UBuildingComponent::UpdateBlueprintLocationAndRotation(FVector CameraLocation, FVector CameraForwardVector)
{
	//todo: implement
}

void UBuildingComponent::OnCameraLocationUpdate(FVector CameraLocation, FVector CameraForwardVector)
{
	UpdateBlueprintLocationAndRotation(CameraLocation, CameraForwardVector);
}

void UBuildingComponent::ToggleBuildingMenu()
{
	bIsMenuShown = !bIsMenuShown;
	OnToggleBuildingMenuDelegate.Execute(bIsMenuShown);
}


// Called every frame
void UBuildingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

