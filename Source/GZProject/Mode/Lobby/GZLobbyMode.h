// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GZProject.h"
#include "GZGameModeBase.h"
#include "GZLobbyMode.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API AGZLobbyMode : public AGZGameModeBase
{
	GENERATED_BODY()
			
public:
	AGZLobbyMode();
	virtual ~AGZLobbyMode();

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
