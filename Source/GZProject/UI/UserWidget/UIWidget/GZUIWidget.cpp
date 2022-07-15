// Fill out your copyright notice in the Description page of Project Settings.

#include "GZUIWidget.h"
#include "UI/System/GZUIManager.h"


UGZUIWidget::UGZUIWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	PaletteCategory = FText::FromString(TEXT("UIWidget"));
#endif
}

void UGZUIWidget::SetVisibility(ESlateVisibility InVisibility)
{
	bool bPlayAnim = false;
	ESlateVisibility CurVisibility = GetVisibility();
	if ((CurVisibility == ESlateVisibility::Collapsed || CurVisibility == ESlateVisibility::Hidden) &&
		(InVisibility == ESlateVisibility::Visible || InVisibility == ESlateVisibility::SelfHitTestInvisible || InVisibility == ESlateVisibility::HitTestInvisible))
	{
		bPlayAnim = true;
	}

	Super::SetVisibility(InVisibility);

	if (bPlayAnim)
	{
		PlayAnimByEvent(EGZWidgetAnimType::WAT_ON_SET_IS_VISIBLE);
	}
}

void UGZUIWidget::NativeConstruct()
{
	OwnerScreen = OwnerUIComponent->OwnerScreen;

	Super::NativeConstruct();

	PlayConstructAnim();
}

void UGZUIWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

bool UGZUIWidget::BeginDestructAnim(bool bRemoveFromParent /*= false*/)
{
	// �ִϸ��̼��� �÷����� �� ���� �������� Ȯ��
	ESlateVisibility WidgetVisibility = GetVisibility();
	if (WidgetVisibility == ESlateVisibility::Collapsed ||
		WidgetVisibility == ESlateVisibility::Hidden)
	{
		// ���� ó��
		if (bRemoveFromParent)
		{
			RemoveFromParent();
		}
		return false;
	}

	// Destruct Animation�� �÷�����
	bool bHasDestructAnim = PlayDestructAnim();
	if (!bHasDestructAnim)
	{
		// �ִϸ��̼��� ���ٸ� ���� ó��
		if (bRemoveFromParent)
		{
			RemoveFromParent();
		}
		return false;
	}

	return true;
}

bool UGZUIWidget::PlayConstructAnim()
{
	return PlayAnimByEvent(EGZWidgetAnimType::WAT_ON_CONSTRUCT);
}

bool UGZUIWidget::PlayDestructAnim()
{
	return PlayAnimByEvent(EGZWidgetAnimType::WAT_BEFORE_DESTRUCT);
}

void UGZUIWidget::BroadcastUIEvent(FGZUIEventParam UIEvent)
{
	if (OwnerUIComponent.IsNull())
	{
		return;
	}

	OwnerUIComponent->OnUIEvent.Broadcast(UIEvent);
}