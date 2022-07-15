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

	/** ���� �ִϸ��̼� ���� */
	virtual bool BeginDestructAnim(bool bRemoveFromParent = false);

protected:	
	/** �����ɶ� �ִϸ��̼� �÷��� */
	bool PlayConstructAnim();

	/** ���ŵɶ� �ִϸ��̼� �÷��� */
	bool PlayDestructAnim();

	/**  ������ ���� UIEvent Broadcast */
	void BroadcastUIEvent(FGZUIEventParam UIEvent);

protected:
	/** UIWidget�� �����ϰ� �ִ� ��ũ�� */
	EGZUIScreen OwnerScreen = EGZUIScreen::None;

	/** UIWidget�� �θ� UIComponent */
	UPROPERTY(Transient)
	TObjectPtr<class UGZUIComponent> OwnerUIComponent;

};
