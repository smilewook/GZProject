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

	GZ_LOG_S(GZ, Warning);

	//UGZUIManager
}