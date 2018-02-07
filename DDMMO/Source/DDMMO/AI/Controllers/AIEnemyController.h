// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class DDMMO_API AAIEnemyController : public AAIController
{
	GENERATED_BODY()
	
	UPROPERTY(transient)
		class UBlackboardComponent* BlackboardComponent;

	UPROPERTY(transient)
		class UBehaviorTreeComponent* BehaviorTreeComponent;


	public:
		AAIEnemyController();

		virtual void Possess(APawn* InPawn) override;

		virtual void UnPossess() override;

		void SetBlackboardOwner(AActor* NewOwner);
	
};
