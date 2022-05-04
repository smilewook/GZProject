// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
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
	* UI STATE 이름을 리턴함
	* @param UIState
	* @return FString 현재 UIState 이름
	*/
	FString GetUIStateNameByEnum(EGZUIState UIState) const;

	/**
	* UI 가 오픈되어 있는지 확인
	* @param UIContent
	* @return BOOL TRUE=열려있음, FALSE=닫힘.
	*/
	bool IsOpenedUI(FString UIState);

	/**
	* UI 가 오픈되어 있는지 확인
	* @param UIName
	* @return BOOL TRUE=열려있음, FALSE=닫힘.
	*/
	bool IsOpenedUIByName(FString UIName);

	/**
	* UI Screen 리턴함
	* @param UIScreen
	*/
	class UGZUIScreenBase* GetUIScreenWidget(EGZUIScreen UIScreen);

	// UI 데이터 받아서 목록 생성
	//

protected:
	UPROPERTY()
	TSubclassOf<class UGZUIScreenBase> MainScreenClass;
private:
	/** GameInstance */
	static class UGZGameInstance* GameInstance;

	/** 메인 스크린 */
 	UPROPERTY(Transient)
 	class UGZUIScreenBase* MainScreen;
};
