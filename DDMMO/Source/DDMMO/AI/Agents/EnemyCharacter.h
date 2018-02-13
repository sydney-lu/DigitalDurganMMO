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

		UPROPERTY(VisibleAnywhere, Category = "AI")
			class UPawnSensingComponent* PawnSensingComp;
	
	protected:
		UPROPERTY(EditDefaultsOnly)
			float areaRadius;

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		AEnemyCharacter();

		UFUNCTION()
			void OnSeePlayer(APawn* Pawn);

		UFUNCTION()
			void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);
	
};
