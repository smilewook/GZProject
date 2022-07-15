// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"

#include "Components/CanvasPanelSlot.h"
#include "UI/Define/GZUIDefine.h"
#include "UI/Event/GZUIEvent.h"
#include "UI/Event/GZUIEventListener.h"
#include "UI/System/GZUIManager.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"
#include "UI/UMG/Blueprint/GZEventAnimUserWidget.h"
#include "UI/UMG/Blueprint/GZWidgetEventAnimDefine.h"
#include "GZUIComponent.generated.h"

USTRUCT(BlueprintType)
struct FGZUIInfoData
{
	GENERATED_USTRUCT_BODY()

public:
	/** ��ũ�� ���̾� Ÿ�� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	EGZUIScreenLayerType UIScreenLayerType;

	/** UI ��ġ ������ */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	FAnchorData PositionData;

	/** UI ������ ���� ���� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ", AdvancedDisplay, meta = (DisplayName = "Size To Content"))
	bool bAutoSize;

	/** ���̾���� ���� �ѹ� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	int32 ZOrder;
};

/**
 * UIWidget�� ����� ���� ���̽� Ŭ����
 */
UCLASS()
class GZPROJECT_API UGZUIComponent : public UGZEventAnimUserWidget
{
	GENERATED_BODY()
	
public:
	UGZUIComponent(const FObjectInitializer& ObjectInitailizer);

public:
	//~ Begin UObject Interface
	virtual void PostLoad() override;
	//~ End UObject Interface
	
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	//~ End UUserWidget Interface

	/** ������ �ʱ�ȭ�� �ʿ��� ��� */
	virtual void InitializeWidget() {}

	/** �̸� ������� �ִϸ��̼��� �÷��̵� �� */
	virtual void PostConstructAnimPlayed();

	/** ���� �ִϸ��̼� ���� */
	virtual bool BeginDestructAnim();

	/** �����ɶ� �ִϸ��̼� �÷��� */
	bool PlayConstructAnim();

	/** ���ŵɶ� �ִϸ��̼� �÷��� */
	bool PlayDestructAnim();

	/**
	* UIEnum ����
	* @param UIEnum
	*/
	void SetUIEnum(EGZUIName InUIEnum);

	/** UIEnum �� ������ */
	EGZUIName GetUIEnum() const { return UIEnum; }

	/* UI �̸��� ������	*/
	FString GetUIName() const;

protected:
	/** �������� ���� UIEvent Broadcast */
	void BroadcastUIEvent(FGZUIEventParam UIEvent);

public:
	FOnUIEvent OnUIEvent;

public:
	/** UIInfoData */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FGZUIInfoData UIInfoData;

	/** UIComponent�� �����ϰ� �ִ� ��ũ�� */
	EGZUIScreen OwnerScreen = EGZUIScreen::None;

protected:
	/** ���� UIEnum */
	EGZUIName UIEnum;

};
