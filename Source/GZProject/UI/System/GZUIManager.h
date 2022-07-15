// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GZGameInstance.h"
#include "UI/Data/GZUILoadDataTable.h"
#include "UI/Define/GZUIDefine.h"
#include "UI/Event/GZUIEventListener.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "GZUIManager.generated.h"

/** UIState ���� �� Delegate */
DECLARE_MULTICAST_DELEGATE_OneParam(FOnUIStateChanged, EGZUIState);

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
	 * UIScreen�� �����ʱ�ȭ
	 * @param UIScreen � UI��ũ���� ǥ������ ����
	 * @param UIMode UI��� ����
	 */
	void CreateUIScreen(EGZUIScreen TargetUIScreen, EGZUIMode UIMode);

	/**
	* Main Screen�� UIState�� ������
	* @param TargetUIScreen �����ϰ��� �ϴ� ��ũ��
	* @param NewUIState ����� UIState
	*/
	void ChangeUIState(EGZUIScreen TargetUIScreen, EGZUIState NewUIState);

	/**
	 * UIEvent Listener�� �߰���
	 * @param TargetUIScreen Ÿ�� ��ũ��
	 * @param Listener ������
	 */
	void AddUIEventListener(EGZUIScreen TargetUIScreen, class IGZUIEventListener* Listener);

	/**
	 * UIEvent Listener�� ������
	 */
	void RemoveUIEventListener(class IGZUIEventListener* Listener);
	void RemoveUIEventListener(EGZUIScreen TargetUIScreen, class IGZUIEventListener* Listener);

	/**
	 * UIScreen Widget�� Get
	 * @param UIScreenType
	 * @return UGZUIScreenBase*
	 */
	class UGZUIScreenBase* GetUIScreen(EGZUIScreen UIScreenType) const;

	/**
	* UI STATE�� ������
	* @param TargetScreen ��ũ�� �ε��� (0 = ����)
	* @return EGZUIState ���� UIState
	*/
	EGZUIState GetUIState(EGZUIScreen TargetScreen) const;

	/**
	* UIState�� ���� �޾� UIStateData�� ������
	* @param UIState UIState ��
	* @return FGZUILoadDataTable
	*/
	FGZUILoadDataTable GetUIStateData(EGZUIState UIState);

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

	/**
	* UIState ����ɶ� UIScreen Ÿ�Ժ� ��ϵ� UI���� ���� �Լ� ��������Ʈ�� ��� 
	* @param TargetUIScreen UIScreen(Main, Touch..)
	* @param InObj ���������� ���� UIComponent
	* @param InResponseMethod UIComponent���� �ݹ���� �Լ�
	*/
	template< class UserClass >
	void SetOnUIStateChanged(EGZUIScreen TargetUIScreen, UserClass* InObj, typename FOnUIStateChanged::FDelegate::TUObjectMethodDelegate< UserClass >::FMethodPtr InResponseMethod)
	{
		FOnUIStateChanged& OnUIStateChanged = UIStateChangeDelegates.FindOrAdd(TargetUIScreen);

		OnUIStateChanged.Add(FOnUIStateChanged::FDelegate::CreateUObject(InObj, InResponseMethod));
	}

	/**
	* Widget�� ��ϵ� ��������Ʈ ����
	* @param InObj ����
	*/
	void ClearOnUIStateChanged(TObjectPtr<UObject> InObj);
	
protected:
	/**
	* ����, ���꽺ũ���� UIState �̺�Ʈ�� �ޱ� ���� �Լ�
	* @param UIScreen ��ũ�� ��ü ������
	* @param NewState ���� �� UIState ��
	*/
	UFUNCTION()
	void OnScreenUIStateChanged(UGZUIScreenBase* UIScreen, EGZUIState NewState);

protected:
	UPROPERTY()
	TSubclassOf<class UGZUIMainScreen> MainScreenClass;

	UPROPERTY()
	TSubclassOf<class UGZUITouchScreen> TouchScreenClass;

	/** ������ ��ũ�� �迭 */
	UPROPERTY(Transient)
	TArray<TObjectPtr<class UGZUIScreenBase>> UIScreens;

private:
	/** GameInstance */
	static class UGZGameInstance* GameInstance;

	/** ���� ��ũ�� */
 	UPROPERTY(Transient)
 	class UGZUIMainScreen* MainScreen;

	/** ��ġ ��ũ�� */
	UPROPERTY(Transient)
	class UGZUITouchScreen* TouchScreen;	

	/** UIState, UIMode �� ���� */
	TArray<FGZUILoadDataTable*> UILoadDataArray;

	/** UIScreen Ÿ�Ժ�, ������ ��������Ʈ ���� */
	TMap<EGZUIScreen, FOnUIStateChanged> UIStateChangeDelegates;
};
