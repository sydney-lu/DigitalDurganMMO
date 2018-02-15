// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DraggableWidget.generated.h"


UCLASS()
class DDMMO_API UDraggableWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	FVector2D DragOffset;

protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation *& OutOperation) override;

	UFUNCTION(BlueprintImplementableEvent)
		void OnStartDrag();

	UFUNCTION(BlueprintImplementableEvent)
		void OnDropped();
};
