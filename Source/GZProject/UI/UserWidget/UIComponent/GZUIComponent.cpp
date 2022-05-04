// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIComponent.h"

UGZUIComponent::UGZUIComponent(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
	UIName = TEXT("NoName");
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
