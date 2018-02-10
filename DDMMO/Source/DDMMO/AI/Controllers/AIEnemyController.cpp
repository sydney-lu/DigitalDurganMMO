// Copyright Digital Durgan studios. All rights reserved.

#include "AIEnemyController.h"

#include "Player/CharacterClass.h"
#include "AI/Agents/EnemyCharacter.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIEnemyController::AAIEnemyController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

	SelfActorKeyName = "SelfActor";
	TargetKeyName = "TargetKey";
	WaypointKeyName = "WaypointKey";
	PositionKeyName = "PositionKey";
	AreaRadiusKeyName = "RadiusAreaKey";
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
		BlackboardComponent->SetValueAsObject(SelfActorKeyName, NewOwner);
	}
}

void AAIEnemyController::SetTarget(UCharacterClass* NewTarget)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsObject(TargetKeyName, NewTarget);
	}
}

void AAIEnemyController::SetWaypoint(FVector NewWaypoint)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsVector(WaypointKeyName, NewWaypoint);
		BlackboardComponent->SetValueAsVector(PositionKeyName, NewWaypoint);
	}
}

void AAIEnemyController::SetAreaRadius(float NewRadius)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsFloat(AreaRadiusKeyName, NewRadius);
	}
}
