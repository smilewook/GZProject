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
	 * UIManager ���۷����� ����
	 */
	static UGZUIManager& GetUIManager();

	//~ Begin USubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End USubsystem Interface

	void Initialize(EGZUIMode UIMode);

	// UI ������ �޾Ƽ� ��� ����
	//

private:
	/* GameInstance */
	static class UGZGameInstance* GameInstance;
};
