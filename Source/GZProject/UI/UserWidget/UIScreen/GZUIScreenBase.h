// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Blueprint/UserWidget.h"
#include "UI/Data/GZUILoadData.h"
#include "UI/Define/GZDefine.h"
#include "GZUIScreenBase.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIScreenBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UGZUIScreenBase(const FObjectInitializer& ObjectInitailizer);

public:
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	//~ End UUserWidget Interface

	/**
	 * ��� ���¿� ���� �����͸� ����
	 */
	void Reset();

	/**
	* UIManager Init
	* @param NewUIMode ���ο� UIMode�� ����
	*/
	virtual void SetUIMode(EGZUIMode NewUIMode);

	/**
	* UIState�� ������
	* @param NewState ������ STATE
	*/
	virtual void ChangeUIState(EGZUIState NewUIState);

	/**
	* UI STATE�� ������
	* @return EGZUIState ���� UIState
	*/
	EGZUIState GetUIState() const { return EGZUIState::None; }

	/**
	 * ȭ�� �� �����ϴ� UIComponent �迭 ����
	 */
	TArray<class UGZUIComponent*>& GetUIComponentsOnScreen() { return UIComponentsOnScreen; }

	/**
	* UILoadData ���޹޾� ĳ�õ� ����(��ġ��)�� ������
	* @param StateDataToRemove ã���� �ϴ� ���� ���
	* @return TArray<UGZUIComponent*> ���� �����͸� ���� �迭
	*/
	TArray<class UGZUIComponent*> GetUIComponentsToRemove(FGZUILoadData& LoadDataToRemove);

protected:
	
	/**
	* ���� ���� �����Ϳ� ���Ͽ� ������ �������� �����ϰ� ���ο� �������� �߰���
	* @param InStateData ������ UIState�� �ش��ϴ� Data
	*/
	UFUNCTION()
	void AttachNewState(FGZUILoadData InLoadData);

	/**
	* UIComponent�� ��� Layer�� �߰���
	* @param NewWidget ���� �߰��� UIComponent
	* @param InLayerType Layer Ÿ��
	*/
	UFUNCTION()
	void AddUIComponentToLayer(class UGZUIComponent* NewUIComponent, EGZUIScreenLayerType InLayerType);

public:
	/** Ÿ���� �� UIScreenLayer */
	UPROPERTY(BlueprintReadOnly, Category = "GZ", meta = (BindWidgetOptional))
	class UGZUIScreenLayer* UIScreenLayer;

protected:
	/** ���� UIMode */
	EGZUIMode CurUIMode;

	/** ȭ�� �� ��ġ�� UIComponent �迭*/
	TArray<class UGZUIComponent*> UIComponentsOnScreen;

	/** ���� ���� UIComponent �迭*/
	TArray<class UGZUIComponent*> UIComponentsToRemove;

	/** ���Ӱ� ���� ���� UIState�� ���� ������ */
	FGZUILoadData NewLoadData;

	/** ���� ���� ���� UIState�� ���� ������ */
	FGZUILoadData CurLoadData;

	/** UIState ���� �� �ʱ�ȭ(UIComponent ��θ� ���� �����) �۾��� �� �� �����ϴ� �÷��� */
	bool bResetUI = false;

};
