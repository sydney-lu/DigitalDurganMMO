// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterSkillData.h"

FName UCharacterSkillData::Name()
{
	return m_skillName;
}

ESkillTag UCharacterSkillData::Tag()
{
	return m_tag;
}

FVector4 UCharacterSkillData::CastInfo()
{
	return FVector4(m_cost, m_castTime, m_cooldown, m_charges);
}

FVector4 UCharacterSkillData::SkillStats()
{
	return FVector4(m_castRange, m_abilityRange, m_triggerTimer, m_duration);
}

FVector UCharacterSkillData::SkillStrength()
{
	return FVector(m_damage, m_buffStrength, m_debuffStrength);
}

TArray<ECastLocation> UCharacterSkillData::CastableLocations()
{
	return m_castLocations;
}

TArray<EAbilityType> UCharacterSkillData::Type()
{
	return m_castTypes;
}

TArray<EBuffType> UCharacterSkillData::Buff()
{
	return m_buffTypes;
}

TArray<EDebuffType> UCharacterSkillData::Debuff()
{
	return m_debuffTypes;
}
