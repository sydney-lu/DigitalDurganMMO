// Copyright Digital Durgan studios. All rights reserved.

#include "EnemyCharacter.h"

#include "AI/Controllers/AIEnemyController.h"

void AEnemyCharacter::BeginPlay()
{
	AAIEnemyController* controller = Cast<AAIEnemyController>(GetController());
	if (controller)
	{
		controller->SetBlackboardOwner(this);
	}
}
