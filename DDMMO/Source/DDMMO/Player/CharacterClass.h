// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterClassData.h"
#include "UObject/NoExportTypes.h"
#include "CharacterClass.generated.h"


UCLASS()
class DDMMO_API UCharacterClass : public UObject
{
	GENERATED_BODY() 

	struct CastInfo
	{
		UCharacterSkillData* skilldata;
		float cooldown;
		int charges;

		CastInfo(UCharacterSkillData* skilldata)
		{
			this->skilldata = skilldata;
		}

		void TickCooldown(float deltaTime)
		{
			if (charges < skilldata->Charges())
			{
				cooldown -= deltaTime;
				if (cooldown <= 0)
				{
					cooldown = skilldata->Cooldown();
					charges++;
				}
			}
		}

		bool SkillAvailable() 
		{
			return charges > 0;
		}
	};

public:

	UCharacterClassData* m_classData;
	TArray<CastInfo> skillUsability;

public:
	UCharacterClass();
	UCharacterClass(UCharacterClassData* classData);
	void InitClass(UCharacterClassData* classData);
	void Tick(float deltaTime);

protected:

	UFUNCTION()
		void DefaultSkill(UCharacterSkillData* skillData);

	UFUNCTION()
		virtual void BasicAttack();

	UFUNCTION()
		virtual void BasicRanged();

	UFUNCTION()
		virtual void BasicBlock();
};
