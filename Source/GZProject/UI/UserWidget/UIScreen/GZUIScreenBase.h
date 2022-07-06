// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Blueprint/UserWidget.h"
#include "UI/Data/GZUILoadDataTable.h"
#include "UI/Define/GZUIDefine.h"
#include "GZUIScreenBase.generated.h"

/** UIScreen���� UIState ����� �� Brodcast() */
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnScreenUIStateChanged, class UGZUIScreenBase*, EGZUIState);

/**
 * UI�� ������ ��ũ�� ȭ�鿡 �Ҵ��ϴ� ���̽� Ŭ����.(Main/Touch..)
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
	* UIScreen ����
	* @param NewUIMode ���ο� UIMode
	*/
	virtual void SetUIScreen(EGZUIScreen UIScreenType);

	/**
	* UIScreen Type�� ������
	* @return EGZUIScreen ���� UIScreen
	*/
	virtual EGZUIScreen GetUIScreen();

	/**
	* UIMode ����
	* @param NewUIMode ���ο� UIMode
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
	TArray<class UGZUIComponent*> GetUIComponentsToRemove(FGZUILoadDataTable& LoadDataToRemove);

protected:
	
	/**
	* ���� ���� �����Ϳ� ���Ͽ� ������ �������� �����ϰ� ���ο� �������� �߰���
	* @param InStateData ������ UIState�� �ش��ϴ� Data
	*/
	UFUNCTION()
	void AttachNewState(FGZUILoadDataTable InLoadData);

	/**
	* UIComponent�� ��� Layer�� �߰���
	* @param NewWidget ���� �߰��� UIComponent
	* @param InLayerType Layer Ÿ��
	*/
	UFUNCTION()
	void AddUIComponentToLayer(class UGZUIComponent* NewUIComponent, EGZUIScreenLayerType InLayerType);

	/**
	 * UIComponent�� ������ �غ� ���� �� �̺�Ʈ�� ���޹���
	 * @param UIComponent ���� �غ� �� UIComponent
	 */
	UFUNCTION()
	void OnReadyToDestroyChild(class UUserWidget* UserWidget);

public:
	/** UIScreen���� UIState ����� �� Brodcast() */
	FOnScreenUIStateChanged OnScreenUIStateChanged;

	/** Ÿ���� �� UIScreenLayer */
	UPROPERTY(BlueprintReadOnly, Category = "GZ", meta = (BindWidgetOptional))
	class UGZUIScreenLayer* UIScreenLayer;

protected:
	/** ���� UIScreen */
	EGZUIScreen CurUIScreen = EGZUIScreen::None;

	/** ���� UIMode */
	EGZUIMode CurUIMode;

	/** ȭ�� �� ��ġ�� UIComponent �迭*/
	TArray<class UGZUIComponent*> UIComponentsOnScreen;

	/** ���� ���� UIComponent �迭*/
	TArray<class UGZUIComponent*> UIComponentsToRemove;

	/** ���Ӱ� ���� ���� UIState�� ���� ������ */
	FGZUILoadDataTable NewLoadData;

	/** ���� ���� ���� UIState�� ���� ������ */
	FGZUILoadDataTable CurLoadData;

	/** UIState ���� �� �ʱ�ȭ(UIComponent ��θ� ���� �����) �۾��� �� �� �����ϴ� �÷��� */
	bool bResetUI = false;

};
