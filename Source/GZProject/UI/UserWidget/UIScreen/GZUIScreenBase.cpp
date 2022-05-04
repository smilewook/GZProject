// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIScreenBase.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"


UGZUIScreenBase::UGZUIScreenBase(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
	
}

void UGZUIScreenBase::NativeConstruct()
{

}

void UGZUIScreenBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UGZUIScreenBase::SetUIMode(EGZUIMode NewUIMode)
{
	GZ_LOG(GZ, Warning, TEXT("UIScreenBase::SetUIMode = %d"), NewUIMode);

	if (CurUIMode != NewUIMode)
	{
		bResetUI = true;
	}

	CurUIMode = NewUIMode;
}

void UGZUIScreenBase::ChangeUIState(EGZUIState NewUIState)
{
	GZ_LOG(GZ, Warning, TEXT("UIScreenBase::ChangeUIState = %d"), NewUIState);

	ensure(CurUIMode != EGZUIMode::None);

	// ���ο� UIState�� �ش��ϴ� �����͸� ������
	// ���� �ε�� UIComponent�� ���� ��� �ϴ� ��� �� ����

	// ���� �÷��� Ȯ��
	if (bResetUI)
	{
		// ������ ���, ��� ����
		bResetUI = false;
	}
	else
	{
		// ������ �ƴ� ���, �������� ���ƾ� �� UIComponent���� ����Ʈ���� ����
	}

	/*// ���� ����� �� UIComponent���� �߷��� ������

	// ������ UIComponent�� �ִ� �� Ȯ��
	if (UIComponentsToRemove.Num() <= 0)
	{
		// ������ ����� ���ٸ� �ٷ� ���ο� UIState�� ����
		AttachNewState(NewStateData);
	}
	else
	{
		// ������ ����� �ִٸ� DestructAnim�� ��û�ϰ� Anim ���ٸ� �ٷ� ����
		TArray<UM1UIComponent*> TempRemoveArray;
		for (UM1UIComponent* UIComponent : UIComponentsToRemove)
		{
			// DestructAnim ����
			bool bHasDestructAnim = UIComponent->BeginDestructAnim();

			if (bHasDestructAnim)
			{
				// DestructAnim�� �ִٸ� ��������Ʈ�� �ɾ�ΰ� �����
				UIComponent->OnDestructAnimFinished.AddUObject(this, &ThisClass::OnReadyToDestroyChild);
			}
			else
			{
				TempRemoveArray.Add(UIComponent);
			}
		}

		// �ٷ� ������ UIComponent���� ���⼭ ����
		int32 RemoveCount = TempRemoveArray.Num();
		for (int32 i = 0; i < RemoveCount; ++i)
		{
			OnReadyToDestroyChild(TempRemoveArray[0]);
			TempRemoveArray.RemoveAt(0);
		}
	}*/
}
