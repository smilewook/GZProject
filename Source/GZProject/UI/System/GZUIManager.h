// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/Data/GZUIInfoData.h"
#include "UI/Data/GZUILoadDataTable.h"
#include "UI/Define/GZDefine.h"
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
	 * Main Screen을 초기화
	 * @param MainScreenUIMode 메인스크린에 표시할 UIMode
	 */
	void Initialize(EGZUIMode EUIMode);

	/**
	* Main Screen의 UIState를 변경함
	* @param MainUIState 변경하고자 하는 메인스크린 UIState
	*/
	void ChangeUIState(EGZUIState MainUIState);

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

	/**
	 * UIInfo 데이터를 리턴함
	 * @param TargetClass WidgetBlueprint의 Class
	 * @return FGZUIInfoData InfoData
	 */
	FGZUIInfoData GetUIInfoData(UClass* TargetClass);

	// UI 데이터 받아서 목록 생성
	//

protected:
	UPROPERTY()
	TSubclassOf<class UGZUIMainScreen> MainScreenClass;
private:
	/** GameInstance */
	static class UGZGameInstance* GameInstance;

	/** 메인 스크린 */
 	UPROPERTY(Transient)
 	class UGZUIMainScreen* MainScreen;

	/** UIState, UIMode 의 정의 */
	TArray<FGZUILoadDataTable*> UILoadDataArray;

	/** UIComponent 위치 데이터 */
	TArray<FGZUIInfoData*> UIInfoDataArray;
};
