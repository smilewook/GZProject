// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UMG/Blueprint/GZUserWidget.h"

void UGZUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGZUserWidget::NativeDestruct()
{
	Super::NativeDestruct();

	// UMG �������� �ϸ� �޸� �� �ö�� �ִ� ���� ������ �����ϴµ� ��������Ʈ ���� ����Ÿ�鼭 ������ �ټ� �־� ����ó����
	if (bInitialized && !IsDesignTime() && !IsUITestWorld())
	{
		UnregisterDelegates();
	}
}

void UGZUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UGZUserWidget::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnAddedToFocusPath(InFocusEvent);
}

void UGZUserWidget::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnRemovedFromFocusPath(InFocusEvent);
}

void UGZUserWidget::OnWidgetRebuilt()
{
	// ������ ������ �� �����.
	UUserWidget::OnWidgetRebuilt();

	if (bInitialized && !IsDesignTime() && !IsUITestWorld())
	{
		RegisterDelegates();
	}
}

int32 UGZUserWidget::GetAnimationIndexFromName(FString WidgetAnimationName)
{
	UWidgetBlueprintGeneratedClass* WidgetBPGeneratedClass = Cast<UWidgetBlueprintGeneratedClass>(GetClass());
	if (WidgetBPGeneratedClass == nullptr)
		return INDEX_NONE;

	return WidgetBPGeneratedClass->Animations.IndexOfByPredicate([&](const UWidgetAnimation* WidgetAnimation) {
		return (WidgetAnimation->GetName() == WidgetAnimationName);
		});
}

UWidgetAnimation* UGZUserWidget::GetAnimationFromName(FString WidgetAnimationName)
{
	int32 Index = GetAnimationIndexFromName(WidgetAnimationName);
	if (Index == INDEX_NONE)
		return nullptr;

	UWidgetBlueprintGeneratedClass* WidgetBPGeneratedClass = Cast<UWidgetBlueprintGeneratedClass>(GetClass());

	return WidgetBPGeneratedClass->Animations[Index];
}

bool UGZUserWidget::IsUITestWorld()
{
	if (!IsValid(GetWorld()))
	{
		return false;
	}

// 	AGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode();
// 	if (!IsValid(GameModeBase)/* || GameModeBase->GetClass() != AGZUITestGameMode::StaticClass()*/)
// 	{
// 		return false;
// 	}

	return true;
}