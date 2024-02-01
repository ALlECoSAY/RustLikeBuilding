// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Components/Character/BuildingComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/DMCharacter.h"
#include "Controllers/DMPlayerController.h"


// Sets default values for this component's properties
UBuildingComponent::UBuildingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UActorComponent::SetComponentTickEnabled(false);

	// ...
	

}


// Called when the game starts
void UBuildingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...


	const auto Character = CastChecked<ADMCharacter>(GetOwner());
	
	Character->OnUpdateLookDelegate.BindUObject(this, &UBuildingComponent::OnCameraLocationUpdate);

	AddBuildingInputMappingContext();
	//todo error nptr exception, mb delegate firing
	BindInputActionsToCallbackFunctions();
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

void UBuildingComponent::ToggleBuildingMode()
{
	// Development only
	UE_LOG(LogTemp, Warning, TEXT("ToggleBuildingMode"));
#if UE_BUILD_DEVELOPMENT
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));
#endif
	

	
	bIsMenuModeToggled = !bIsMenuModeToggled;
	if(bIsMenuModeToggled)
	{
		ToggleMenuModeOn();
	}
	else
	{
		ToggleMenuModeOff();
	}
}

void UBuildingComponent::OpenBuildingMenu()
{

#if UE_BUILD_DEVELOPMENT
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));			
#endif
}

void UBuildingComponent::CloseBuildingMenu()
{
#if UE_BUILD_DEVELOPMENT
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));			
#endif
}

void UBuildingComponent::AddBuildingInputMappingContext()
{
	//get the player controller
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwner()->GetInstigatorController());
	//get the subsystem
	const auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	//add Input Mapping Context
	if (Subsystem)
	{
		Subsystem->AddMappingContext(BuildingMappingContext, InputMappingContextPriority);
	}
}

void UBuildingComponent::RemoveBuildingInputMappingContext()
{
	//get the player controller
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwner()->GetInstigatorController());
	//get the subsystem
	const auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	//add Input Mapping Context
	if (Subsystem)
	{
		Subsystem->AddMappingContext(BuildingMappingContext, InputMappingContextPriority);
	}
}

void UBuildingComponent::BindInputActionsToCallbackFunctions()
{
	//get the player controller
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwner()->GetInstigatorController());
	//get the input component
	const auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerController->InputComponent);
	
	//bind the toggle building menu delegate
	
	// Toggle Building Mode
	EnhancedInputComponent->BindAction(ToggleBuildingMenuAction, ETriggerEvent::Triggered, this, &ThisClass::ToggleBuildingMode);

	// Building Menu Open
	EnhancedInputComponent->BindAction(BuildAction, ETriggerEvent::Triggered, this, &ThisClass::OpenBuildingMenu);
	// Building Menu Close
	EnhancedInputComponent->BindAction(BuildAction, ETriggerEvent::Completed, this, &ThisClass::CloseBuildingMenu);
	
	
}

void UBuildingComponent::ToggleMenuModeOn()
{
	SetComponentTickEnabled(true);
	OnToggleBuildingMenuDelegate.Execute(true);
}

void UBuildingComponent::ToggleMenuModeOff()
{
	SetComponentTickEnabled(false);
	OnToggleBuildingMenuDelegate.Execute(false);
}


// Called every frame
void UBuildingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

