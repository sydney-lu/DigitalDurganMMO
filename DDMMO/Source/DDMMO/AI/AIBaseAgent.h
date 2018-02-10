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

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		UPROPERTY(EditAnywhere, Category = "AI")
			class UBehaviorTree* BehaviorTree;

		AAIBaseAgent();

		virtual void Tick(float DeltaTime) override;
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		// Handling Damage
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

		const float MAXHEALTH = 10.0f;
		float CURHEALTH;
};
