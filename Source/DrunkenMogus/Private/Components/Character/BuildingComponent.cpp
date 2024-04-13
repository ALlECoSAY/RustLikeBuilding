// Oleksii Pushkarov practice Rust-alike Building System + UI


#include "Components/Character/BuildingComponent.h"

#include "BuildingDeveloperSettings.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Characters/DMCharacter.h"
#include "Controllers/DMPlayerController.h"
#include "Engine/StaticMeshActor.h"
#include "GameInstances/DMGameInstance.h"


UBuildingComponent::UBuildingComponent()
{
#if UE_SERVER
    PrimaryComponentTick.bCanEverTick = true;
#endif
}


void UBuildingComponent::BeginPlay()
{
	Super::BeginPlay();
	
    UActorComponent::SetComponentTickEnabled(false);

#if not UE_SERVER 

	//get GameInstance
	const auto GameInstance = CastChecked<UDMGameInstance>(GetWorld()->GetGameInstance());

	const auto Character = CastChecked<ADMCharacter>(GetOwner());
	//bind view update to the camera transform update
	Character->GetFollowCamera()->TransformUpdated.AddUObject(this, &ThisClass::OnCharacterFollowCameraTransformUpdate);

	AddBuildingInputMappingContext();
	
	BindInputActionsToCallbackFunctions();

	//setup deafault values for building
	SetupDefaults();
	
#endif
	
}

void UBuildingComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
#if not UE_SERVER
	RemoveBuildingInputMappingContext();
#endif
}

void UBuildingComponent::SetupDefaults()
{
	const auto BuildingDeveloperSettings = GetDefault<UBuildingDeveloperSettings>();

	CurrentBuildingNode = BuildingDeveloperSettings->DefaultBuildingNode;
}


void UBuildingComponent::UpdateBuildingView(FVector CameraLocation, FVector CameraForwardVector)
{

	const auto CameraFocusLocation = CameraLocation + CameraForwardVector * BuildDistance;
	auto CameraFocusRotation = CameraForwardVector.Rotation();
	CameraFocusRotation.Pitch = 0.0f; CameraFocusRotation.Roll = 0.0f;
	Server_TryPlaceBlueprint(CameraFocusLocation, CameraFocusRotation);
		
#if WITH_EDITOR
	Debug_DrawDebug();
#endif
}

void UBuildingComponent::Server_TryBuild_Implementation(FVector Location, FRotator Rotation, EBuildingNode BuildingNode)
{
#if UE_SERVER

	Build(Location, Rotation, BuildingNode);	

#endif
}

#if UE_SERVER
void UBuildingComponent::Build(FVector Location, FRotator Rotation, EBuildingNode BuildingNode)
{
	const auto BuildingNodeInfo = GetDefault<UBuildingDeveloperSettings>()->GetBuildingNodeInfo(BuildingNode);
	check(BuildingNodeInfo);
	const auto BuildingNodeClass = BuildingNodeInfo->BuildingNodeClass;
	check(BuildingNodeClass);
	auto Params = FActorSpawnParameters();
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(BuildingNodeClass, Location, Rotation, Params);	
}
#endif

void UBuildingComponent::Server_TryPlaceBlueprint_Implementation(FVector Location, FRotator Rotation)
{
#if UE_SERVER
    bool IsSuccess = true;
	bool IsSnapped = false;
	FVector NewLocation = Location;
	FRotator NewRotation = Rotation;

	Client_PlaceBlueprint(NewLocation, NewRotation, IsSuccess, IsSnapped);
#endif
}


void UBuildingComponent::Client_PlaceBlueprint_Implementation(FVector Location, FRotator Rotation, bool IsPlaceable,
	bool IsSnapped)
{
#if not UE_SERVER

	SnappedLocation = Location;
	SnappedRotation = Rotation;
	bIsSnapped = IsSnapped;
	if(bIsPlaceable != IsPlaceable)
	{
		bIsPlaceable = IsPlaceable;
		//todo blueprint material options
	}
	
	BlueprintBuildingNodeActor->SetActorLocationAndRotation(SnappedLocation, SnappedRotation);
	
#endif
}



void UBuildingComponent::OnCharacterFollowCameraTransformUpdate(USceneComponent* UpdatedComponent,
	EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	if (!bIsBuildingModeActive)
	{
		return;
	}
	
	const auto Character = CastChecked<ADMCharacter>(GetOwner());
	const auto CameraComponent = Character->GetFollowCamera();
	const auto CameraLocation = CameraComponent->GetComponentLocation();

	const auto PlayerController = GetOwner()->GetInstigatorController();

	check(PlayerController);

	const auto CameraForwardVector = CameraComponent->GetForwardVector();

	UpdateBuildingView(CameraLocation, CameraForwardVector);
}

void UBuildingComponent::OnToggleBuildingModeInput()
{
#if WITH_EDITOR
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));
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

void UBuildingComponent::ShowBuildingMenu() const
{

#if WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));			
#endif

	OnToggleBuildingMenuDelegate.Broadcast(true);
	
}

void UBuildingComponent::HideBuildingMenu() const
{
#if WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(__FUNCTION__));			
#endif
	
	OnToggleBuildingMenuDelegate.Broadcast(false);
}

void UBuildingComponent::OnBuildInput()
{
#if WITH_EDITOR
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%hs"), __FUNCTION__));
#endif

	Server_TryBuild(SnappedLocation, SnappedRotation, CurrentBuildingNode);
}

void UBuildingComponent::AddBuildingInputMappingContext() const
{
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwner()->GetInstigatorController());
	const auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(BuildingMappingContext, InputMappingContextPriority);
}

void UBuildingComponent::RemoveBuildingInputMappingContext() const
{
	if(!IsValid(GetOwner()))
	{
		return;
	}
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwner()->GetInstigatorController());
	const auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	check(Subsystem);
	Subsystem->RemoveMappingContext(BuildingMappingContext);
}

void UBuildingComponent::BindInputActionsToCallbackFunctions()
{
	const auto PlayerController = CastChecked<ADMPlayerController>(GetOwner()->GetInstigatorController());
	const auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerController->InputComponent);
	
	EnhancedInputComponent->BindAction(ToggleBuildingModeAction, ETriggerEvent::Triggered, this, &ThisClass::OnToggleBuildingModeInput);
	EnhancedInputComponent->BindAction(ToggleBuildingMenuAction, ETriggerEvent::Triggered, this, &ThisClass::OnToggleBuildingMenuInput);
	EnhancedInputComponent->BindAction(BuildAction, ETriggerEvent::Triggered, this, &ThisClass::OnBuildInput);
}

#if WITH_EDITOR
void UBuildingComponent::Debug_DrawDebug()
{
	//draw debug CameraFocusLocation
	//DrawDebugSphere(GetWorld(), CameraFocusLocation, 15.0f, 12, FColor::Magenta, false, 0, 10, 3.f);

	//draw debug SnappedLocation
	DrawDebugSphere(GetWorld(), SnappedLocation, 25.0f, 12, FColor::Green, false, 0, 10, 3.f);
	
}
#endif

void UBuildingComponent::ActivateBuildingMode()
{
	//enable tick
	SetComponentTickEnabled(true);

	//spawn default blueprint node actor
	auto Params = FActorSpawnParameters();
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	const auto BuildingDeveloperSettings = GetDefault<UBuildingDeveloperSettings>();
	CurrentBuildingNode = BuildingDeveloperSettings->DefaultBuildingNode;
	const auto CurrentBuildingNodeInfo = BuildingDeveloperSettings->GetBuildingNodeInfo(CurrentBuildingNode);
	check(CurrentBuildingNodeInfo);
	BlueprintBuildingNodeActor = GetWorld()->SpawnActor<AActor>(CurrentBuildingNodeInfo->BlueprintBuildingNodeClass, SnappedLocation, SnappedRotation, Params);
	//notify
	OnToggleBuildingModeDelegate.Broadcast(true);
}

void UBuildingComponent::DeactivateBuildingModeOff()
{
	//disable tick
	SetComponentTickEnabled(false);
	
	BlueprintBuildingNodeActor->Destroy();
	//notify
	OnToggleBuildingModeDelegate.Broadcast(false);
}

void UBuildingComponent::OnToggleBuildingMenuInput()
{
	if(!bIsBuildingModeActive)
	{
		return;
	}
	
#if WITH_EDITOR
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));
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

