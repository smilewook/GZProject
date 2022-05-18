// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/Data/GZUILoadData.h"
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
	 * GZGameInstance�� �����ϴ� UIManager ���۷����� ����
	 */
	static UGZUIManager& GetUIManager();

	//~ Begin USubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End USubsystem Interface

	/**
	 * Main Screen�� �ʱ�ȭ
	 * @param MainScreenUIMode ���ν�ũ���� ǥ���� UIMode
	 */
	void Initialize(EGZUIMode EUIMode);

	/**
	* Main Screen�� UIState�� ������
	* @param MainUIState �����ϰ��� �ϴ� ���ν�ũ�� UIState
	*/
	void ChangeUIState(EGZUIState MainUIState);

	/**
	* UI STATE�� ������
	* @param TargetScreen ��ũ�� �ε��� (0 = ����)
	* @return EGZUIState ���� UIState
	*/
	EGZUIState GetUIState(EGZUIScreen TargetScreen) const;

	/**
	* UIState�� ���� �޾� UIStateData�� ������
	* @param UIState UIState ��
	* @return FUILoadData
	*/
	FUILoadData GetUIStateData(EGZUIState UIState);

	/**
	* UI �̸��� ������
	* @param UIEnum
	* @return FString ���� UI �̸�
	*/
	FString GetUINameByEnum(EGZUIName UIEnum) const;

	/**
	* UI �� ���µǾ� �ִ��� Ȯ��
	* @param UIEnum
	* @return BOOL TRUE=��������, FALSE=����.
	*/
	bool IsOpenedUI(EGZUIName UIEnum);

	/**
	* UI �� ���µǾ� �ִ��� Ȯ��
	* @param UIName
	* @return BOOL TRUE=��������, FALSE=����.
	*/
	bool IsOpenedUIByName(FString UIName);

	/**
	* UIComponent ������
	* @param EGZUIName UIEnum
	*/
	class UGZUIComponent* FindUIComponentByEnum(EGZUIName UIEnum);

	/**
	* UIScreen ������
	* @param EGZUIScreen UIScreen
	*/
	class UGZUIScreenBase* GetUIScreenWidget(EGZUIScreen UIScreen);

	// UI ������ �޾Ƽ� ��� ����
	//

protected:
	UPROPERTY()
	TSubclassOf<class UGZUIScreenBase> MainScreenClass;
private:
	/** GameInstance */
	static class UGZGameInstance* GameInstance;

	/** ���� ��ũ�� */
 	UPROPERTY(Transient)
 	class UGZUIScreenBase* MainScreen;

	/** UIState, UIMode �� ���� */
	TArray<FUILoadData*> UILoadDataArray;
};
