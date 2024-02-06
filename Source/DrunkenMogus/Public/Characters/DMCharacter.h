// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "DMCharacter.generated.h"

class UBuildingComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);


DECLARE_MULTICAST_DELEGATE_TwoParams(FOnUpdateFocusSignature, /*Camera Location*/ FVector, /*Camera ForwardVector*/ FVector);
//non dynamic version
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnCharacterMovedSignature, /*DeltaSeconds*/ float, /*OldLocation*/ FVector, /*OldVelocity*/ FVector);

UCLASS(config=Game)
class ADMCharacter : public ACharacter
{
	GENERATED_BODY()

	
public:
	ADMCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void UpdateLook(FVector CameraLocation, FVector CameraForwardVector);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:

#pragma region Getters/Setters
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns BuildingComponent subobject **/
	FORCEINLINE class UBuildingComponent* GetBuildingComponent() const { return BuildingComponent; }

	

#pragma endregion

public:
	
	
	FOnUpdateFocusSignature OnUpdateFocusDelegate;

protected:

#pragma region Components

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Building, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBuildingComponent> BuildingComponent;
	
#pragma endregion

#pragma region Input
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

#pragma endregion


	
};

