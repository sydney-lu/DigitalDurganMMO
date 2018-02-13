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

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName SelfActorKeyName;

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName TargetKeyName;

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName WaypointKeyName;

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName PositionKeyName;

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName AreaRadiusKeyName;

		virtual void Possess(APawn* InPawn) override;

		virtual void UnPossess() override;


	public:
		AAIEnemyController();

		void SetBlackboardOwner(AActor* NewOwner);

		void SetTarget(class ADDMMOCharacter* NewTarget);

		void SetWaypoint(FVector NewWaypoint);

		void SetAreaRadius(float NewRadius);
};
