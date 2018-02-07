// Copyright Digital Durgan studios. All rights reserved.

#include "AIEnemyController.h"

#include "AI/Agents/EnemyCharacter.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIEnemyController::AAIEnemyController()
{

}

void AAIEnemyController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	AEnemyCharacter* character = Cast<AEnemyCharacter>(InPawn);
	if (character && character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*character->BehaviorTree->BlackboardAsset);

		BehaviorTreeComponent->StartTree(*character->BehaviorTree);
	}
}

void AAIEnemyController::UnPossess()
{
	Super::UnPossess();

	BehaviorTreeComponent->StopTree();
}

void AAIEnemyController::SetBlackboardOwner(AActor * NewOwner)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsObject("SelfActor", NewOwner);
	}
}