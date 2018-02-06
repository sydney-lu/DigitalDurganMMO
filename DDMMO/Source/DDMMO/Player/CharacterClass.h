// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterClassData.h"
#include "UObject/NoExportTypes.h"
#include "CharacterClass.generated.h"


UCLASS()
class DDMMO_API UCharacterClass : public UObject
{
	GENERATED_BODY()

public:

	UCharacterClassData* m_classData;

public:
	UCharacterClass();
	UCharacterClass(UCharacterClassData* classData);
	void InitClass(UCharacterClassData* classData);

protected:

	UFUNCTION()
		void DefaultSkill(UCharacterSkillData* skillData);

	UFUNCTION()
		virtual void BasicAttack();

	UFUNCTION()
		virtual void BasicRanged();

	UFUNCTION()
		virtual void BasicBlock();
};
