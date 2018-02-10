// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterClassData.h"

FString UCharacterClassData::Description()
{
	return FString(m_className + ":" + m_styleTag + ":" + m_subStyleTag);
}

float UCharacterClassData::BaseAttack()
{
	return m_baseAttack;
}

float UCharacterClassData::BaseSpeed()
{
	return m_baseSpeed;
}

float UCharacterClassData::BaseStamina()
{
	return m_baseStamina;
}

float UCharacterClassData::BaseDefence()
{
	return m_baseDefence;
}

TArray<UCharacterSkillData*> UCharacterClassData::SkillsData()
{
	return skillsData;
}
