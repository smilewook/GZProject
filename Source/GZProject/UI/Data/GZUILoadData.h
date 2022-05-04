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
struct FUILoadData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	EGZUIMode ModeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	EGZUIState StateName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UIData")
	TArray<TSubclassOf<class UGZUIComponent>> ComponentClassArray;

public:
	FUILoadData() : ModeName(EGZUIMode::None), StateName(EGZUIState::None)
	{}

	void Reset()
	{
		ModeName = EGZUIMode::None;
		StateName = EGZUIState::None;
		ComponentClassArray.Reset();
	}
};

UCLASS()
class GZPROJECT_API UGZUILoadData : public UDataTable
{
	GENERATED_BODY()
	
};
