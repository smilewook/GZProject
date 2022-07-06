// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZUIScreenLayer.generated.h"

UENUM()
enum class EGZUIScreenLayerType
{
	None,
	Background,			// 컨텐츠 뒤에 깔리는 백그라운드
	Contents,			// 컨텐츠
	Modal,				// 모달(딤드처리)
	Popup,				// 일반 팝업
};

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIScreenLayer : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/**
	* LayerWidget 을 찾고 리턴함
	* @param InLayerType 찾고자 하는 Layer 타입
	* @param UCanvasPanel Layer의 메인 CanvasPanel
	*/
	class UCanvasPanel* GetLayerCanvasPanel(EGZUIScreenLayerType InLayerType);

public:
	/** 배경 컨텐츠에 사용하는 레이어 위젯 */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* BackgroundLayerWidget;

	/** 컨텐츠 레이어 위젯 */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* ContentsLayerWidget;

	/** 모달(클릭을 막기 위한 처리) 레이어 위젯 */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* ModalLayerWidget;

	/** 팝업을 위한 레이어 위젯 */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* PopupLayerWidget;

	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UCanvasPanel* BackgroundLayerCanvas;

	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UCanvasPanel* ContentsLayerCanvas;

	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UCanvasPanel* ModalLayerCanvas;

	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UCanvasPanel* PopupLayerCanvas;
};
