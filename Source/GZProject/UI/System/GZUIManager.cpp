// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIManager.h"
#include "../../GZGameInstance.h"

UGZGameInstance* UGZUIManager::GameInstance;

UGZUIManager::UGZUIManager()
{
	GZ_LOG_S(GZ, Warning);
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
	GameInstance = nullptr;
}

void UGZUIManager::Initialize(EGZUIMode UIMode)
{
}

UGZUIManager& UGZUIManager::GetUIManager()
{
	// GameInstance에 인스턴싱된 UIManager 가져오기.
	return *UGZGameInstance::GetSubsystem<UGZUIManager>(GameInstance);
}