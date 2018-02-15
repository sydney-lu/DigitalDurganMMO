// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DDMMO/Widgets/DraggableWidget.h"
#include "Blueprint/UserWidget.h"
#include "HUD_Main.h"
#include "PlayerInfoWidget.generated.h"


UCLASS()
class DDMMO_API UPlayerInfoWidget : public UDraggableWidget
{
	GENERATED_BODY()

protected:
	bool IsVisible;

public:
	UHUD_Main *MainHud;

public:
	UFUNCTION(BlueprintCallable)
		void ToggleVisible();

	UFUNCTION(BlueprintImplementableEvent)
		void InitilizeInfo(ACharacter* character);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateInfo(ACharacter* character);
};
