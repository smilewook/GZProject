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
	 * �̺�Ʈ�� �ش��ϴ� �ִϸ��̼��� ã�� �÷�����
	 * @param InAnimEvent �÷����ϰ��� �ϴ� �̺�Ʈ
	 * @return bool ���� Ȥ�� ����
	 */
	bool PlayAnimByEvent(EGZWidgetAnimType InAnimEvent);

protected:
	/**
	 * �ִϸ��̼� ���̵� �̿��� �ִϸ��̼��� ã�� �÷�����
	 * @param InAnimId �÷����ϰ��� �ϴ� �ִϸ��̼� ID
	 * @param bForceReverse ������ �� ��� �� �� ����
	 * @return bool ���� Ȥ�� ����
	 */
	void PlayAnimById(FString InAnimId, bool bForceReverse = false);

	/**
	 * EventAnimData�� �����ִϸ��̼��� ���� ã��
	 * @param WidgetAnimation ã���� �ϴ� �����ִϸ��̼�
	 * @return FGZUIComponentAnimData AnimData
	 */
	FGZUIComponentAnimData FindFirstAnimData(const UWidgetAnimation* WidgetAnimation);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "U1")
	TArray<FGZUIComponentAnimData> EventAnimData;
};
