// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/Data/GZUIInfoData.h"
#include "UI/Data/GZUILoadDataTable.h"
#include "UI/Define/GZUIDefine.h"
#include "GZUIManager.generated.h"

/**
 * 
 */
UCLASS(config=UI)
class GZPROJECT_API UGZUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UGZUIManager();

	/**
	 * GZGameInstance에 존재하는 UIManager 레퍼런스를 전달
	 */
	static UGZUIManager& GetUIManager();

	//~ Begin USubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End USubsystem Interface

	/**
	 * UIScreen을 생성초기화
	 * @param UIScreen 어떤 UI스크린에 표시할지 설정
	 * @param UIMode UI모드 설정
	 */
	void CreateUIScreen(EGZUIScreen TargetUIScreen, EGZUIMode UIMode);

	/**
	 * UIScreen Widget을 Get
	 * @param UIScreenType
	 * @return UGZUIScreenBase*
	 */
	class UGZUIScreenBase* GetUIScreen(EGZUIScreen UIScreenType) const;

	/**
	* Main Screen의 UIState를 변경함
	* @param TargetUIScreen 변경하고자 하는 스크린
	* @param NewUIState 변경될 UIState
	*/
	void ChangeUIState(EGZUIScreen TargetUIScreen, EGZUIState NewUIState);

	/**
	* UI STATE를 리턴함
	* @param TargetScreen 스크린 인덱스 (0 = 메인)
	* @return EGZUIState 현재 UIState
	*/
	EGZUIState GetUIState(EGZUIScreen TargetScreen) const;

	/**
	* UIState를 전달 받아 UIStateData를 리턴함
	* @param UIState UIState 값
	* @return FGZUILoadDataTable
	*/
	FGZUILoadDataTable GetUIStateData(EGZUIState UIState);

	/**
	* UI 이름을 리턴함
	* @param UIEnum
	* @return FString 현재 UI 이름
	*/
	FString GetUINameByEnum(EGZUIName UIEnum) const;

	/**
	* UI 가 오픈되어 있는지 확인
	* @param UIEnum
	* @return BOOL TRUE=열려있음, FALSE=닫힘.
	*/
	bool IsOpenedUI(EGZUIName UIEnum);

	/**
	* UI 가 오픈되어 있는지 확인
	* @param UIName
	* @return BOOL TRUE=열려있음, FALSE=닫힘.
	*/
	bool IsOpenedUIByName(FString UIName);

	/**
	* UIComponent 리턴함
	* @param EGZUIName UIEnum
	*/
	class UGZUIComponent* FindUIComponentByEnum(EGZUIName UIEnum);

	/**
	* UIScreen 리턴함
	* @param EGZUIScreen UIScreen
	*/
	class UGZUIScreenBase* GetUIScreenWidget(EGZUIScreen UIScreen);

	// UI 데이터 받아서 목록 생성
	//

protected:
	UPROPERTY()
	TSubclassOf<class UGZUIMainScreen> MainScreenClass;

	UPROPERTY()
	TSubclassOf<class UGZUITouchScreen> TouchScreenClass;

	UPROPERTY(Transient)
	TArray<TObjectPtr<class UGZUIScreenBase>> UIScreens;

private:
	/** GameInstance */
	static class UGZGameInstance* GameInstance;

	/** 메인 스크린 */
 	UPROPERTY(Transient)
 	class UGZUIMainScreen* MainScreen;

	/** 터치 스크린 */
	UPROPERTY(Transient)
	class UGZUITouchScreen* TouchScreen;	

	/** UIState, UIMode 의 정의 */
	TArray<FGZUILoadDataTable*> UILoadDataArray;
};
