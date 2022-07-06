// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidget/UIScreen/GZUISubScreen.h"
#include "GZUITouchScreen.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUITouchScreen : public UGZUISubScreen
{
	GENERATED_BODY()
	
public:
	//~ Begin UGZUISubScreen Interface
	virtual void CreateSlateWindow() override;
	//~ End UGZUISubScreen Interface
};
