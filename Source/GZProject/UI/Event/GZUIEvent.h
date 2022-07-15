// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Define/GZUIDefine.h"
#include "GZUIEvent.generated.h"

/** ���������� �߻��ϴ� �̺�Ʈ */
UENUM()
enum class EGZUIEvent
{
	None,

	Confirm,
	Cancel,
	Next,
	Previous,
	Success,
	Fail,
	Exit,
	Admin,
	Password,

	Max
};

DECLARE_DELEGATE_OneParam(FOnGZUIEventDelegate, EGZUIEvent)

USTRUCT()
struct FGZUIEventParam
{
	GENERATED_BODY()

	EGZUIEvent UIEvent;
	EGZUIScreen UIScreen;
	int32 PlayerIndex = INDEX_NONE;
	FString Password;
	FOnGZUIEventDelegate OnUIEventDelegate;

	FGZUIEventParam() {}
	FGZUIEventParam(EGZUIEvent E) : UIEvent(E) {}
	FGZUIEventParam(EGZUIEvent E, int32 P) : UIEvent(E), PlayerIndex(P) {}
	FGZUIEventParam(EGZUIEvent E, FString& S) : UIEvent(E), Password(S) {}
	FGZUIEventParam(EGZUIEvent E, EGZUIScreen S) : UIEvent(E), UIScreen(S) {}
};