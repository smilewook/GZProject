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
	// ��ä�� �ε�� �� �� ȣ���.
	Super::PostLoad();
}

void UGZUIComponent::NativeConstruct()
{
	// ��ä�� ����Ʈ�� ������ ȣ���.
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
