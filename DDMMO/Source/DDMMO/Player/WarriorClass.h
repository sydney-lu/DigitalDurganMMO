// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/CharacterClass.h"
#include "WarriorClass.generated.h"

/**
 * 
 */
UCLASS()
class DDMMO_API UWarriorClass : public UCharacterClass
{
	GENERATED_BODY()
	
private:

	UFUNCTION()
		void BasicAttack() override;

	UFUNCTION()
		void BasicRanged() override;

	UFUNCTION()
		void BasicBlock() override;

	UFUNCTION()
		void WarriorPride(UCharacterSkillData* skillData);
	
	UFUNCTION()
		void Leap(UCharacterSkillData* skillData);

	UFUNCTION()
		void Block(UCharacterSkillData* skillData);

	UFUNCTION()
		void LeapingStrike(UCharacterSkillData* skillData);

	UFUNCTION()
		void Retaliation(UCharacterSkillData* skillData);

	UFUNCTION()
		void ShieldBash(UCharacterSkillData* skillData);

	UFUNCTION()
		void Downfall(UCharacterSkillData* skillData);
};
