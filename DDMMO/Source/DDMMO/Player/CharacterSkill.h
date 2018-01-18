// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterSkillData.h"
#include "Engine/TriggerVolume.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "CharacterSkill.generated.h"


UCLASS(BlueprintType)
class DDMMO_API ACharacterSkill : public ATriggerVolume
{
	GENERATED_BODY()

	UCharacterSkillData* skilldata;
	APlayerController* player;

private:

	ACharacterSkill();
	void Tick(float deltaTime) override;
};
