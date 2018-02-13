// Copyright Digital Durgan studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "Blueprint/UserWidget.h"
#include "WidgetDrag.generated.h"

/**
 * 
 */
UCLASS()
class DDMMO_API UWidgetDrag : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* WidgetReference;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector2D DragOffset;

public:
	UFUNCTION(BlueprintCallable)
	UUserWidget* GetWidgetReference();
};
