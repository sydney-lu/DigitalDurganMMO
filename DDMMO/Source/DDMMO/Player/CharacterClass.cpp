// Copyright Digital Durgan studios. All rights reserved.

#include "CharacterClass.h"

UCharacterClass::UCharacterClass()
{
}

UCharacterClass::UCharacterClass(UCharacterClassData* classData)
{
	m_classData = classData;
}

void UCharacterClass::InitClass(UCharacterClassData* classData)
{
	m_classData = classData;
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
