// Oleksii Pushkarov practice Rust-alike Building System + UI

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

	// Called when the building mode activated
	void InitiateBuilding();
	
	void UpdateBlueprintLocationAndRotation(FVector CameraLocation, FVector CameraForwardVector);

	// Callback on Look action
	UFUNCTION()
	void OnCameraLocationUpdate(FVector CameraLocation, FVector CameraForwardVector);

	// Building Mode input handling 
	void ToggleBuildingMode();
	void ActivateBuildingMode();
	void DeactivateBuildingModeOff();
	// Building Menu input handling
	void ToggleBuildingMenu();
	void ShowBuildingMenu();
	void HideBuildingMenu();
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

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleBuildingModeAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TriggerBuildingMenuAction;

#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	float BuildDistance = 1000.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> BuildingDataTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Building)
	TObjectPtr<AActor> BlueprintBuildingNodeActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Building|UI", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AActor>> BlueprintBuildingNodeActorClasses;

	bool bIsBuildingModeActive = false;
	bool bIsBuildingMenuShown = false;

	UPROPERTY(EditAnywhere, Category= Input,  meta = (AllowPrivateAccess = "true"))
	int InputMappingContextPriority = 0;
	
};
