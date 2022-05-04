// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIComponent.h"

UGZUIComponent::UGZUIComponent(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
	UIName = TEXT("NoName");
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

void UGZUIComponent::SetUIName(FString InUIName)
{
	UIName = InUIName;
}

FString UGZUIComponent::GetUIName()
{
	if (UIName.IsEmpty())
	{
		UIName = TEXT("NoName");
	}
	
	return UIName;
}
