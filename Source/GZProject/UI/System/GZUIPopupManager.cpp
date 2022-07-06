// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIPopupManager.h"
#include "GZGameInstance.h"
#include "UI/System/GZUIManager.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "UI/UserWidget/UIScreen/GZUIMainScreen.h"


UGZGameInstance* UGZUIPopupManager::GameInstance;

UGZUIPopupManager::UGZUIPopupManager()
{
	GZ_LOG_S(GZ, Warning);
}

void UGZUIPopupManager::Initialize(FSubsystemCollectionBase& Collection)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUIPopupManager::Initialize!!"));

	GameInstance = GetTypedOuter<UGZGameInstance>();
}

void UGZUIPopupManager::Deinitialize()
{
	GameInstance = nullptr;
}


void UGZUIPopupManager::Open(EGZUIPopupOpenType OpenType, FGZUIPopupOpenParams PopupParams)
{
	if (OpenType == EGZUIPopupOpenType::None || PopupParams.PopupStyle == EGZUIPopupStyle::None)
	{
		GZ_LOG(GZ, Warning, TEXT("PopupOpenType || PopupStyle is None !!"));
		return;
	}

	UGZUIScreenBase* TouchScreen = UGZUIManager::GetUIManager().GetUIScreen(EGZUIScreen::Touch);
	UGZUIScreenBase* MainScreen = UGZUIManager::GetUIManager().GetUIScreen(EGZUIScreen::Main);
	if (!IsValid(TouchScreen) || !IsValid(MainScreen))
	{
		GZ_LOG(GZ, Warning, TEXT("ScreenWidget is nullptr !!"));
		return;
	}

	/*
	// ��ũ��Ű���尡 �ƴҶ�
	if (PopupParams.PopupStyle != EGZUIPopupStyle::ScreenKeyboard)
	{
		bool bIsPopupOpend = TouchScreen->PopupComponent->IsOpened() || MainScreen->PopupComponent->IsOpened();
		if (bIsPopupOpend && IsReservable(PopupOption))
		{
			U1Popup->ReservedPopupData.Add(FU1ReservedPopupData(PopupOption, ResponseDelegate));
			return;
		}
	}

	bool bIsTouchScreenTarget = PopupOption.TargetScreens.Contains(EU1UIScreen::Touch);
	bool bIsMainScreenTarget = PopupOption.TargetScreens.Contains(EU1UIScreen::Main);

	if (bIsTouchScreenTarget && bIsMainScreenTarget)
	{
		// ���꽺ũ�� �˾��� ������ ���ν�ũ�� �˾��� �ݾƾ� �ϹǷ� ��������Ʈ�� ���ε��ص�
		if (!TouchScreen->PopupComponent->OnPopupClosed.IsBoundToObject(U1Popup))
		{
			TouchScreen->PopupComponent->OnPopupClosed.BindUObject(U1Popup, &UU1Popup::OnTouchScreenPopupClosed);
		}
	}

	if (bIsTouchScreenTarget)
	{
		TouchScreen->PopupComponent->OpenPopup(PopupOption, ResponseDelegate);
	}

	if (bIsMainScreenTarget)
	{
		MainScreen->PopupComponent->OpenPopup(PopupOption, ResponseDelegate);
	}

	OnPopupStateChanged.Broadcast(true);
	*/
}

UGZUIPopupManager& UGZUIPopupManager::GetUIPopupManager()
{
	// GameInstance�� �ν��Ͻ̵� UIPopupManager ��������.
	return *UGZGameInstance::GetSubsystem<UGZUIPopupManager>(GameInstance);
}