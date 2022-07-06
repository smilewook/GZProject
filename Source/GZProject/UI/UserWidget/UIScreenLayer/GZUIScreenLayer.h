// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZUIScreenLayer.generated.h"

UENUM()
enum class EGZUIScreenLayerType
{
	None,
	Background,			// ������ �ڿ� �򸮴� ��׶���
	Contents,			// ������
	Modal,				// ���(����ó��)
	Popup,				// �Ϲ� �˾�
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
	* LayerWidget �� ã�� ������
	* @param InLayerType ã���� �ϴ� Layer Ÿ��
	* @param UCanvasPanel Layer�� ���� CanvasPanel
	*/
	class UCanvasPanel* GetLayerCanvasPanel(EGZUIScreenLayerType InLayerType);

public:
	/** ��� �������� ����ϴ� ���̾� ���� */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* BackgroundLayerWidget;

	/** ������ ���̾� ���� */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* ContentsLayerWidget;

	/** ���(Ŭ���� ���� ���� ó��) ���̾� ���� */
	UPROPERTY(BlueprintReadOnly, Category = "UI", Meta = (BindWidgetOptional))
	class UGZUIScreenLayerWidget* ModalLayerWidget;

	/** �˾��� ���� ���̾� ���� */
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
