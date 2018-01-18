// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillDefinitions.generated.h"

/**
 * 
 */

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

USTRUCT(BlueprintType)
struct FBuff
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		EBuffType type;
	UPROPERTY(EditAnywhere)
		float strength;
};

USTRUCT(BlueprintType)
struct FDebuff
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		EDebuffType type;
	UPROPERTY(EditAnywhere)
		float strength;
};