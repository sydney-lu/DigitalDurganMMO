// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIBaseAgent.generated.h"

UCLASS()
class DDMMO_API AAIBaseAgent : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
		class ADDMMOCharacter* target;

	UPROPERTY(EditDefaultsOnly, Category = Enemy)
	float maxHealth;
	float currentHealth;

	UPROPERTY(EditDefaultsOnly, Category = Enemy)
	float damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy)
	float attackDistance;

	virtual void BeginPlay() override;

public:
	AAIBaseAgent();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Enemy)
	bool bIsPatroling;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Enemy)
	bool bIsReturning;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Enemy)
	bool bIsChasing;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Enemy)
	bool bIsAttacking;

	FORCEINLINE bool IsAlive() const { return currentHealth > 0.0f; }
	FORCEINLINE float GetHeathRatio() const { return (currentHealth / maxHealth); }
	FORCEINLINE float GetCurrentHealth() const { return currentHealth; }
	FORCEINLINE float GetDamage() const { return damage; }
	FORCEINLINE ADDMMOCharacter* GetAgentTarget() const { return target; }

	// Handling Damage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

};
