// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"
#include "GZUIScreenLayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIScreenLayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UGZUIScreenLayerWidget(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(BlueprintReadOnly, Category = "GZ", Meta = (BindWidget))
	class UCanvasPanel* UICanvas;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "GZ")
	EGZUIScreenLayerType LayerType;
};
