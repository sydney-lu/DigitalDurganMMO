// Copyright Digital Durgan studios. All rights reserved.

#include "WarriorClass.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>

void UWarriorClass::BasicAttack()
{
	Super::BasicAttack();
}

void UWarriorClass::BasicRanged()
{
	Super::BasicRanged();
}

void UWarriorClass::BasicBlock()
{
	Super::BasicBlock();
}

void UWarriorClass::WarriorPride(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated WarriorPride."));
}

void UWarriorClass::Leap(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated Leap."));
}

void UWarriorClass::Block(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated Block."));
}

void UWarriorClass::LeapingStrike(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated LeapingStrike."));
}

void UWarriorClass::Retaliation(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated Retaliation."));
}

void UWarriorClass::Bash(UCharacterSkillData * skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated Bash."));
}

void UWarriorClass::Downfall(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated Downfall."));
}

void UWarriorClass::SkyStrike(UCharacterSkillData * skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated SkyStrike."));
}

void UWarriorClass::Grab(UCharacterSkillData * skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activated Grab."));
}