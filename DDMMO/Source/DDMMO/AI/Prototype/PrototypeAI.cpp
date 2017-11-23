// Copyright Digital Durgan studios. All rights reserved.

#include "PrototypeAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "PrototypeCharacter.h"

APrototypeAI::APrototypeAI()
{
}

void APrototypeAI::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (APrototypeAI* PrototypeCharacer = Cast<APrototypeAI>(InPawn))
	{
		if (PrototypeBT)
		{
			RunBehaviorTree(PrototypeBT);

			//EnemyKeyID = PrototypeBT->GetKeyID("Target");
		}
	}
}

ETeamAttitude::Type APrototypeAI::GetTeamAttitudeTowards(const AActor& other) const
{
	if (Cast<IGenericTeamAgentInterface>(&other))
	{
		return Super::GetTeamAttitudeTowards(other);
	}
	return ETeamAttitude::Hostile;
}
