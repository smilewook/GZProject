// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;
	//~ End UUserWidget Interface

	/** ��������Ʈ ��� */
	virtual void RegisterDelegates() {}

	/** ��������Ʈ ���� */
	virtual void UnregisterDelegates() {}

	/** �ʱ�ȭ �Ǿ����� */
	bool IsInitialized() { return bInitialized; }
	
protected:
	//~ Begin UUserWidget Interface
	virtual void OnWidgetRebuilt() override;
	//~ End UUserWidget Interface

	/** �ִϸ��̼� �̸��� ���޹޾� �ε������� ���� */
	int32 GetAnimationIndexFromName(FString WidgetAnimationName);

	/** �ִϸ��̼� �̸��� ���޹޾� �����͸� ���� */
	UWidgetAnimation* GetAnimationFromName(FString WidgetAnimationName);

	bool IsUITestWorld();
};
