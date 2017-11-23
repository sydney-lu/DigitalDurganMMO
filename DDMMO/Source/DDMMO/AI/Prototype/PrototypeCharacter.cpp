// Copyright Digital Durgan studios. All rights reserved.

#include "PrototypeCharacter.h"

APrototypeCharacter::APrototypeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APrototypeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrototypeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APrototypeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

