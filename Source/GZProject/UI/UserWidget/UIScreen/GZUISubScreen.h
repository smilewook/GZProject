// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidget/UIScreen/GZUIScreenBase.h"
#include "GZUISubScreen.generated.h"

/**
 * 서브로 사용할 스크린 클래스(서브는 늘어날 수 있다?)
 */
UCLASS(config = UI)
class GZPROJECT_API UGZUISubScreen : public UGZUIScreenBase
{
	GENERATED_BODY()
	
public:
	UGZUISubScreen(const FObjectInitializer& ObjectInitializer);

	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//virtual void RemoveFromParent() override;
	//~ End UUserWidget Interface

	// 윈도우 생성
	virtual void CreateSlateWindow() {}

};
