// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "GZGameModeBase.h"
#include "GZGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API AGZGameMode : public AGZGameModeBase
{
	GENERATED_BODY()
			
public:
	AGZGameMode();
	virtual ~AGZGameMode();

	//~ Begin AGameModeBase
	virtual void StartPlay() override;
	//~ End AGameModeBase

protected:
	//~ Begin AActor
	virtual void BeginPlay() override;
	//~ End AActor

	/** UI √ ±‚»≠ */
	virtual void InitializeUI();

};
