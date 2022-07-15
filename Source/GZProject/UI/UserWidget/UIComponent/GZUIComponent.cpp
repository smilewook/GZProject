// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIComponent.h"

UGZUIComponent::UGZUIComponent(const FObjectInitializer& ObjectInitializer)
	:UGZEventAnimUserWidget(ObjectInitializer)
{
	UIEnum = EGZUIName::None;
}

void UGZUIComponent::PostLoad()
{
	// 개채가 로드된 직 후 호출됨.
	Super::PostLoad();
}

void UGZUIComponent::NativeConstruct()
{
	// 개채가 뷰포트에 붙으면 호출됨.
	Super::NativeConstruct();

	// 위젯의 초기화가 필요한 경우.
	InitializeWidget();
}

void UGZUIComponent::NativeDestruct()
{
	Super::NativeDestruct();
}

void UGZUIComponent::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UGZUIComponent::PostConstructAnimPlayed()
{

}

bool UGZUIComponent::BeginDestructAnim()
{
	UnregisterDelegates();

	ESlateVisibility WidgetVisibility = GetVisibility();
	if (WidgetVisibility == ESlateVisibility::Collapsed || WidgetVisibility == ESlateVisibility::Hidden)
	{
		return false;
	}

	bool bDestructAnimPlayed = PlayDestructAnim();
	if (!bDestructAnimPlayed)
	{
		return false;
	}

	return true;
}

bool UGZUIComponent::PlayConstructAnim()
{
	return PlayAnimByEvent(EGZWidgetAnimType::WAT_ON_CONSTRUCT);
}

bool UGZUIComponent::PlayDestructAnim()
{
	return PlayAnimByEvent(EGZWidgetAnimType::WAT_BEFORE_DESTRUCT);
}

void UGZUIComponent::BroadcastUIEvent(FGZUIEventParam UIEvent)
{
	UIEvent.UIScreen = OwnerScreen;

	OnUIEvent.Broadcast(UIEvent);
}

void UGZUIComponent::SetUIEnum(EGZUIName InUIEnum)
{
	UIEnum = InUIEnum;
}

FString UGZUIComponent::GetUIName() const
{
	FString UIName;
	if (UIEnum == EGZUIName::None)
	{
		UIName = TEXT("NoName");
	}
	else
	{
		UIName = UGZUIManager::GetUIManager().GetUINameByEnum(UIEnum);
	}
	
	return UIName;
}
