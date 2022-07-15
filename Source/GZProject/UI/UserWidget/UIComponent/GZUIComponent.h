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
	/** 스크린 레이어 타입 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	EGZUIScreenLayerType UIScreenLayerType;

	/** UI 위치 데이터 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	FAnchorData PositionData;

	/** UI 스케일 적용 유무 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ", AdvancedDisplay, meta = (DisplayName = "Size To Content"))
	bool bAutoSize;

	/** 레이어에서의 뎁스 넘버 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	int32 ZOrder;
};

/**
 * UIWidget을 만들기 위한 베이스 클래스
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

	/** 위젯의 초기화가 필요한 경우 */
	virtual void InitializeWidget() {}

	/** 미리 만들어진 애니메이션이 플레이된 후 */
	virtual void PostConstructAnimPlayed();

	/** 제거 애니메이션 시작 */
	virtual bool BeginDestructAnim();

	/** 생성될때 애니메이션 플레이 */
	bool PlayConstructAnim();

	/** 제거될때 애니메이션 플레이 */
	bool PlayDestructAnim();

	/**
	* UIEnum 설정
	* @param UIEnum
	*/
	void SetUIEnum(EGZUIName InUIEnum);

	/** UIEnum 을 리턴함 */
	EGZUIName GetUIEnum() const { return UIEnum; }

	/* UI 이름을 리턴함	*/
	FString GetUIName() const;

protected:
	/** 컨텐츠에 따라 UIEvent Broadcast */
	void BroadcastUIEvent(FGZUIEventParam UIEvent);

public:
	FOnUIEvent OnUIEvent;

public:
	/** UIInfoData */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FGZUIInfoData UIInfoData;

	/** UIComponent을 소유하고 있는 스크린 */
	EGZUIScreen OwnerScreen = EGZUIScreen::None;

protected:
	/** 현재 UIEnum */
	EGZUIName UIEnum;

};
