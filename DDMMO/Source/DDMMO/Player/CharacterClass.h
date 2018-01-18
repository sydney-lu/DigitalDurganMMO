// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterClassData.h"
#include "DDMMOCharacter.h"
#include "UObject/NoExportTypes.h"
#include "CharacterClass.generated.h"


UCLASS()
class DDMMO_API UCharacterClass : public UObject
{
	GENERATED_BODY()

public:

	UCharacterClassData* m_classData;
	ADDMMOCharacter* m_player;

	DECLARE_DELEGATE_OneParam(SkillLogic, UCharacterSkillData*);
	TArray<SkillLogic> SkillLogicDelegates;

public:
	UCharacterClass();
	UCharacterClass(ADDMMOCharacter* playerCharacter, UCharacterClassData* classData);
	void InitClass(ADDMMOCharacter* playerCharacter, UCharacterClassData* classData);

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
