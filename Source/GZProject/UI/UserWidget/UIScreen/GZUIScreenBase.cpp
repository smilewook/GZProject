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

	// 새로운 UIState에 해당하는 데이터를 가져옴
	// 이전 로드된 UIComponent를 삭제 대상에 일단 모두 다 넣음

	// 리셋 플래그 확인
	if (bResetUI)
	{
		// 리셋인 경우, 모두 제거
		bResetUI = false;
	}
	else
	{
		// 리셋이 아닌 경우, 삭제하지 말아야 할 UIComponent들을 리스트에서 제외
	}

	/*// 삭제 대상이 된 UIComponent들을 추려서 가져옴

	// 삭제할 UIComponent가 있는 지 확인
	if (UIComponentsToRemove.Num() <= 0)
	{
		// 삭제할 대상이 없다면 바로 새로운 UIState로 전이
		AttachNewState(NewStateData);
	}
	else
	{
		// 삭제할 대상이 있다면 DestructAnim을 요청하고 Anim 없다면 바로 삭제
		TArray<UM1UIComponent*> TempRemoveArray;
		for (UM1UIComponent* UIComponent : UIComponentsToRemove)
		{
			// DestructAnim 시작
			bool bHasDestructAnim = UIComponent->BeginDestructAnim();

			if (bHasDestructAnim)
			{
				// DestructAnim이 있다면 델리게이트를 걸어두고 대기함
				UIComponent->OnDestructAnimFinished.AddUObject(this, &ThisClass::OnReadyToDestroyChild);
			}
			else
			{
				TempRemoveArray.Add(UIComponent);
			}
		}

		// 바로 삭제할 UIComponent들을 여기서 정리
		int32 RemoveCount = TempRemoveArray.Num();
		for (int32 i = 0; i < RemoveCount; ++i)
		{
			OnReadyToDestroyChild(TempRemoveArray[0]);
			TempRemoveArray.RemoveAt(0);
		}
	}*/
}
