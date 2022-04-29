// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIManager.h"
#include "GZGameInstance.h"
#include "UI/UserWidget/UIScreen/GZUIScreenBase.h"


UGZGameInstance* UGZUIManager::GameInstance;

UGZUIManager::UGZUIManager()
{
	GZ_LOG_S(GZ, Warning);

	// 메인 스크린 클래스 블루프린트 위젯
	static ConstructorHelpers::FClassFinder<UGZUIScreenBase> MAIN_SCREEN_WIDGET(TEXT("/Game/UI/WidgetBlueprint/UIScreen/WB_Screen.WB_Screen_C"));
	if (MAIN_SCREEN_WIDGET.Succeeded())
	{
		MainScreenClass = MAIN_SCREEN_WIDGET.Class;
	}
}

void UGZUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUIManager::Initialize!!"));

	GameInstance = GetTypedOuter<UGZGameInstance>();
	
	// UIMode 및 UIState 데이터 테이블

	// UI 배치 메타데이터

	// 콘솔 명령 등록
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

void UGZUIManager::Initialize(EGZUIMode EUIMode)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUIManager::Initialize!! With UIMode"));

	// 메인스크린 생성
	if (!IsValid(MainScreen))
	{
		MainScreen = CreateWidget<UGZUIScreenBase>(GameInstance, MainScreenClass);
		//MainScreen->OnScreenUIStateChanged.AddUObject(this, &ThisClass::OnScreenUIStateChanged);
	
		MainScreen->AddToViewport();
	}
	
	//MainScreen->SetUIMode(MainScreenUIMode);
}

void UGZUIManager::ChangeUIState(EGZUIMode MainUIState)
{
	GZ_LOG(GZ, Warning, TEXT("UIManager::ChangeUIState  = %s / Solo"), *GetUIStateNameByEnum(MainUIState));

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

FString UGZUIManager::GetUIStateNameByEnum(EGZUIState UIState)
{
	//GZ_LOG(GZ, Warning, TEXT("UIManager::GetUIStateNameByEnum, UIState = %d"), UIState);

	FString Result;

	switch (UIState)
	{
	case EGZUIState::AdminSetting:					Result = TEXT("AdminSetting");						break;
	case EGZUIState::AnalysisHole:					Result = TEXT("AnalysisHole");						break;
	case EGZUIState::CCSelection:					Result = TEXT("CCSelection");						break;
	case EGZUIState::CoursePreview:					Result = TEXT("CoursePreview");						break;
	case EGZUIState::DropBall:						Result = TEXT("DropBall");							break;
	case EGZUIState::ExitProgram:					Result = TEXT("ExitProgram");						break;
	case EGZUIState::GameEnd:						Result = TEXT("GameEnd");							break;
	case EGZUIState::GreenUndulation:				Result = TEXT("GreenUndulation");					break;
	case EGZUIState::HoleEnd:						Result = TEXT("HoleEnd");							break;
	case EGZUIState::HoleTimeSetting:				Result = TEXT("HoleTimeSetting");					break;
	case EGZUIState::Intro:							Result = TEXT("Intro");								break;
	case EGZUIState::Loading:						Result = TEXT("Loading");							break;
	case EGZUIState::LowView:						Result = TEXT("LowView");							break;
	case EGZUIState::Menu:							Result = TEXT("Menu");								break;
	case EGZUIState::ModeSelection:					Result = TEXT("ModeSelection");						break;
	case EGZUIState::PlayerRegistration:			Result = TEXT("PlayerRegistration");				break;
	case EGZUIState::PlayerSetting:					Result = TEXT("PlayerSetting");						break;
	case EGZUIState::Replay:						Result = TEXT("Replay");							break;
	case EGZUIState::RoundBoard:					Result = TEXT("RoundBoard");						break;
	case EGZUIState::Scorecard:						Result = TEXT("Scorecard");							break;
	case EGZUIState::Shot:							Result = TEXT("Shot");								break;
	case EGZUIState::ShotEnd:						Result = TEXT("ShotEnd");							break;
	case EGZUIState::ShotReady:						Result = TEXT("ShotReady");							break;
	case EGZUIState::TimeSetting:					Result = TEXT("TimeSetting");						break;
	case EGZUIState::None:
	default:
		Result = TEXT("None");
		break;
	}

	return Result;
}

UGZUIScreenBase* UGZUIManager::GetUIScreenWidget(EGZUIScreen UIScreen)
{
	if (UIScreen != EGZUIScreen::Main)
	{
		return nullptr;
	}

	return MainScreen;
}

UGZUIManager& UGZUIManager::GetUIManager()
{
	// GameInstance에 인스턴싱된 UIManager 가져오기.
	return *UGZGameInstance::GetSubsystem<UGZUIManager>(GameInstance);
}