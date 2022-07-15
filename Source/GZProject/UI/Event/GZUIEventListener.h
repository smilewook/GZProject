// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UI/Define/GZUIDefine.h"
#include "UI/Event/GZUIEvent.h"
#include "GZUIEventListener.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnUIEvent, const FGZUIEventParam&)

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGZUIEventListener : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GZPROJECT_API IGZUIEventListener
{
	GENERATED_BODY()

public:
	virtual void OnUIEvent(EGZUIState UIState, const FGZUIEventParam& EventParam) = 0;
};
