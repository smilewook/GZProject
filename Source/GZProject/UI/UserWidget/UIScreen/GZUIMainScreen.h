// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidget/UIScreen/GZUIScreenBase.h"
#include "GZUIMainScreen.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIMainScreen : public UGZUIScreenBase
{
	GENERATED_BODY()
	
public:
	UGZUIMainScreen(const FObjectInitializer& ObjectInitializer);

	//~ Begin UUserWidget Interface
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	//~ End UUserWidget Interface

	//~ Begin UGZUIScreenBase Interface
	virtual void SetUIMode(EGZUIMode NewUIMode);
	//~ End UGZUIScreenBase Interface
};
