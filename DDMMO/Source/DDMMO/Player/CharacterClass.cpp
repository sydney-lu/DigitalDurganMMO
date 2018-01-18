// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterClass.h"

UCharacterClass::UCharacterClass()
{
}

UCharacterClass::UCharacterClass(ADDMMOCharacter* playerCharacter, UCharacterClassData* classData)
{
	InitClass(playerCharacter, classData);
}

void UCharacterClass::InitClass(ADDMMOCharacter* playerCharacter, UCharacterClassData* classData)
{
	m_classData = classData;
	m_player = playerCharacter;

	SkillLogicDelegates.SetNum(m_classData->SkillsData().Num());

	if (m_classData != nullptr) 
	{
		for (size_t i = 0; i < m_classData->SkillsData().Num(); i++)
		{
			// Try to Bind To UFuction named the same as current SkillData name.
			SkillLogicDelegates[i].BindUFunction(this, m_classData->SkillsData()[i]->Name(), m_classData->SkillsData()[i]);

			// Check if UFunction was Found and properly bound, else Bind to DefaultSkill
			if (!SkillLogicDelegates[i].IsBound())
			{
				UE_LOG(LogTemp, Warning, TEXT("Logic Function for Skill: %s not implimented"), *m_classData->SkillsData()[i]->Name().ToString())
					SkillLogicDelegates[i].BindUFunction(this, FName("DefaultSkill"), m_classData->SkillsData()[i]);
			}
		}
	}
}

void UCharacterClass::DefaultSkill(UCharacterSkillData* skillData)
{
	if (skillData != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("Logic Function for Skill: %s not implimented"), *skillData->Name().ToString())
}

void UCharacterClass::BasicAttack()
{

}

void UCharacterClass::BasicRanged()
{

}

void UCharacterClass::BasicBlock()
{

}
