// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIManager.h"
#include "GZGameInstance.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "UI/UserWidget/UIScreen/GZUIMainScreen.h"


UGZGameInstance* UGZUIManager::GameInstance;

UGZUIManager::UGZUIManager()
{
	GZ_LOG_S(GZ, Warning);

	// ���� ��ũ�� Ŭ���� �������Ʈ ����
	static ConstructorHelpers::FClassFinder<UGZUIMainScreen> MAIN_SCREEN_WIDGET(TEXT("/Game/UI/WidgetBlueprint/UIScreen/WB_MainScreen.WB_MainScreen_C"));
	if (MAIN_SCREEN_WIDGET.Succeeded())
	{
		MainScreenClass = MAIN_SCREEN_WIDGET.Class;
	}
}

void UGZUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUIManager::Initialize!!"));

	GameInstance = GetTypedOuter<UGZGameInstance>();
	
	TArray<FName> NameArray;
	// UIMode �� UIState ������ ���̺�
	GameInstance->GetUILoadData(NameArray, UILoadDataArray);

	// UI ��ġ ��Ÿ������

	// �ܼ� ��� ���
}

void UGZUIManager::Deinitialize()
{
	if (IsValid(MainScreen))
	{
		MainScreen->RemoveFromParent();
		MainScreen = nullptr;
	}

	GameInstance = nullptr;
}

void UGZUIManager::Initialize(EGZUIMode UIMode)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUIManager::Initialize!! With UIMode = %d"), UIMode);

	// ���ν�ũ�� ����
	if (!IsValid(MainScreen))
	{
		MainScreen = CreateWidget<UGZUIMainScreen>(GameInstance, MainScreenClass);
		//MainScreen->OnScreenUIStateChanged.AddUObject(this, &ThisClass::OnScreenUIStateChanged);
	
		MainScreen->AddToViewport();
	}
	
	MainScreen->SetUIMode(UIMode);
}

void UGZUIManager::ChangeUIState(EGZUIState MainUIState)
{
	GZ_LOG(GZ, Warning, TEXT("UIManager::ChangeUIState  = %d / Solo"), MainUIState);

	if (IsValid(MainScreen))
	{
		//MainScreen->SetUIStateParam(FM1UIStateParam());
		MainScreen->ChangeUIState(MainUIState);
	}
}

EGZUIState UGZUIManager::GetUIState(EGZUIScreen TargetScreen) const
{
	return MainScreen->GetUIState();
}

FGZUILoadData UGZUIManager::GetUIStateData(EGZUIState UIState)
{
	check(UILoadDataArray.Num() > 0);

	FGZUILoadData NoneData;
	if (UIState == EGZUIState::None)
	{
		return NoneData;
	}

	// UILoadData �迭���� �ʿ��� �������� �ε��� ����.
	int32 RowIndex = UILoadDataArray.IndexOfByPredicate([&](const FGZUILoadData* UILoadData) {
		return (UILoadData->StateEnum == UIState);
	});

	ensure(RowIndex != INDEX_NONE);
	if (RowIndex == INDEX_NONE)
	{
		return NoneData;
	}

	// UILoadData ���� UIState�� ���� �ε�(Visible) ������ ����.
	FGZUILoadData* UILoadData = UILoadDataArray[RowIndex];

	// �������ͽ��� �ε��� �����͸� ã�µ� 
	return *UILoadData;
}

FString UGZUIManager::GetUINameByEnum(EGZUIName UIEnum) const
{
	//GZ_LOG(GZ, Warning, TEXT("UIManager::GetUINameByEnum, UIName = %d"), UIEnum);

	FString Result;

	switch (UIEnum)
	{
	case EGZUIName::Admin:								Result = TEXT("Admin");								break;
	case EGZUIName::Advertisement:						Result = TEXT("Advertisement");						break;
	case EGZUIName::Attention:							Result = TEXT("Attention");							break;
	case EGZUIName::BallIndicator:						Result = TEXT("BallIndicator");						break;
	case EGZUIName::BallSensor:							Result = TEXT("BallSensor");						break;
	case EGZUIName::ChallengeCelebration:				Result = TEXT("ChallengeCelebration");				break;
	case EGZUIName::ChallengeLevelUp:					Result = TEXT("ChallengeLevelUp");					break;
	case EGZUIName::ChallengeRanking:					Result = TEXT("ChallengeRanking");					break;
	case EGZUIName::ChallengeResult:					Result = TEXT("ChallengeResult");					break;
	case EGZUIName::ClubSelect:							Result = TEXT("ClubSelect");						break;
	case EGZUIName::CommonOption:						Result = TEXT("CommonOption");						break;
	case EGZUIName::CommonPopup:						Result = TEXT("CommonPopup");						break;
	case EGZUIName::ContactLesson:						Result = TEXT("HoleTimeSetting");					break;
	case EGZUIName::FinalResult:						Result = TEXT("FinalResult");						break;
	case EGZUIName::GoodsSelect:						Result = TEXT("GoodsSelect");						break;
	case EGZUIName::GroundAttribute:					Result = TEXT("GroundAttribute");					break;
	case EGZUIName::GTMTime:							Result = TEXT("GTMTime");							break;
	case EGZUIName::GuestTimeSelect:					Result = TEXT("GuestTimeSelect");					break;
	case EGZUIName::IdleRank:							Result = TEXT("IdleRank");							break;
	case EGZUIName::InterimResult:						Result = TEXT("InterimResult");						break;
	case EGZUIName::Loading:							Result = TEXT("Loading");							break;
	case EGZUIName::LocationSelect:						Result = TEXT("LocationSelect");					break;
	case EGZUIName::Login:								Result = TEXT("Login");								break;
	case EGZUIName::Menu:								Result = TEXT("Menu");								break;
	case EGZUIName::ModeInfo:							Result = TEXT("ModeInfo");							break;
	case EGZUIName::Nasmo:								Result = TEXT("Nasmo");								break;
	case EGZUIName::NasmoAuto:							Result = TEXT("NasmoAuto");							break;
	case EGZUIName::Network:							Result = TEXT("Network");							break;
	case EGZUIName::Notice:								Result = TEXT("Notice");							break;
	case EGZUIName::Password:							Result = TEXT("Password");							break;
	case EGZUIName::PlayerDetail:						Result = TEXT("PlayerDetail");						break;
	case EGZUIName::PlayerInfo:							Result = TEXT("PlayerInfo");						break;
	case EGZUIName::RoundOption:						Result = TEXT("RoundOption");						break;
	case EGZUIName::ScreenMinimap:						Result = TEXT("ScreenMinimap");						break;
	case EGZUIName::SensorReady:						Result = TEXT("SensorReady");						break;
	case EGZUIName::ShotDataClub:						Result = TEXT("ShotDataClub");						break;
	case EGZUIName::ShotDataRange:						Result = TEXT("ShotDataRange");						break;
	case EGZUIName::ShotHeight:							Result = TEXT("ShotHeight");						break;
	case EGZUIName::ShotResult:							Result = TEXT("ShotResult");						break;
	case EGZUIName::ShowCombo:							Result = TEXT("ShowCombo");							break;
	case EGZUIName::TargetInfo:							Result = TEXT("TargetInfo");						break;
	case EGZUIName::TargetShow:							Result = TEXT("TargetShow");						break;
	case EGZUIName::TeeHeight:							Result = TEXT("TeeHeight");							break;
	case EGZUIName::None:
	default:
		Result = TEXT("None");
		break;
	}

	return Result;
}

bool UGZUIManager::IsOpenedUI(EGZUIName UIEnum)
{
	// ���� �ε�Ǿ� �ִ� UI�߿��� ����(visible)�Ǿ� �ִ� �� üũ.
	UGZUIComponent* UIComponent;
	UIComponent = FindUIComponentByEnum(UIEnum);
	if (UIComponent != nullptr)
	{
		return UIComponent->GetIsVisible();
	}

	return false;
}

bool UGZUIManager::IsOpenedUIByName(FString UIName)
{
	
	return true;
}

UGZUIComponent* UGZUIManager::FindUIComponentByEnum(EGZUIName UIEnum)
{
	// ���� ��ũ���� �ε�� UI�߿��� ã��.
	TArray<UGZUIComponent*> UIComponentArray;
	UIComponentArray = MainScreen->GetUIComponentsOnScreen();
	for (UGZUIComponent* UIComponent : UIComponentArray)
	{
		if (UIComponent->GetUIEnum() == UIEnum)
		{
			return UIComponent;
		}
	}
	return nullptr;
}

UGZUIScreenBase* UGZUIManager::GetUIScreenWidget(EGZUIScreen UIScreen)
{
	if (UIScreen != EGZUIScreen::Main)
	{
		return nullptr;
	}

	return MainScreen;
}

FGZUIInfoData UGZUIManager::GetUIInfoData(UClass* TargetClass)
{
	FGZUIInfoData NoneData;

	if (UIInfoDataArray.Num() <= 0)
	{
		return NoneData;
	}

	int32 RowIndex = UIInfoDataArray.IndexOfByPredicate([&](const FGZUIInfoData* InfoData) {
		return (InfoData->WidgetBlueprintClass == TargetClass);
		});

	if (RowIndex == INDEX_NONE)
	{
		GZ_LOG(GZ, Warning, TEXT("UIManager::GetUIInfoData() is Empty, UIName = %s"), *TargetClass->GetName());
		return NoneData;
	}

	return *UIInfoDataArray[RowIndex];
}

UGZUIManager& UGZUIManager::GetUIManager()
{
	// GameInstance�� �ν��Ͻ̵� UIManager ��������.
	return *UGZGameInstance::GetSubsystem<UGZUIManager>(GameInstance);
}