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
	* UIManager Init
	* @param NewUIMode 새로운 UIMode를 설정
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
	 * 화면 상에 존재하는 UIComponent 배열 정보
	 */
	TArray<class UGZUIComponent*>& GetUIComponentsOnScreen() { return UIComponentsOnScreen; }

protected:
	/**
	* UIComponent를 대상 Layer에 추가함
	* @param NewWidget 새로 추가할 UIComponent
	* @param InLayerType Layer 타입
	*/
	//UFUNCTION()
		//void AddUIComponentToLayer(class UM1UIComponent* NewUIComponent, EGZUIScreenLayerType InLayerType);

	/**
	* 이전 상태 데이터와 비교하여 삭제할 위젯들은 삭제하고 새로운 위젯들은 추가함
	* @param InStateData 변경할 UIState에 해당하는 Data
	*/
	//UFUNCTION()
		//void AttachNewState(FM1UIStateData InStateData);

public:
	/** 타겟이 될 UIScreenLayer */
	UPROPERTY(BlueprintReadOnly, Category = "GZ", meta = (BindWidgetOptional))
	class UGZUIScreenLayer* UIScreenLayer;

protected:
	/** 현재 UIMode */
	EGZUIMode CurUIMode;

	/** 화면 상에 배치된 UIComponent 배열*/
	TArray<class UGZUIComponent*> UIComponentsOnScreen;

	/** 새롭게 적용 중인 UIState에 대한 데이터 */
	FUILoadData NewLoadData;

	/** 현재 적용 중인 UIState에 대한 데이터 */
	FUILoadData CurLoadData;

	/** UIState 변경 시 초기화(UIComponent 모두를 새로 재생성) 작업을 할 지 결정하는 플래그 */
	bool bResetUI = false;

};
