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

		// Called every frame
		//virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
