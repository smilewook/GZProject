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
	
	// UIMode �� UIState ������ ���̺�

	// UI ��ġ ��Ÿ������

	// �ܼ� ��� ���
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
	// GameInstance�� �ν��Ͻ̵� UIManager ��������.
	return *UGZGameInstance::GetSubsystem<UGZUIManager>(GameInstance);
}