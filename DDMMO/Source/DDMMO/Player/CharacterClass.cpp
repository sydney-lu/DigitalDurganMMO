// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterClass.h"

FString UCharacterClass::Description()
{
	return FString(m_className + ":" + m_styleTag + ":" + m_subStyleTag);
}

FVector4 UCharacterClass::BaseStats()
{
	return FVector4(m_baseAttack, m_baseSpeed, m_baseStamina, m_baseDefence);
}
