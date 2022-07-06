// Fill out your copyright notice in the Description page of Project Settings.


#include "GZGameInstance.h"
#include "UI/Define/GZUIDefine.h"

/** Global UGZGameInstance pointer.*/
UGZGameInstance* GInstance;

UGZGameInstance::UGZGameInstance()
{
	GZ_LOG_S(GZ, Warning);

	GInstance = this;

	InitUILoadData();
}

UGZGameInstance::~UGZGameInstance()
{}

void UGZGameInstance::GetUILoadData(TArray<FName>&KeyArray, TArray<FGZUILoadDataTable*>&RowArray)
{
	// KeyArray > EGZUIState
	KeyArray = UILoadDataTable->GetRowNames();
	UILoadDataTable->GetAllRows<FGZUILoadDataTable>(FString(""), RowArray);
}

void UGZGameInstance::InitUILoadData()
{
	FString UILoadDataTablePath = TEXT("/Game/DB/UI/UILoadDataTable.UILoadDataTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_UILOADDATATABLE(*UILoadDataTablePath);
	if (DT_UILOADDATATABLE.Succeeded())
	{
		UILoadDataTable = DT_UILOADDATATABLE.Object;
	}
}
