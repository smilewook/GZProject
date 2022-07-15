// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIIntro.h"

void UGZUIIntro::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGZUIIntro::RegisterDelegates()
{
	UGZUIManager::GetUIManager().SetOnUIStateChanged(EGZUIScreen::Main, this, &ThisClass::OnChangeMainUIState);
}

void UGZUIIntro::UnregisterDelegates()
{
	UGZUIManager::GetUIManager().ClearOnUIStateChanged(this);
}

void UGZUIIntro::OnChangeMainUIState(EGZUIState NewUIState)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUIIntro::OnChangeMainUIState!! w/ NewUIState = %d"), NewUIState);
}