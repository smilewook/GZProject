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

	/** 델리케이트 등록 */
	virtual void RegisterDelegates() {}

	/** 델리게이트 해제 */
	virtual void UnregisterDelegates() {}

	/** 초기화 되었는지 */
	bool IsInitialized() { return bInitialized; }
	
protected:
	//~ Begin UUserWidget Interface
	virtual void OnWidgetRebuilt() override;
	//~ End UUserWidget Interface

	/** 애니메이션 이름을 전달받아 인덱스값을 리턴 */
	int32 GetAnimationIndexFromName(FString WidgetAnimationName);

	/** 애니메이션 이름을 전달받아 포인터를 리턴 */
	UWidgetAnimation* GetAnimationFromName(FString WidgetAnimationName);

	bool IsUITestWorld();
};
