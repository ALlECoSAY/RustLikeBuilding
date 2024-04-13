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
	
	FOnToggleBuildingModeSignature OnToggleBuildingModeDelegate;
	FOnToggleBuildingMenuSignature OnToggleBuildingMenuDelegate;

protected:

	UBuildingComponent();
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
	

	void SetupDefaults();
	
	// Callback on TransformUpdate
	void OnCharacterFollowCameraTransformUpdate(USceneComponent* UpdatedComponent, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport);


#pragma region UI
protected:
	
	void ShowBuildingMenu() const;
	void HideBuildingMenu() const;
	
	bool bIsBuildingModeActive = false;
	bool bIsBuildingMenuShown = false;
	
#pragma endregion
	
#pragma region Input
protected:
	
	// Input mappings management
	void AddBuildingInputMappingContext() const;
	void RemoveBuildingInputMappingContext() const;
	void BindInputActionsToCallbackFunctions();
	
	// Building Mode input handling 
	void OnToggleBuildingModeInput();
	
	// Building Menu input handling
	void OnToggleBuildingMenuInput();

	// Building input handling
	void OnBuildInput();
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* BuildingMappingContext;

	/** OnToggleBuildingModeInput Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleBuildingModeAction;

	/** OnToggleBuildingMenuInput Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleBuildingMenuAction;

	/** OnBuildInput Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BuildAction;
	
	UPROPERTY(EditAnywhere, Category= Input,  meta = (AllowPrivateAccess = "true"))
	int InputMappingContextPriority = 0;

#pragma endregion

#pragma region Building
protected:
	void ActivateBuildingMode();
	void DeactivateBuildingModeOff();
	
	void UpdateBuildingView(FVector CameraLocation, FVector CameraForwardVector);

	UFUNCTION(Server, Unreliable)
	void Server_TryPlaceBlueprint(FVector Location, FRotator Rotation);
	UFUNCTION(Client, Unreliable)
	void Client_PlaceBlueprint(FVector Location, FRotator Rotation, bool IsPlaceable, bool IsSnapped);

	UFUNCTION(Server, Reliable)
	void Server_TryBuild(FVector Location, FRotator Rotation, EBuildingNode BuildingNode);

	#if UE_SERVER
	void Build(FVector Location, FRotator Rotation, EBuildingNode BuildingNode);
	#endif

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	float BuildDistance = 1000.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Building)
	TObjectPtr<AActor> BlueprintBuildingNodeActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|UI", meta = (AllowPrivateAccess = "true"))
	EBuildingNode CurrentBuildingNode = EBuildingNode::SquareFoundation;
	
	FVector SnappedLocation;
	FRotator SnappedRotation;
	
	bool bIsSnapped = false;
	bool bIsPlaceable = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|Blueprint", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstanceDynamic> BlueprintMaterial;


#pragma endregion
	
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
