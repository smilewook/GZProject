// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIMainScreen.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"

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

	//if (NewUIMode != EGZUIMode::Lobby && ClickBlocker != nullptr)
	//{
	//	ClickBlocker->SetVisibility(ESlateVisibility::Hidden);
	//}

	/** 스크린 레이어 타입에 따른 컨텐츠 레이어 선택 */
	UCanvasPanel* ContentCanvasPanel = UIScreenLayer->GetLayerCanvasPanel(EGZUIScreenLayerType::Contents);
	if (IsValid(ContentCanvasPanel))
	{
		UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(ContentCanvasPanel->Slot);
		if (IsValid(CanvasPanelSlot))
		{
			//FMargin Offsets = GET_ADMIN_GUI_SETTING()->GetOffsets();

			//CanvasPanelSlot->SetOffsets(Offsets);
		}
	}
}
