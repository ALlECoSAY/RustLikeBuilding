// Copyright Epic Games, Inc. All Rights Reserved.

#include "DrunkenMogusGameMode.h"
#include "DrunkenMogusCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADrunkenMogusGameMode::ADrunkenMogusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
