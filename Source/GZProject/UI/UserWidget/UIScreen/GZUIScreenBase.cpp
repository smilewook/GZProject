// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIScreenBase.h"

UGZUIScreenBase::UGZUIScreenBase(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
	
}

void UGZUIScreenBase::NativeConstruct()
{

}

void UGZUIScreenBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}