// Fill out your copyright notice in the Description page of Project Settings.


#include "GZGameInstance.h"
#include "UI/Define/GZDefine.h"

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

void UGZGameInstance::GetUILoadData(TArray<FName>&KeyArray, TArray<FGZUILoadData*>&RowArray)
{
	// KeyArray > EGZUIState
	KeyArray = UILoadDataTable->GetRowNames();
	UILoadDataTable->GetAllRows<FGZUILoadData>(FString(""), RowArray);
}

// FGZUILoadData UGZGameInstance::GetUILoadData(EGZUIState UIState)
// {
// 	TArray<FName> RowNames = UILoadDataTable->GetRowNames();
// 	for (int i = 0; i < RowNames.Num(); i++)
// 	{
// 		FString ContextString = TEXT("");
// 		FGZUILoadData UILoadData = *(UILoadDataTable->FindRow<FGZUILoadData>(RowNames[i], ContextString));
// 		UILoadDataArray.Push(UILoadData);
// 		//GZ_LOG(GZ, Warning, TEXT("UGZGameInstance::InitUILoadData!! UILoadData.StateName = %s"), *(UILoadData.StateName));
// 	}
// 
// 	return UILoadDataTable->FindRow<FGZUILoadData>(*FString::FromInt(UIState), TEXT(""));
// }

void UGZGameInstance::InitUILoadData()
{
	FString UILoadDataPath = TEXT("/Game/DB/UI/UILoadData.UILoadData");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_UILOADDATA(*UILoadDataPath);
	if (DT_UILOADDATA.Succeeded())
	{
		UILoadDataTable = DT_UILOADDATA.Object;
	}
}
