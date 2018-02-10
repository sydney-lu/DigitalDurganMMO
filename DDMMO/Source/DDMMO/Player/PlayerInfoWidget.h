// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInfoWidget.generated.h"


UCLASS()
class DDMMO_API UPlayerInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent)
		void OnInitialize();

	UFUNCTION(BlueprintNativeEvent)
		void ToggleVisible();
};
