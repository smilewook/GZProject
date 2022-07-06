// Fill out your copyright notice in the Description page of Project Settings.


#include "GZUIScreenBase.h"
#include "Components/CanvasPanel.h"
#include "Ui/Data/GZUIInfoData.h"
#include "UI/System/GZUIManager.h"
#include "UI/UserWidget/UIComponent/GZUIComponent.h"
#include "UI/UserWidget/UIScreenLayer/GZUIScreenLayer.h"


UGZUIScreenBase::UGZUIScreenBase(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
	CurLoadData.Reset();
}

void UGZUIScreenBase::NativeConstruct()
{
	// 팝업컴포넌트 생성하기.
	// UIScreen 타입 설정하기.
}

void UGZUIScreenBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UGZUIScreenBase::Reset()
{
	// 로드 데이터 초기화.
	NewLoadData.Reset();
	CurLoadData.Reset();

	// 위젯 제거.
	for (UGZUIComponent* UIComponent : UIComponentsOnScreen)
	{
		UIComponent->RemoveFromParent();
	}

	UIComponentsOnScreen.Reset();
	UIComponentsToRemove.Reset();
}

void UGZUIScreenBase::SetUIScreen(EGZUIScreen UIScreenType)
{
	CurUIScreen = UIScreenType;
}

EGZUIScreen UGZUIScreenBase::GetUIScreen()
{
	return CurUIScreen;
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
	NewLoadData = UGZUIManager::GetUIManager().GetUIStateData(NewUIState);
	GZ_LOG(GZ, Warning, TEXT("UIScreenBase::ChangeUIState() NewLoadData.StateName= %s"), &(NewLoadData.StateName));
	 
	// 이전 로드된 UIComponent를 삭제 대상에 일단 모두 다 넣음
	FGZUILoadDataTable LoadDataToRemove = CurLoadData;

	// 리셋 플래그 확인
	if (bResetUI)
	{
		// 리셋인 경우, 모두 제거
		bResetUI = false;
	}
	else
	{
		// 리셋이 아닌 경우, 삭제하지 말아야 할 UIComponent들을 리스트에서 제외
		LoadDataToRemove.ComponentClassArray.RemoveAll([&](TSubclassOf<UGZUIComponent> UIComponent) {
			return (NewLoadData.ComponentClassArray.IndexOfByKey(UIComponent) != INDEX_NONE);
		});
	}

	// 삭제 대상이 된 UIComponent들을 추려서 가져옴
	UIComponentsToRemove = GetUIComponentsToRemove(LoadDataToRemove);

	// 삭제할 UIComponent가 있는 지 확인
	if (UIComponentsToRemove.Num() <= 0)
	{
		// 삭제할 대상이 없다면 바로 새로운 UIState로 전이
		AttachNewState(NewLoadData);
	}
	else
	{
		// 삭제할 대상이 있다면 DestructAnim을 요청하고 Anim 없다면 바로 삭제
		TArray<UGZUIComponent*> TempRemoveArray;
		for (UGZUIComponent* UIComponent : UIComponentsToRemove)
		{
			// DestructAnim 시작

			// DestructAnim이 있다면 델리게이트를 걸어두고 대기함

			// DestructAnim이 없으면 삭제 리스트에 추가.
			TempRemoveArray.Add(UIComponent);
		}

		// 바로 삭제할 UIComponent들을 여기서 정리
		int32 RemoveCount = TempRemoveArray.Num();
		for (int32 i = 0; i < RemoveCount; ++i)
		{
			OnReadyToDestroyChild(TempRemoveArray[0]);
			TempRemoveArray.RemoveAt(0);
		}
	}
}

TArray<UGZUIComponent*> UGZUIScreenBase::GetUIComponentsToRemove(FGZUILoadDataTable& LoadDataToRemove)
{
	TArray<UGZUIComponent*> UIComponentArray;

	// 삭제대상이 된 UIComponent 리스트를 추림
	for (UGZUIComponent* UIComponent : UIComponentsOnScreen)
	{
		int32 Index = LoadDataToRemove.ComponentClassArray.IndexOfByPredicate([UIComponent](TSubclassOf<UGZUIComponent> UIComponentClass) {
			return (UIComponentClass == UIComponent->GetClass());
		});

		UIComponentArray.Add(UIComponent);
	}

	return UIComponentArray;
}

void UGZUIScreenBase::AttachNewState(FGZUILoadDataTable InLoadData)
{
	GZ_LOG(GZ, Warning, TEXT("UIScreenBase::AttachNewState = %d"), InLoadData.StateEnum);

	// State 변경
	FGZUILoadDataTable OldLoadData = CurLoadData;
	CurLoadData = InLoadData;

	// 위젯 생성은 여기서부터
	UCanvasPanelSlot* CanvasPanelSlot = nullptr;

	int32 ZOrder = 0;
	for (TSubclassOf<UGZUIComponent> UIComponentClass : NewLoadData.ComponentClassArray)
	{
		// UIComponent Class가 없다면 ?
		check(UIComponentClass != nullptr);

		// 화면 상에 이미 존재하는 UIComponent인 지 확인함
		int32 Index = UIComponentsOnScreen.IndexOfByPredicate([&](UGZUIComponent* UICompCached) {
			return UICompCached->GetClass() == UIComponentClass;
		});

		// 새롭게 생성할 위젯인 지 확인
		if (Index == INDEX_NONE)
		{
			// 새로 생성할 UIComponent인 경우

			// UIComponent 생성
			UGZUIComponent* NewUIComponent = CreateWidget<UGZUIComponent>(this, UIComponentClass);
			FGZUIInfoData UIInfoData = NewUIComponent->UIInfoData;
			GZ_LOG(GZ, Warning, TEXT("UIScreenBase::AttachNewState() CreateWidget = %s"), *UIComponentClass->GetName());

			// UIComponent를 UIInfoData를 기반으로 Layer에 붙임
			AddUIComponentToLayer(NewUIComponent, UIInfoData.UIScreenLayerType);

			// 화면 상에 존재하는 UIComponent들을 캐싱
			UIComponentsOnScreen.Add(NewUIComponent);

			// CanvasPanelSlot을 가져와 Layout 데이터를 적용
			CanvasPanelSlot = Cast<UCanvasPanelSlot>(NewUIComponent->Slot);
			if (IsValid(CanvasPanelSlot))
			{
				CanvasPanelSlot->SetLayout(UIInfoData.PositionData);
				CanvasPanelSlot->SetAutoSize(UIInfoData.bAutoSize);
				CanvasPanelSlot->SetZOrder(UIInfoData.ZOrder);
			}
		}
		else
		{
			// 화면 상에 존재하는 UIComponent인 경우

			// 캐싱 상태인 지 확인
// 			if (UIComponentsOnScreen[Index]->GetIsCached())
// 			{
// 				// 캐싱 중이라면 활성화 요청
// 				UIComponentsOnScreen[Index]->PostActivatedFromCaching();
// 			}

			CanvasPanelSlot = Cast<UCanvasPanelSlot>(UIComponentsOnScreen[Index]->Slot);
		}
	}

	// AttachNewState의 콜스택이 Paint 콜스택인 경우가 있음(애니메이션 Tick 등의 Delegate 연결로 인한)
	// Paint 진행 중에 새로운 위젯이 붙으면 Prepass 데이터가 없어 랜더링 문제가 발생하는 경우가 있음(RetainerBox 크기 오류 문제, 엔진 버그...)
	//ForceLayoutPrepass();

	// 위젯 생성 후에 상태 변경 알림.
	OnScreenUIStateChanged.Broadcast(this, CurLoadData.StateEnum);
}

void UGZUIScreenBase::AddUIComponentToLayer(UGZUIComponent* NewUIComponent, EGZUIScreenLayerType InLayerType)
{
	if (InLayerType == EGZUIScreenLayerType::None)
	{
		GZ_LOG(GZ, Warning, TEXT("UIScreenBase::AddUIComponentToLayer() LayerType is None"));
		return;
	}

	UCanvasPanel* TargetCanvasPanel = UIScreenLayer->GetLayerCanvasPanel(InLayerType);
	if (!IsValid(TargetCanvasPanel))
	{
		GZ_LOG(GZ, Warning, TEXT("UIScreenBase::AddUIComponentToLayer() Failed to find parent"));
		return;
	}

	GZ_LOG(GZ, Warning, TEXT("UIScreenBase::AddUIComponentToLayer() AddUI = %s"), *NewUIComponent->GetName());

	TargetCanvasPanel->AddChild(NewUIComponent);
}

void UGZUIScreenBase::OnReadyToDestroyChild(UUserWidget* UserWidget)
{
	UGZUIComponent* UIComponent = Cast<UGZUIComponent>(UserWidget);
	
	// 삭제 전 애니메이션 딜리게이트 제거하기.

	// 삭제하기.
	{
		GZ_LOG(GZ, Warning, TEXT("UIScreenBase::OnReadyToDestroyChild() RemoveUI = %s"), *UIComponent->GetName());

		// 리스트에서 삭제하고 부모로부터 떼어냄
		UIComponentsOnScreen.Remove(UIComponent);
		UIComponent->RemoveFromParent();

		// 이 시점에 UIComponent는 부모로부터 분리됐을 뿐 메모리 상에는 그대로 존재함으로 주의 필요
		// 최종적으로 GC가 일어나는 시점이 되야 UIComponent가 메모리에서 삭제됨
	}

	UIComponentsToRemove.Remove(UIComponent);

	// 이전 UIState의 UIComponent들이 모두 삭제됐다면 다음 UIState를 붙임
	if (UIComponentsToRemove.Num() <= 0)
	{
		AttachNewState(NewLoadData);
	}
}