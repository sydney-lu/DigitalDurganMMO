// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterSkill.h"

FString UCharacterSkill::Name()
{
	return FString();
}

SkillTag UCharacterSkill::Tag()
{
	return m_tag;
}

FVector4 UCharacterSkill::CastInfo()
{
	return FVector4(m_cost, m_castTime, m_cooldown, m_charges);
}

FVector4 UCharacterSkill::SkillStats()
{
	return FVector4(m_castRange, m_abilityRange, m_triggerTimer, m_duration);
}

FVector UCharacterSkill::SkillStrength()
{
	return FVector(m_damage, m_buffStrength, m_debuffStrength);
}

CastLocation UCharacterSkill::CastableLocations()
{
	return m_castLocation;
}

CastType UCharacterSkill::Type()
{
	return m_castType;
}

BuffType UCharacterSkill::Buff()
{
	return m_buffType;
}

DebuffType UCharacterSkill::Debuff()
{
	return m_debuffType;
}