// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClass.generated.h"

/**
 * 
 */
UCLASS()
class DDMMO_API UCharacterClass : public UDataAsset
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Name", MultiLine = true))
		FString m_className;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Style", MultiLine = true))
		FString m_styleTag;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "SubStyle", MultiLine = true))
		FString m_subStyleTag;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Base Attack", ClampMin = "0.0", UIMin = "0.0"))
		float m_baseAttack;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Base Speed", ClampMin = "0.0", UIMin = "0.0"))
		float m_baseSpeed;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Base Stamina", ClampMin = "0.0", UIMin = "0.0"))
		float m_baseStamina;
	UPROPERTY(EditAnywhere, meta = (DisplayName = "Base Defence", ClampMin = "0.0", UIMin = "0.0"))
		float m_baseDefence;

public:

	FString Description();
	FVector4 BaseStats();		//(BaseAttack,BaseSpeed,BaseStamina,BaseDefence)

};
