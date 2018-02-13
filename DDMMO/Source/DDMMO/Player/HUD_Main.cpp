// Copyright Digital Durgan studios. All rights reserved.

#include "HUD_Main.h"

void UHUD_Main::UpdateFocus()
{
	APlayerController* player = GetOwningLocalPlayer()->PlayerController;
	if (InfoWidgets.Num() > 0) 
	{
		player->bShowMouseCursor = true;
		player->SetInputMode(FInputModeGameAndUI());
	}
	else 
	{
		player->bShowMouseCursor = false;
		player->SetInputMode(FInputModeGameOnly());
	}
}

void UHUD_Main::AddInfoWidget(UUserWidget * widget)
{
	InfoWidgets.Add(widget); 
	UpdateFocus();
}

void UHUD_Main::RemoveInfoWidget(UUserWidget * widget)
{
	InfoWidgets.Remove(widget); 
	UpdateFocus();
}

bool UHUD_Main::NativeOnDrop(const FGeometry & InGeometry, const FDragDropEvent & InDragDropEvent, UDragDropOperation * InOperation)
{
	UWidgetDrag* DragOp;
	if (Cast<UWidgetDrag>(InOperation)) 
	{
		DragOp = Cast<UWidgetDrag>(InOperation);
		FVector2D offset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition() - DragOp->DragOffset);

		DragOp->WidgetReference->RemoveFromParent();
		DragOp->WidgetReference->AddToViewport();
		DragOp->WidgetReference->SetPositionInViewport(offset);
	}
	return true;
}
