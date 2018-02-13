// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DDMMO/WidgetDrag.h"
#include "HUD_Main.generated.h"


UCLASS()
class DDMMO_API UHUD_Main : public UUserWidget
{
	GENERATED_BODY()

	TArray<class UUserWidget*> InfoWidgets;

public: 
	void UpdateFocus();

	void AddInfoWidget(UUserWidget* widget);
	void RemoveInfoWidget(UUserWidget* widget);

	virtual bool NativeOnDrop(const FGeometry & InGeometry, const FDragDropEvent & InDragDropEvent, UDragDropOperation * InOperation) override;
};
