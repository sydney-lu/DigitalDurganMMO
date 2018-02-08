// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/AIBaseAgent.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DDMMO_API AEnemyCharacter : public AAIBaseAgent
{
	GENERATED_BODY()

	
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
	
	
};
