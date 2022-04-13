// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "Engine/GameInstance.h"
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

};
