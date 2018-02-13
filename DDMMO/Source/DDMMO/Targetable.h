// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Targetable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UTargetable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DDMMO_API ITargetable
{
	GENERATED_BODY()

	bool m_isTargeted;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Targetable")
		bool OnTargeted();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Targetable")
		bool OnUntargeted();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Targetable")
		bool IsTargeted();
};
