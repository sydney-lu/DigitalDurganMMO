// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DDMMOGameMode.h"
#include "Player/DDMMOCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADDMMOGameMode::ADDMMOGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MMOCharacter/MMOCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
