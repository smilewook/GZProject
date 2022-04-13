// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GZUIManager.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UGZUIManager();

	/**
	 * UIManager 레퍼런스를 전달
	 */
	static UGZUIManager& GetUIManager();

	//~ Begin USubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End USubsystem Interface

	void Initialize(EGZUIMode UIMode);

	// UI 데이터 받아서 목록 생성
	//

private:
	/* GameInstance */
	static class UGZGameInstance* GameInstance;
};
