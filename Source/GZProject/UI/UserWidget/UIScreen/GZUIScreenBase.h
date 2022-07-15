// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Blueprint/UserWidget.h"
#include "UI/Event/GZUIEventListener.h"
#include "UI/Data/GZUILoadDataTable.h"
#include "UI/Define/GZUIDefine.h"
#include "GZUIScreenBase.generated.h"

/** UIScreen에서 UIState 변경될 때 Broadcast() */
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnScreenUIStateChanged, class UGZUIScreenBase*, EGZUIState);

/**
 * UI가 보여질 스크린 화면에 할당하는 베이스 클래스.(Main/Touch..)
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
	* UIScreen 설정
	* @param NewUIMode 새로운 UIMode
	*/
	virtual void SetUIScreen(EGZUIScreen UIScreenType);

	/**
	* UIScreen Type를 리턴함
	* @return EGZUIScreen 현재 UIScreen
	*/
	virtual EGZUIScreen GetUIScreen();

	/**
	* UIMode 설정
	* @param NewUIMode 새로운 UIMode
	*/
	virtual void SetUIMode(EGZUIMode NewUIMode);

	/**
	* UIState를 변경함
	* @param NewState 변경할 STATE
	*/
	virtual void ChangeUIState(EGZUIState NewUIState);

	/**
	* UI STATE를 리턴함
	* @return EGZUIState 현재 UIState
	*/
	EGZUIState GetUIState() const { return EGZUIState::None; }

	/**
	 * 이벤트 리스너 설정
	 * @param EventListener 이벤트 리스너
	 */
	void AddUIEventListener(class IGZUIEventListener* EventListener);
	void RemoveUIEventListener(class IGZUIEventListener* EventListener);

	/**
	 * 화면 상에 존재하는 UIComponent 배열 정보
	 */
	TArray<class UGZUIComponent*>& GetUIComponentsOnScreen() { return UIComponentsOnScreen; }

protected:

	/**
	* 모든 상태와 내부 데이터를 리셋
	*/
	void Reset();

	/**
	* UIComponent를 대상 Layer에 추가함
	* @param NewWidget 새로 추가할 UIComponent
	* @param InLayerType Layer 타입
	*/
	UFUNCTION()
		void AddUIComponentToLayer(class UGZUIComponent* NewUIComponent, EGZUIScreenLayerType InLayerType);
	
	/**
	* 이전 상태 데이터와 비교하여 삭제할 위젯들은 삭제하고 새로운 위젯들은 추가함
	* @param InStateData 변경할 UIState에 해당하는 Data
	*/
	UFUNCTION()
	void AttachNewState(FGZUILoadDataTable InLoadData);

	/**
	* UILoadData 전달받아 캐시된 위젯(배치된)을 리턴함
	* @param StateDataToRemove 찾고자 하는 위젯 목록
	* @return TArray<UGZUIComponent*> 위젯 포인터를 담은 배열
	*/
	TArray<class UGZUIComponent*> GetUIComponentsToRemove(FGZUILoadDataTable& LoadDataToRemove);

	/**
	 * UIComponent가 삭제될 준비가 됐을 때 이벤트를 전달받음
	 * @param UIComponent 삭제 준비가 된 UIComponent
	 */
	UFUNCTION()
	void OnReadyToDestroyChild(class UUserWidget* UserWidget);

	/**
	 * UIEventListeners에 등록된 UIComponent EventListener에 이벤트를 전달
	 * @param EventParam 전달할 이벤트
	 */
	void OnUIComponentEvent(const FGZUIEventParam& EventParam);

public:
	/** UIScreen에서 UIState 변경될 때 Brodcast() */
	FOnScreenUIStateChanged OnScreenUIStateChanged;

	/** 타겟이 될 UIScreenLayer */
	UPROPERTY(BlueprintReadOnly, Category = "GZ", meta = (BindWidgetOptional))
	class UGZUIScreenLayer* UIScreenLayer;

protected:
	/** 현재 UIScreen */
	EGZUIScreen CurUIScreen = EGZUIScreen::None;

	/** 현재 UIMode */
	EGZUIMode CurUIMode;

	/** 화면 상에 배치된 UIComponent 배열*/
	TArray<class UGZUIComponent*> UIComponentsOnScreen;

	/** 삭제 중인 UIComponent 배열*/
	TArray<class UGZUIComponent*> UIComponentsToRemove;

	/** 새롭게 적용 중인 UIState에 대한 데이터 */
	FGZUILoadDataTable NewLoadData;

	/** 현재 적용 중인 UIState에 대한 데이터 */
	FGZUILoadDataTable CurLoadData;

	/** UIState 변경 시 초기화(UIComponent 모두를 새로 재생성) 작업을 할 지 결정하는 플래그 */
	bool bResetUI = false;

	TArray<class IGZUIEventListener*> UIEventListeners;

};
