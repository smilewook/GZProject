// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidget/UIScreen/GZUIScreenBase.h"
#include "GZUISubScreen.generated.h"

/**
 * ����� ����� ��ũ�� Ŭ����(����� �þ �� �ִ�?)
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

	// ������ ����
	virtual void CreateSlateWindow() {}

};
