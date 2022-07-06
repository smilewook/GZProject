// Fill out your copyright notice in the Description page of Project Settings.


#include "GZGameMode.h"
#include "UI/System/GZUIManager.h"


AGZGameMode::AGZGameMode()
{
	PlayerControllerClass = APlayerController::StaticClass();
}

AGZGameMode::~AGZGameMode()
{
}

void AGZGameMode::StartPlay()
{
	Super::StartPlay();

	//GZ_LOG_S(GZ, Warning);

	//UGZUIManager
}

void AGZGameMode::BeginPlay()
{
	Super::BeginPlay();

	// UI √ ±‚»≠
	InitializeUI();
}

void AGZGameMode::InitializeUI()
{
	//
}