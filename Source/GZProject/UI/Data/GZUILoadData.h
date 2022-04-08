// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "../Define/GZDefine.h"
#include "GZUILoadData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FUILoadData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	EGZUIMode ModeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	EGZUIState StateName;

public:
	FUILoadData() : ModeName(EGZUIMode::None), StateName(EGZUIState::None)
	{}
};

UCLASS()
class GZPROJECT_API UGZUILoadData : public UDataTable
{
	GENERATED_BODY()
	
};
