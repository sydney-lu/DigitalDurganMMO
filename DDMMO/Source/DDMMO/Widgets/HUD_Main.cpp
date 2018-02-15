// Copyright Digital Durgan studios. All rights reserved.

#include "HUD_Main.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Engine/UserInterfaceSettings.h"
#include "PlayerInfoWidget.h"

FVector2D UHUD_Main::RestrictToBox(FVector2D position, FVector2D min, FVector2D max)
{
	if(max < min)
		return position;

	if (position.X < min.X) position.X = min.X;
	else if (position.X > max.X) position.X = max.X;

	if (position.Y < min.Y) position.Y = min.Y;
	else if (position.Y > max.Y) position.Y = max.Y;

	return position;
}

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
	UWidgetDrag* DragOp = Cast<UWidgetDrag>(InOperation);
	if (DragOp)
	{
		if (Cast<UPlayerInfoWidget>(DragOp->WidgetReference))
		{
			FVector2D newPosition = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition()) - DragOp->DragOffset;
			if (GEngine && GEngine->GameViewport)
			{
				FVector2D viewportSize = GEngine->GameViewport->Viewport->GetSizeXY();
				float viewportScale = GetDefault<UUserInterfaceSettings>()->GetDPIScaleBasedOnSize(FIntPoint(viewportSize.X, viewportSize.Y));
				FVector2D Max = InGeometry.GetLocalPositionAtCoordinates(FVector2D(1, 1)) - DragOp->WidgetReference->GetDesiredSize();
				FVector2D Min = FVector2D::ZeroVector;

				newPosition = RestrictToBox(newPosition, Min, Max);
			}

			DragOp->WidgetReference->RemoveFromParent();
			DragOp->WidgetReference->AddToViewport();
			DragOp->WidgetReference->SetPositionInViewport(newPosition, false);
		}
	}
	return true;
}