// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UMG/Blueprint/GZUserWidget.h"
#include "UI/UMG/Blueprint/GZWidgetEventAnimDefine.h"
#include "GZEventAnimUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GZPROJECT_API UGZEventAnimUserWidget : public UGZUserWidget
{
	GENERATED_BODY()
	
public:
	/**
	 * 이벤트에 해당하는 애니메이션을 찾아 플레이함
	 * @param InAnimEvent 플레이하고자 하는 이벤트
	 * @return bool 성공 혹은 실패
	 */
	bool PlayAnimByEvent(EGZWidgetAnimType InAnimEvent);

protected:
	/**
	 * 애니메이션 아이디를 이용해 애니메이션을 찾고 플레이함
	 * @param InAnimId 플레이하고자 하는 애니메이션 ID
	 * @param bForceReverse 강제로 역 재생 할 지 여부
	 * @return bool 성공 혹은 실패
	 */
	void PlayAnimById(FString InAnimId, bool bForceReverse = false);

	/**
	 * EventAnimData를 위젯애니메이션을 통해 찾음
	 * @param WidgetAnimation 찾고자 하는 위젯애니메이션
	 * @return FGZUIComponentAnimData AnimData
	 */
	FGZUIComponentAnimData FindFirstAnimData(const UWidgetAnimation* WidgetAnimation);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "U1")
	TArray<FGZUIComponentAnimData> EventAnimData;
};
