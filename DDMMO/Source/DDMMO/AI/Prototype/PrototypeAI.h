// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PrototypeAI.generated.h"

UCLASS()
class DDMMO_API APrototypeAI : public AAIController
{
	GENERATED_BODY()

public:
	APrototypeAI();
	virtual void Possess(APawn* InPawn) override;
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& other) const override;

	//UPROPERTY(transient) // transient -> intializing the 0
	//class UBlackboardComponent* PrototypeBB;

	//UPROPERTY(transient)
	//class UBehaviorTreeComponent* PrototypeBT;

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* PrototypeBT;

	//uint8 EnemyKeyID;
};