// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SkillDefinitions.h"
#include "CharacterSkillData.generated.h"


UCLASS(BlueprintType)
class DDMMO_API UCharacterSkillData : public UDataAsset
{
	GENERATED_BODY()

public:

protected:

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Name"))
		FName m_skillName;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Tag"))
		ESkillTag m_tag;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cost", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_cost;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cooldown", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_cooldown;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Time", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_castTime;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Max Charges", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_charges;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Duration", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_duration;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Range", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_castRange;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Skill Range", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_abilityRange;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Trigger Timer", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_triggerTimer;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Base Damage", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStrength)
		float m_damage;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Location"), Category = Types)
		TArray<ECastLocation> m_castLocations;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Type"), Category = Types)
		TArray<EAbilityType> m_castTypes;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Buff Type"), Category = Buffs)
		TArray<FBuff> m_buffs;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Debuff Type"), Category = Buffs)
		TArray<FDebuff> m_debuffs;

public:
	FName Name();
	ESkillTag Tag();

	FVector4 CastInfo();		// (Cost, CastTime, Cooldown, Charges)
	FVector4 SkillStats();		// (CastRange, AbilityRange, TriggerTimer, Duration)
	float SkillDamage();

	TArray<ECastLocation> CastableLocations();
	TArray<EAbilityType> Type();
	TArray<FBuff> Buffs();
	TArray<FDebuff> Debuffs();
};