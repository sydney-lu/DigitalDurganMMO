// Copyright Digital Durgan studios. All rights reserved.

#include "PlayerInfoWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DragDropOperation.h"
#include "DDMMO/WidgetDrag.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>

FReply UPlayerInfoWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	FKey DragKey = FKey("LeftMouseButton");

	if (InMouseEvent.GetEffectingButton() == DragKey || InMouseEvent.IsTouchEvent())
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, TEXT("NativeOnMouseButtonDown."));
		return FReply::Handled().DetectDrag(this->TakeWidget(), DragKey);
	}
	return FReply::Unhandled();
}

void UPlayerInfoWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation *& OutOperation)
{
	UWidgetDrag* DragDropOp = NewObject<UWidgetDrag>();

	DragDropOp->WidgetReference = this;
	DragDropOp->DragOffset = DragOffset;
	DragDropOp->DefaultDragVisual = this;
	DragDropOp->Pivot = EDragPivot::MouseDown;

	OutOperation = DragDropOp;
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, TEXT("NativeOnDragDetected."));
}

void UPlayerInfoWidget::ToggleVisible()
{
	if (MainHud) 
	{
		IsVisible = !IsVisible;

		if (IsVisible)
		{
			SetVisibility(ESlateVisibility::Visible);
			MainHud->AddInfoWidget(this);
		}
		else
		{
			SetVisibility(ESlateVisibility::Hidden);
			MainHud->RemoveInfoWidget(this);
		}
	}
}
