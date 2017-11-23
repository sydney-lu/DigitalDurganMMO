// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PrototypeCharacter.generated.h"

UCLASS()
class DDMMO_API APrototypeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APrototypeCharacter();
	
	//UPROPERTY(EditAnywhere, Category = Behavior)
	//class UBehaviorTree* PrototypeBehavior;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
