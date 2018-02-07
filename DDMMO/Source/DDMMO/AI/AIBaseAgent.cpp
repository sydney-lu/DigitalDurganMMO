// Copyright Digital Durgan studios. All rights reserved.

#include "AIBaseAgent.h"


// Sets default values
AAIBaseAgent::AAIBaseAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAIBaseAgent::BeginPlay()
{

}

// Called to bind functionality to input
void AAIBaseAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

