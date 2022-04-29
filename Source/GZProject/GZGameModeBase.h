// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "GameFramework/GameModeBase.h"
#include "GZGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API AGZGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
			
public:
	AGZGameModeBase();
	virtual ~AGZGameModeBase();

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
