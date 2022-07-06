// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/Define/GZUIDefine.h"
#include "UI/Define/GZUIPopupDefine.h"
#include "GZUIPopupManager.generated.h"


/**
 * 
 */
UCLASS(config=UI)
class GZPROJECT_API UGZUIPopupManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UGZUIPopupManager();

	/**
	 * GZGameInstance�� �����ϴ� UIPopupManager ���۷����� ����
	 */
	static UGZUIPopupManager& GetUIPopupManager();

	//~ Begin USubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End USubsystem Interface

	/**
	 * 
	 */
	static void Open(EGZUIPopupOpenType OpenType, FGZUIPopupOpenParams PopupParams);

private:
	/** GameInstance */
	static class UGZGameInstance* GameInstance;
};
