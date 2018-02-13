// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUD_Main.h"
#include "PlayerInfoWidget.generated.h"


UCLASS()
class DDMMO_API UPlayerInfoWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	FVector2D DragOffset;
	bool IsVisible;

public:
	UHUD_Main *MainHud;

protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation *& OutOperation) override;

public:
	UFUNCTION(BlueprintCallable)
		void ToggleVisible();
};
