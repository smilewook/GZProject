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

	// UI √ ±‚»≠
	InitializeUI();
}

void AGZLobbyMode::InitializeUI()
{
	EGZUIMode UIMode;
	UIMode = EGZUIMode::Lobby;

	UGZUIManager::GetUIManager().Initialize(UIMode);
}