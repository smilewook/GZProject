// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayerWidget.h"

UCanvasPanel* UGZUIScreenLayer::GetLayerCanvasPanel(EGZUIScreenLayerType InLayerType)
{
	switch (InLayerType)
	{
	case EGZUIScreenLayerType::Background:
		return IsValid(BackgroundLayerWidget) ? BackgroundLayerWidget->UICanvas : BackgroundLayerCanvas;

	case EGZUIScreenLayerType::Contents:
		return IsValid(ContentsLayerWidget) ? ContentsLayerWidget->UICanvas : ContentsLayerCanvas;

	case EGZUIScreenLayerType::Modal:
		return IsValid(ModalLayerWidget) ? ModalLayerWidget->UICanvas : ModalLayerCanvas;

	case EGZUIScreenLayerType::Popup:
		return IsValid(PopupLayerWidget) ? PopupLayerWidget->UICanvas : PopupLayerCanvas;

	default:	// 모달로 우선 처리.
		return IsValid(ModalLayerWidget) ? ModalLayerWidget->UICanvas : ModalLayerCanvas;
	}
}
