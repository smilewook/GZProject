// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UI/Define/GZDefine.h"
#include "GZUILoadData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGZUILoadData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	EGZUIState StateEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	FString StateName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	EGZUIMode ModeEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	FString ModeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	TArray<TSubclassOf<class UGZUIComponent>> ComponentClassArray;

public:
	FGZUILoadData() : StateEnum(EGZUIState::None), StateName(TEXT("None")), ModeEnum(EGZUIMode::None), ModeName(TEXT("None"))
	{}

	void Reset()
	{
		StateEnum = EGZUIState::None;
		StateName = TEXT("None");
		ModeEnum = EGZUIMode::None;
		ModeName = TEXT("None");
		ComponentClassArray.Reset();
	}
};
