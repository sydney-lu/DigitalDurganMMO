// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterClassData.h"

FString UCharacterClassData::Description()
{
	return FString(m_className + ":" + m_styleTag + ":" + m_subStyleTag);
}

FVector4 UCharacterClassData::BaseStats()
{
	return FVector4(m_baseAttack, m_baseSpeed, m_baseStamina, m_baseDefence);
}

TArray<UCharacterSkillData*> UCharacterClassData::SkillsData()
{
	return skillsData;
}
