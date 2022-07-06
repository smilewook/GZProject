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

	// UI �ʱ�ȭ
	InitializeUI();
}

void AGZGameModeBase::InitializeUI()
{
	// ���� ���ÿ� �⺻���� �����س��� �ϴ� �������.
}