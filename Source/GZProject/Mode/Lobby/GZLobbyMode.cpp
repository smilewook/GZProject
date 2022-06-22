// Fill out your copyright notice in the Description page of Project Settings.


#include "GZLobbyMode.h"
#include "UI/System/GZUIManager.h"


AGZLobbyMode::AGZLobbyMode()
{
	PlayerControllerClass = APlayerController::StaticClass();
}

AGZLobbyMode::~AGZLobbyMode()
{
}

void AGZLobbyMode::StartPlay()
{
	Super::StartPlay();

	//GZ_LOG_S(GZ, Warning);

	//UGZUIManager
}

void AGZLobbyMode::BeginPlay()
{
	Super::BeginPlay();

	// UI �ʱ�ȭ
	InitializeUI();

	// Lobby State �̺�Ʈ�� ���� ������ ����
	//FM1MainDelegate::OnLobbyStateChanged.AddUObject(this, &AM1LobbyMode::OnLobbyStateChanged);

	// State ���¸� �ε� ���·� ��ȯ
	// StateManager�� ���� ���� ��ȯ ���� ��.
}

void AGZLobbyMode::InitializeUI()
{
	EGZUIMode UIMode;
	UIMode = EGZUIMode::Lobby;

	UGZUIManager::GetUIManager().Initialize(UIMode);
}