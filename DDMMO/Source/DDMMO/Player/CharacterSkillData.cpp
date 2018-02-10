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

FText UCharacterSkillData::Description()
{
	return m_description;
}

UTexture2D * UCharacterSkillData::GetImage()
{
	return m_image;
}

float UCharacterSkillData::CastTime()
{
	return m_castTime;
}

float UCharacterSkillData::Cooldown()
{
	return m_cooldown;
}

float UCharacterSkillData::Charges()
{
	return m_charges;
}

float UCharacterSkillData::CastRange()
{
	return m_castRange;
}

float UCharacterSkillData::AbilityRange()
{
	return m_abilityRange;
}

float UCharacterSkillData::TriggerTimer()
{
	return m_triggerTimer;
}

float UCharacterSkillData::Duration()
{
	return m_duration;
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
