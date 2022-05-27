// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIMainScreen.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"

UGZUIMainScreen::UGZUIMainScreen(const FObjectInitializer& ObjectInitializer)
	:UGZUIScreenBase(ObjectInitializer)
{
	
}

void UGZUIMainScreen::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	for (UGZUIComponent* UIComponent : UIComponentsOnScreen)
	{
		UIComponent->RemoveFromParent();
	}

	UIComponentsOnScreen.Reset();
}

void UGZUIMainScreen::SetUIMode(EGZUIMode NewUIMode)
{
	Super::SetUIMode(NewUIMode);

	GZ_LOG(GZ, Warning, TEXT("UIMainScreen::SetUIMode = %d"), NewUIMode);
}
