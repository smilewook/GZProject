// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIComponent.h"
#include "UI/System/GZUIManager.h"

UGZUIComponent::UGZUIComponent(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
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
}

void UGZUIComponent::NativeDestruct()
{
	Super::NativeDestruct();
}

void UGZUIComponent::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
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
