// Copyright Digital Durgan studios. All rights reserved.

#include "DraggableWidget.h"
#include "DragDropOperation.h"
#include "DDMMO/WidgetDrag.h"

FReply UDraggableWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	OnStartDrag();

	DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	FKey DragKey = FKey("LeftMouseButton");

	if (InMouseEvent.GetEffectingButton() == DragKey || InMouseEvent.IsTouchEvent())
		return FReply::Handled().DetectDrag(this->TakeWidget(), DragKey);
	return FReply::Unhandled();
}

void UDraggableWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation *& OutOperation)
{
	UWidgetDrag* DragDropOp = NewObject<UWidgetDrag>();

	DragDropOp->WidgetReference = this;
	DragDropOp->DragOffset = DragOffset;
	DragDropOp->DefaultDragVisual = this;
	DragDropOp->Pivot = EDragPivot::MouseDown;

	OutOperation = DragDropOp;
	OnDropped();
}

