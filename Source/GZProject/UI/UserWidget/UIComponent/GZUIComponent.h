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
	/** ��ũ�� ���̾� Ÿ�� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
	EGZUIScreenLayerType UIScreenLayerType;

	/** UI ��ġ ������*/
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
	* UIEnum ����
	* @param UIEnum
	*/
	void SetUIEnum(EGZUIName InUIEnum);

	/**
	* UIEnum �� ������.
	*/
	EGZUIName GetUIEnum() const { return UIEnum; }

	/**
	* UI �̸��� ������.
	*/
	FString GetUIName() const;

public:
	/** UIInfoData */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FGZUIInfoData UIInfoData;

protected:
	/** ���� UIEnum */
	EGZUIName UIEnum;

};
