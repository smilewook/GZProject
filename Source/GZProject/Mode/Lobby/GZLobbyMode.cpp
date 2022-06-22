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

	// UI 초기화
	InitializeUI();

	// Lobby State 이벤트에 대한 리스닝 시작
	//FM1MainDelegate::OnLobbyStateChanged.AddUObject(this, &AM1LobbyMode::OnLobbyStateChanged);

	// State 상태를 로딩 상태로 전환
	// StateManager를 만들어서 상태 전환 해줄 것.
}

void AGZLobbyMode::InitializeUI()
{
	EGZUIMode UIMode;
	UIMode = EGZUIMode::Lobby;

	UGZUIManager::GetUIManager().Initialize(UIMode);
}