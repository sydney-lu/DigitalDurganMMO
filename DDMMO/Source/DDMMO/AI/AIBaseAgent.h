// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIBaseAgent.generated.h"

UCLASS()
class DDMMO_API AAIBaseAgent : public ACharacter
{
	GENERATED_BODY()

	private:
		UPROPERTY(EditDefaultsOnly)
			class UCharacterClass* target;

	protected:
		UPROPERTY(EditDefaultsOnly)
			float maxHealth;
		float currentHealth;

		UPROPERTY(EditDefaultsOnly)
			float damage;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
			float attackDistance;

		virtual void BeginPlay() override;

	public:
		UPROPERTY(EditAnywhere, Category = "AI")
			class UBehaviorTree* BehaviorTree;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
			bool bIsPatroling;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
			bool bIsReturning;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
			bool bIsChasing;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
			bool bIsAttacking;


		AAIBaseAgent();

		//virtual void Tick(float DeltaTime) override;

		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		FORCEINLINE bool IsAlive() const { return currentHealth > 0.0f; }
		FORCEINLINE float GetHeathRatio() const { return (currentHealth/maxHealth); }
		FORCEINLINE float GetCurrentHealth() const { return currentHealth; }
		FORCEINLINE float GetDamage() const { return damage; }
		FORCEINLINE UCharacterClass* GetAgentTarget() const { return target; }

};
