// Copyright Digital Durgan studios. All rights reserved.

#include "PlayerInfoWidget.h"
#include "DragDropOperation.h"
#include "DDMMO/WidgetDrag.h"

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
