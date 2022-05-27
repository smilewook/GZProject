// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "Engine/DataTable.h"
#include "UI/Define/GZDefine.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"
#include "GZUIInfoData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGZUIInfoData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	TSubclassOf<UGZUIComponent> WidgetBlueprintClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	EGZUIScreenLayerType UIScreenLayerType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	FAnchorData PositionData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ", AdvancedDisplay, meta = (DisplayName = "Size To Content"))
	bool bAutoSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	int32 ZOrder;

public:
	FGZUIInfoData()
	{}
};
