// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterClass.h"

void UCharacterClass::InitClass()
{
	for (size_t i = 0; i < classData->SkillsData().Num(); i++)
	{
		// Try to Bind To UFuction named the same as current SkillData name.
		SkillLogicDelegates[i].BindUFunction(this, classData->SkillsData()[i]->Name(), classData->SkillsData()[i]);

		// Check if UFunction was Found and properly bound, else Bind to DefaultSkill
		if (!SkillLogicDelegates[i].IsBound())
		{
			UE_LOG(LogTemp, Warning, TEXT("Logic Function for Skill: %s not implimented"), *classData->SkillsData()[i]->Name().ToString())
				SkillLogicDelegates[i].BindUFunction(this, FName("DefaultSkill"), classData->SkillsData()[i]);
		}
	}
}

void UCharacterClass::DefaultSkill(UCharacterSkillData* skillData)
{
	UE_LOG(LogTemp, Warning, TEXT("Logic Function for Skill: %s not implimented"), *skillData->Name().ToString())
}
