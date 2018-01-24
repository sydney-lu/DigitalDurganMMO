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

FString UCharacterSkillData::Description()
{
	return m_description;
}

UTexture2D * UCharacterSkillData::GetImage()
{
	return m_image;
}

FVector4 UCharacterSkillData::CastInfo()
{
	return FVector4(m_cost, m_castTime, m_cooldown, m_charges);
}

FVector4 UCharacterSkillData::SkillStats()
{
	return FVector4(m_castRange, m_abilityRange, m_triggerTimer, m_duration);
}

float UCharacterSkillData::SkillDamage()
{
	return m_damage;
}

TArray<ECastLocation> UCharacterSkillData::CastableLocations()
{
	return m_castLocations;
}

TArray<EAbilityType> UCharacterSkillData::Type()
{
	return m_castTypes;
}

TArray<FBuff> UCharacterSkillData::Buffs()
{
	return m_buffs;
}

TArray<FDebuff> UCharacterSkillData::Debuffs()
{
	return m_debuffs;
}
