// Fill out your copyright notice in the Description page of Project Settings.

#include "GZUIDelegates.h"

UGZGameInstance* UGZUIDelegates::GameInstance;

void UGZUIDelegates::Initialize(FSubsystemCollectionBase& Collection)
{
	GameInstance = GetTypedOuter<UGZGameInstance>();
}

void UGZUIDelegates::Deinitialize()
{

}

void UGZUIDelegates::RemoveAll(UObject* InObj)
{
	for (int32 i = 0; i < GetInfoArray().Num();)
	{
		if (GetInfoArray()[i].Delegate.IsBoundToObject(InObj) ||
			GetInfoArray()[i].DelegateOneParam.IsBoundToObject(InObj))
		{
			GetInfoArray().RemoveAt(i);
		}		
		else
		{
			i++;
		}
	}
}

void UGZUIDelegates::Notify(Type InType, State InState /*= State::None*/)
{
	TArray<UGZUIDelegates::FInfo>& InfoArray = GetInfoArray();

	// Broadcast 중 Unregister하는 경우 생길 수 있어 복사본을 이용함
	TArray<UGZUIDelegates::FInfo> CopyInfoArray = InfoArray;

	for (FInfo& Info : CopyInfoArray)
	{		
		if (Info.Type != InType)
		{
			continue;
		}
		
		if (Info.DelegateOneParam.IsBound())
		{
			Info.DelegateOneParam.ExecuteIfBound(InState);
		}
		else if(Info.State == InState)
		{
			Info.Delegate.ExecuteIfBound();
		}
	}
}

TArray<UGZUIDelegates::FInfo>& UGZUIDelegates::GetInfoArray()
{
	UGZUIDelegates* UIDelegates = UGZGameInstance::GetSubsystem<UGZUIDelegates>(GameInstance);
	return UIDelegates->InfoArray;
}
