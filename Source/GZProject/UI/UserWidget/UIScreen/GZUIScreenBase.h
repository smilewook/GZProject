// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/Define/GZDefine.h"
#include "GZUIScreenBase.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIScreenBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UGZUIScreenBase(const FObjectInitializer& ObjectInitailizer);

public:
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	//~ End UUserWidget Interface	

	/**
	* UI STATE를 리턴함
	* @return EGZUIState 현재 UIState
	*/
	//EGZUIState GetUIState() const { return CurStateData.StateName; }

};
