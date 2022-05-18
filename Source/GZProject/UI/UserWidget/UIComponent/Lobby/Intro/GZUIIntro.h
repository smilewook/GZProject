// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "GZUIIntro.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIIntro : public UGZUIComponent
{
	GENERATED_BODY()
	
public:
	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	//~ End UUserWidget Interface

public:
	UPROPERTY(BlueprintReadOnly, Category = "GZ", Meta = (BindWidgetOptional))
	class UTextBlock* IntroText;
};