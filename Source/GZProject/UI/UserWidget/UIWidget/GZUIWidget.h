// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Define/GZUIDefine.h"
#include "UI/Event/GZUIEvent.h"
#include "UI/Event/GZUIEventListener.h"
#include "UI/UMG/Blueprint/GZEventAnimUserWidget.h"
#include "UI/UMG/Blueprint/GZWidgetEventAnimDefine.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "GZUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIWidget : public UGZEventAnimUserWidget
{
	GENERATED_BODY()
	
public:
	UGZUIWidget(const FObjectInitializer& ObjectInitializer);

	//~ Begin UWidget Interface
	virtual void SetVisibility(ESlateVisibility InVisibility) override;
	//~ End UWidget Interface

	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//~ End UUserWidget Interface

	/** 제거 애니메이션 시작 */
	virtual bool BeginDestructAnim(bool bRemoveFromParent = false);

protected:	
	/** 생성될때 애니메이션 플레이 */
	bool PlayConstructAnim();

	/** 제거될때 애니메이션 플레이 */
	bool PlayDestructAnim();

	/**  위젯에 따라 UIEvent Broadcast */
	void BroadcastUIEvent(FGZUIEventParam UIEvent);

protected:
	/** UIWidget을 소유하고 있는 스크린 */
	EGZUIScreen OwnerScreen = EGZUIScreen::None;

	/** UIWidget의 부모 UIComponent */
	UPROPERTY(Transient)
	TObjectPtr<class UGZUIComponent> OwnerUIComponent;

};
