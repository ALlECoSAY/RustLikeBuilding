// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Building/BuildingNodes/BuildingNode.h"
#include "BuildingComponent.generated.h"

class UInputMappingContext;
class UInputAction;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnToggleBuildingModeSignature,/*bIsActivated*/ bool);
//HUD link to show/hide building menu
DECLARE_MULTICAST_DELEGATE_OneParam(FOnToggleBuildingMenuSignature,/*bIsShown*/ bool);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class DRUNKENMOGUS_API UBuildingComponent : public UActorComponent
{
	GENERATED_BODY()


	

public:
	// Sets default values for this component's properties
	UBuildingComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetupDefaults();

	void UpdateBuildingView(FVector CameraLocation, FVector CameraForwardVector);
	void UpdateFocusLocation(FVector CameraLocation, FVector CameraForwardVector);
	void UpdateSnappedLocation(FVector CameraLocation, FVector CameraForwardVector);

	// Callback on TransformUpdate
	void OnCharacterFollowCameraTransformUpdate(USceneComponent* UpdatedComponent, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport);

	// Building Mode input handling 
	void ToggleBuildingMode();
	void ActivateBuildingMode();
	void DeactivateBuildingModeOff();
	// Building Menu input handling
	void ToggleBuildingMenu();
	void ShowBuildingMenu();
	void HideBuildingMenu();
	// Building input handling
	void Build();
	// Input mappings management
	void AddBuildingInputMappingContext();
	void RemoveBuildingInputMappingContext();
	void BindInputActionsToCallbackFunctions();





public:
	
	FOnToggleBuildingModeSignature OnToggleBuildingModeDelegate;
	FOnToggleBuildingMenuSignature OnToggleBuildingMenuDelegate;

protected:

#pragma region Input
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* BuildingMappingContext;

	/** ToggleBuildingMode Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleBuildingModeAction;

	/** ToggleBuildingMenu Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleBuildingMenuAction;

	/** Build Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BuildAction;
	
	UPROPERTY(EditAnywhere, Category= Input,  meta = (AllowPrivateAccess = "true"))
	int InputMappingContextPriority = 0;

#pragma endregion

#pragma region Building
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	float BuildDistance = 1000.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Building)
	TObjectPtr<AActor> BlueprintBuildingNodeActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|UI", meta = (AllowPrivateAccess = "true"))
	EBuildingNode CurrentBuildingNode = EBuildingNode::SquareFoundation;

	UPROPERTY(Transient)
	TArray<FBuildingNodeInfo> BuildingNodesInfos;
	
	FBuildingNodeInfo* CurrentBuildingNodeInfo = nullptr;

	FVector FocusLocation;
	FRotator FocusRotation;
	
	FVector SnappedLocation;
	FRotator SnappedRotation;
	
	bool bIsBuildingModeActive = false;
	bool bIsBuildingMenuShown = false;

#pragma region Debug

	
#if WITH_EDITOR

	void Debug_DrawDebug();
	
#endif

	
#if WITH_EDITORONLY_DATA

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Debug, meta = (AllowPrivateAccess = "true"))
	bool bDebug = false;
	
#endif

#pragma endregion
};
