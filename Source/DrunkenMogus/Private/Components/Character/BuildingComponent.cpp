// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Components/Character/BuildingComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Characters/DMCharacter.h"
#include "Controllers/DMPlayerController.h"
#include "GameInstances/DMGameInstance.h"


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


	//get GameInstance
	const auto GameInstance = CastChecked<UDMGameInstance>(GetWorld()->GetGameInstance());

	//todo get the building data table 
	//BuildingNodesInfos = GameInstance->GetBuildingNodesInfos();
	
	const auto Character = CastChecked<ADMCharacter>(GetOwner());
	//bind view update to the camera transform update
	Character->GetFollowCamera()->TransformUpdated.AddUObject(this, &ThisClass::OnCharacterFollowCameraTransformUpdate);

	AddBuildingInputMappingContext();
	
	//todo error nptr exception, mb delegate firing
	BindInputActionsToCallbackFunctions();


	//setup deafault values for building
	SetupDefaults();
	
}

void UBuildingComponent::SetupDefaults()
{
	//CurrentBuildingNodeInfo = 
	
	
}


void UBuildingComponent::UpdateBuildingView(FVector CameraLocation, FVector CameraForwardVector)
{
	UpdateFocusLocation(CameraLocation, CameraForwardVector);
	UpdateSnappedLocation(CameraLocation, CameraForwardVector);

	
#if WITH_EDITOR
	Debug_DrawDebug();
#endif
}

void UBuildingComponent::UpdateFocusLocation(FVector CameraLocation, FVector CameraForwardVector)
{
	FocusLocation = CameraLocation + CameraForwardVector * BuildDistance;
}

void UBuildingComponent::UpdateSnappedLocation(FVector CameraLocation, FVector CameraForwardVector)
{
	//todo: implement snapping to the grid
	SnappedLocation = FocusLocation - FVector::UpVector * 200.0f;
}

void UBuildingComponent::OnCharacterFollowCameraTransformUpdate(USceneComponent* UpdatedComponent,
	EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	const auto Character = CastChecked<ADMCharacter>(GetOwner());
	const auto CameraComponent = Character->GetFollowCamera();
	const auto CameraLocation = CameraComponent->GetComponentLocation();

	const auto PlayerController = GetOwner()->GetInstigatorController();

	check(PlayerController);

	//const auto ForwardVector = PlayerController->GetControlRotation().Vector();
	const auto CameraForwardVector = CameraComponent->GetForwardVector();

	UpdateBuildingView(CameraLocation, CameraForwardVector);
}

void UBuildingComponent::ToggleBuildingMode()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));
#if WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));
#endif
	
	
	bIsBuildingModeActive = !bIsBuildingModeActive;
	if(bIsBuildingModeActive)
	{
		ActivateBuildingMode();
	}
	else
	{
		DeactivateBuildingModeOff();
	}
}

void UBuildingComponent::ShowBuildingMenu()
{

#if WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));			
#endif

	OnToggleBuildingMenuDelegate.Broadcast(true);
	
}

void UBuildingComponent::HideBuildingMenu()
{
#if WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));			
#endif
	
	OnToggleBuildingMenuDelegate.Broadcast(false);
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
	EnhancedInputComponent->BindAction(ToggleBuildingModeAction, ETriggerEvent::Triggered, this, &ThisClass::ToggleBuildingMode);

	// Building Menu Open
	EnhancedInputComponent->BindAction(ToggleBuildingMenuAction, ETriggerEvent::Triggered, this, &ThisClass::ToggleBuildingMenu);
		
}

#if WITH_EDITOR
void UBuildingComponent::Debug_DrawDebug()
{
	//draw debug FocusLocation
	DrawDebugSphere(GetWorld(), FocusLocation, 15.0f, 12, FColor::Magenta, false, 0, 10, 3.f);

	//draw debug SnappedLocation
	DrawDebugSphere(GetWorld(), SnappedLocation, 25.0f, 12, FColor::Green, false, 0, 10, 3.f);
	
}
#endif

void UBuildingComponent::ActivateBuildingMode()
{
	SetComponentTickEnabled(true);
	OnToggleBuildingModeDelegate.Broadcast(true);
}

void UBuildingComponent::DeactivateBuildingModeOff()
{
	SetComponentTickEnabled(false);
	OnToggleBuildingModeDelegate.Broadcast(false);
}

void UBuildingComponent::ToggleBuildingMenu()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));
#if WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));
#endif
	
	bIsBuildingMenuShown = !bIsBuildingMenuShown;
	if(bIsBuildingMenuShown)
	{
		ShowBuildingMenu();
		
	}
	else
	{
		HideBuildingMenu();
	}
}


// Called every frame
void UBuildingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

