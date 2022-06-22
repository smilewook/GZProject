// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UI/Define/GZDefine.h"
#include "GZUILoadDataTable.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGZUILoadDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UILoadData")
	EGZUIState StateEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UILoadData")
	FString StateName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UILoadData")
	EGZUIMode ModeEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UILoadData")
	FString ModeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UILoadData")
	TArray<TSubclassOf<class UGZUIComponent>> ComponentClassArray;

public:
	FGZUILoadDataTable() : StateEnum(EGZUIState::None), StateName(TEXT("None")), ModeEnum(EGZUIMode::None), ModeName(TEXT("None"))
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
