// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UMG/Blueprint/GZUserWidget.h"

void UGZUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGZUserWidget::NativeDestruct()
{
	Super::NativeDestruct();

	// UMG 에디팅을 하면 메모리 상에 올라와 있는 이전 위젯을 삭제하는데 델리게이트 삭제 로직타면서 문제가 다수 있어 예외처리함
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
	// 위젯이 생성된 후 실행됨.
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