// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZWidgetEventAnimDefine.generated.h"

// Normal, Hovered, Pressed, Disabled, Selected Normal, Selected Hovered, Selected Pressed, Selected Disabled

// 일반 이벤트(WAT)
UENUM(BlueprintType)
enum class EGZWidgetAnimType : uint8
{
	WAT_NONE 					UMETA(DisplayName = "None"),
	WAT_ON_CONSTRUCT 			UMETA(DisplayName = "OnConstruct"),
	WAT_ON_CONSTRUCT_L			UMETA(DisplayName = "OnConstructLeft"),
	WAT_BEFORE_DESTRUCT 		UMETA(DisplayName = "BeforeDestruct"),
	WAT_BEFORE_DESTRUCT_L 		UMETA(DisplayName = "BeforeDestructLeft"),
	WAT_ON_SET_IS_VISIBLE		UMETA(DisplayName = "OnSetIsVisible"),
};

// 버튼 이벤트(BAT)
UENUM(BlueprintType)
enum class ECustomButtonAnimType : uint8
{
	BAT_NONE 					UMETA(DisplayName = "None"),
	BAT_NORMAL					UMETA(DisplayName = "Normal"),
	BAT_HOVERED					UMETA(DisplayName = "Hovered"),
	BAT_UNHOVERED				UMETA(DisplayName = "Unhovered"),
	BAT_PRESSED					UMETA(DisplayName = "Pressed"),
	BAT_RELEASED				UMETA(DisplayName = "Released"),
	BAT_DISABLED				UMETA(DisplayName = "OnDisabled"),
	BAT_CLICKED					UMETA(DisplayName = "OnClicked"),

	BAT_SELECTED_NORMAL			UMETA(DisplayName = "Normal(Selected)"),
	BAT_SELECTED_HOVERED		UMETA(DisplayName = "Hovered(Selected)"),
	BAT_SELECTED_UNHOVERED		UMETA(DisplayName = "Unhovered(Selected)"),
	BAT_SELECTED_PRESSED		UMETA(DisplayName = "Pressed(Selected)"),
	BAT_SELECTED_RELEASED		UMETA(DisplayName = "Released(Selected)"),
	BAT_SELECTED_DISABLED		UMETA(DisplayName = "OnDisabled(Selected)"),
	BAT_SELECTED_CLICKED		UMETA(DisplayName = "OnClicked(Selected)")
};

USTRUCT(BlueprintType)
struct GZPROJECT_API FGZWidgetAnimData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	FString AnimId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	FString WidgetAnimName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	float StartAtTime = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	int32 NumberOfLoops = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	TEnumAsByte<EUMGSequencePlayMode::Type> PlayMode = EUMGSequencePlayMode::Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	float PlaybackSpeed = 1.0;

	UPROPERTY(Transient)
	class UUMGSequencePlayer* SequencePlayer;
};

USTRUCT(BlueprintType)
struct GZPROJECT_API FGZUIComponentAnimData : public FGZWidgetAnimData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	EGZWidgetAnimType AnimEvent = EGZWidgetAnimType::WAT_ON_CONSTRUCT;
};

USTRUCT(BlueprintType)
struct GZPROJECT_API FGZCustomButtonAnimData : public FGZWidgetAnimData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (DisplayThumbnail = false))
	ECustomButtonAnimType AnimEvent = ECustomButtonAnimType::BAT_NORMAL;
};