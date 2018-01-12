// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterSkillData.generated.h"


UENUM(BlueprintType)
enum class ECastLocation : uint8
{
	Any				UMETA(DisplayName = "Any"),
	Stationary		UMETA(DisplayName = "Stationary"),
	Ground			UMETA(DisplayName = "Ground"),
	Air				UMETA(DisplayName = "Air"),
	Dead			UMETA(DisplayName = "Dead"),
	Blocking		UMETA(DisplayName = "Blocking"),
	Mounted			UMETA(DisplayName = "Mounted"),
};

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	Single			UMETA(DisplayName = "Single"),
	Line			UMETA(DisplayName = "Line"),
	Aoe				UMETA(DisplayName = "Aoe"),
	Barrage			UMETA(DisplayName = "Barrage"),
	Trap			UMETA(DisplayName = "Trap"),
	Cone			UMETA(DisplayName = "Cone"),
};

UENUM(BlueprintType)
enum class EBuffType : uint8
{
	NoBuff			UMETA(DisplayName = "NoBuff"),
	Heal			UMETA(DisplayName = "Heal"),
	Immune			UMETA(DisplayName = "Immune"),
	Boost			UMETA(DisplayName = "Boost"),
	DecayingBoost	UMETA(DisplayName = "DecayingBoost"),
	Untargetable	UMETA(DisplayName = "Untargetable"),
};

UENUM(BlueprintType)
enum class EDebuffType : uint8
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
enum class ESkillTag : uint8
{
	Spell			UMETA(DisplayName = "Spell"),
	Primer			UMETA(DisplayName = "Primer"),
	Utility			UMETA(DisplayName = "Utility"),
	Trap			UMETA(DisplayName = "Trap"),
};

UCLASS(BlueprintType)
class DDMMO_API UCharacterSkillData : public UDataAsset
{
	GENERATED_BODY()

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
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Buff Strength", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStrength)
		float m_buffStrength;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Debuff Strength", ClampMin = "0.0", UIMin = "0.0"), Category = SkillStrength)
		float m_debuffStrength;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Location"), Category = Types)
		TArray<ECastLocation> m_castLocations;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Cast Type"), Category = Types)
		TArray<EAbilityType> m_castTypes;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Buff Type"), Category = Types)
		TArray<EBuffType> m_buffTypes;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Debuff Type"), Category = Types)
		TArray<EDebuffType> m_debuffTypes;

public:
	FName Name();
	ESkillTag Tag();

	FVector4 CastInfo();		// (Cost, CastTime, Cooldown, Charges)
	FVector4 SkillStats();		// (CastRange, AbilityRange, TriggerTimer, Duration)
	FVector SkillStrength();	// (Damage, BuffStrength, DebuffStrength)

	TArray<ECastLocation> CastableLocations();
	TArray<EAbilityType> Type();
	TArray<EBuffType> Buff();
	TArray<EDebuffType> Debuff();
};