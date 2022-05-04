// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(GZ, Log, All);			// Default
DECLARE_LOG_CATEGORY_EXTERN(GZUI, Log, All);		// UserInterface

// CLASSNAME::FUNCTIONNAME(LINE) ���·� FString ����
#define GZ_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// GZ_LOG_CALLINFO�� Category, Verbosity�� �޾� �α׷� ���
// Ex) [2022.04.01-04.30.04:240][ 26]GZ: UGZUIManager::UGZUIManager(22)
#define GZ_LOG_S(Category, Verbosity) UE_LOG(Category, Verbosity, TEXT("%s"), *GZ_LOG_CALLINFO)

// GZ_LOG_S�� �Էµ� Format�� �߰������� �α׷� ���
// Ex) [2022.04.01-04.30.04:240][ 26]GZ: UGZUIManager::UGZUIManager(22) UGZUIManager Initialized.
#define GZ_LOG(Category, Verbosity, Format, ...) UE_LOG(Category, Verbosity, TEXT("%s %s"), *GZ_LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))