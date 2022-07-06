// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/Define/GZUIDefine.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"
#include "GZUIComponent.generated.h"

USTRUCT(BlueprintType)
struct FGZUIInfoData
{
	GENERATED_USTRUCT_BODY()

public:
	/** 스크린 레이어 타입 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	EGZUIScreenLayerType UIScreenLayerType;

	/** UI 위치 데이터*/
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
class GZPROJECT_API UGZUIComponent : public UUserWidget
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

	/**
	* UIEnum 설정
	* @param UIEnum
	*/
	void SetUIEnum(EGZUIName InUIEnum);

	/**
	* UIEnum 을 리턴함.
	*/
	EGZUIName GetUIEnum() const { return UIEnum; }

	/**
	* UI 이름을 리턴함.
	*/
	FString GetUIName() const;

public:
	/** UIInfoData */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FGZUIInfoData UIInfoData;

protected:
	/** 현재 UIEnum */
	EGZUIName UIEnum;

};
