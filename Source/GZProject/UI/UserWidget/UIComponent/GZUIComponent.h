// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Blueprint/UserWidget.h"
#include "UI/Define/GZDefine.h"
#include "GZUIComponent.generated.h"

/**
 * 
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
	* UI 이름 설정
	* @param UIName을 설정
	*/
	void SetUIName(FString InUIName);

	/**
	* UI 이름을 리턴함.
	*/
	FString GetUIName();

protected:
	/** 현재 UIName */
	FString UIName;

};
