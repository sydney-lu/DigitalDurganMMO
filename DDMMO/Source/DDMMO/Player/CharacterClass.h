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
	UCharacterClassData* classData;

	DECLARE_DELEGATE_OneParam(SkillLogic, UCharacterSkillData*);
	TArray<SkillLogic> SkillLogicDelegates;

public:
	void InitClass();

protected:
	UFUNCTION()
		void DefaultSkill(UCharacterSkillData* skillData);
};
