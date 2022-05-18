// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "UI/Data/GZUILoadData.h"
#include "GZGameInstance.generated.h"

// 
extern UGZGameInstance* GInstance;

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UGZGameInstance();
	virtual ~UGZGameInstance();

	// UILoadData ��������.
	void GetUILoadData(TArray<FName>& KeyArray, TArray<struct FUILoadData*>& RowArray);

private:
	void InitUILoadData();

private:
	UPROPERTY()
	class UDataTable* UILoadDataTable;

	// �׽�Ʈ�ϱ� ���� �ε� ������ �����
	TArray<FUILoadData*> UILoadDataArray;

};
