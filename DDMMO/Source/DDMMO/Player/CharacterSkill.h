// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterSkill.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class CastLocation : uint8
{
	Any				UMETA(DisplayName = "Any"),
	Stationary		UMETA(DisplayName = "Stationary"),
	Ground			UMETA(DisplayName = "Ground"),
	Air				UMETA(DisplayName = "Air"),
	Dead			UMETA(DisplayName = "Dead"),
	Mounted			UMETA(DisplayName = "Mounted"),
};

UENUM(BlueprintType)
enum class CastType : uint8
{
	Single			UMETA(DisplayName = "Single"),
	Line			UMETA(DisplayName = "Line"),
	Aoe				UMETA(DisplayName = "Aoe"),
	Barrage			UMETA(DisplayName = "Barrage"),
};

UENUM(BlueprintType)
enum class BuffType : uint8
{
	NoBuff			UMETA(DisplayName = "NoBuff"),
	Heal			UMETA(DisplayName = "Heal"),
	Immune			UMETA(DisplayName = "Immune"),
	Boost			UMETA(DisplayName = "Boost"),
	DecayingBoost	UMETA(DisplayName = "DecayingBoost"),
	Untargetable	UMETA(DisplayName = "Untargetable"),
};

UENUM(BlueprintType)
enum class DebuffType : uint8
{
	NoDebuff		UMETA(DisplayName = "NoDebuff"),
	Piercing		UMETA(DisplayName = "Piercing"),
	Knockback		UMETA(DisplayName = "Knockback"),
	Slow			UMETA(DisplayName = "Slow"),
	DecayingSlow	UMETA(DisplayName = "DecayingSlow"),
	Bleed			UMETA(DisplayName = "Bleed"),
	Root			UMETA(DisplayName = "Root"),
	Daze			UMETA(DisplayName = "Daze"),
	Aibourne		UMETA(DisplayName = "Aibourne"),
	Stunned			UMETA(DisplayName = "Stunned"),
	Stagger			UMETA(DisplayName = "Stagger"),
};

UENUM(BlueprintType)
enum class SkillTag : uint8
{
	Spell			UMETA(DisplayName = "Spell"),
	Primer			UMETA(DisplayName = "Primer"),
	Utility			UMETA(DisplayName = "Utility"),
	Trap			UMETA(DisplayName = "Trap"),
};

UCLASS(BlueprintType)
class DDMMO_API UCharacterSkill : public UDataAsset
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Name"))
		FString m_skillName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Tag"))
		SkillTag m_tag;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cost", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_cost;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Time", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_castTime;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cooldown", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_cooldown;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Charges", ClampMin = "0.0", UIMin = "0.0"), Category = CastInfo)
		float m_charges;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Range", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_castRange;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Skill Range", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_abilityRange; 
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Trigger Timer", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_triggerTimer;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Duration", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_duration;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Damage", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_damage;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Buff Strength", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_buffStrength;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Debuff Strength", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStats)
		float m_debuffStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Cast Location"), Category = Types)
		CastLocation m_castLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Cast Type"), Category = Types)
		CastType m_castType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Buff Type"), Category = Types)
		BuffType m_buffType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Debuff Type"), Category = Types)
		DebuffType m_debuffType;

public:
	FString Name();
	SkillTag Tag();

	FVector4 CastInfo();				// (Cost,CastTime,Cooldown,Charges)
	FVector4 SkillStats();				// (CastRange,AbilityRange,TriggerTimer,Duration)
	FVector SkillStrength();			// (Damage,BuffStrength,DebuffStrength)

	CastLocation CastableLocations();
	CastType Type();
	BuffType Buff();
	DebuffType Debuff();
};

