// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterClass.h"

UCharacterClass::UCharacterClass()
{
}

UCharacterClass::UCharacterClass(UCharacterClassData* classData)
{
	InitClass(classData);
}

void UCharacterClass::InitClass(UCharacterClassData* classData)
{
	m_classData = classData;

	if (m_classData)
	{
		for (size_t i = 0; i < m_classData->SkillsData().Num(); i++)
			skillUsability.Add(CastInfo(m_classData->SkillsData()[i]));
	}
}

void UCharacterClass::Tick(float deltaTime)
{
	if (m_classData)
	{
		for (size_t i = 0; i < skillUsability.Num(); i++)
			skillUsability[i].TickCooldown(deltaTime);
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
