// Fill out your copyright notice in the Description page of Project Settings.


#include "GZGameModeBase.h"
#include "UI/System/GZUIManager.h"


AGZGameModeBase::AGZGameModeBase()
{
	PlayerControllerClass = APlayerController::StaticClass();
}

AGZGameModeBase::~AGZGameModeBase()
{
}

void AGZGameModeBase::StartPlay()
{
	Super::StartPlay();
}

void AGZGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// UI 초기화
	InitializeUI();
}

void AGZGameModeBase::InitializeUI()
{
	// 레벨 세팅에 기본으로 적용해놔서 일단 사용하자.
}