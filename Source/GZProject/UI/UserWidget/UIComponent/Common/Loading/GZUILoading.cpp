// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUILoading.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "UI/System/GZUIManager.h"

void UGZUILoading::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGZUILoading::RegisterDelegates()
{
	UGZUIManager::GetUIManager().SetOnUIStateChanged(EGZUIScreen::Main, this, &ThisClass::OnChangeMainUIState);
}

void UGZUILoading::UnregisterDelegates()
{
	UGZUIManager::GetUIManager().ClearOnUIStateChanged(this);
}

void UGZUILoading::OnChangeMainUIState(EGZUIState NewUIState)
{
	GZ_LOG(GZ, Warning, TEXT("UGZUILoading::OnChangeMainUIState!! w/ NewUIState = %d"), NewUIState);
}

void UGZUILoading::OnLoadingProgress(float ProgressPercent)
{
	ProgressBar->SetPercent(ProgressPercent);
}