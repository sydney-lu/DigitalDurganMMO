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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted WarriorPride."));
}

void UWarriorClass::Leap(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted Leap."));
}

void UWarriorClass::Block(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted Block."));
}

void UWarriorClass::LeapingStrike(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted LeapingStrike."));
}

void UWarriorClass::Retaliation(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted Retaliation."));
}

void UWarriorClass::Bash(UCharacterSkillData * skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted Bash."));
}

void UWarriorClass::Downfall(UCharacterSkillData* skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted Downfall."));
}

void UWarriorClass::SkyStrike(UCharacterSkillData * skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted SkyStrike."));
}

void UWarriorClass::Grab(UCharacterSkillData * skillData)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You Activted Grab."));
}


