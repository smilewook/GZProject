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
	// �˾�������Ʈ �����ϱ�.
	// UIScreen Ÿ�� �����ϱ�.
}

void UGZUIScreenBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UGZUIScreenBase::Reset()
{
	// �ε� ������ �ʱ�ȭ.
	NewLoadData.Reset();
	CurLoadData.Reset();

	// ���� ����.
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

	// ���ο� UIState�� �ش��ϴ� �����͸� ������
	NewLoadData = UGZUIManager::GetUIManager().GetUIStateData(NewUIState);
	GZ_LOG(GZ, Warning, TEXT("UIScreenBase::ChangeUIState() NewLoadData.StateName= %s"), &(NewLoadData.StateName));
	 
	// ���� �ε�� UIComponent�� ���� ��� �ϴ� ��� �� ����
	FGZUILoadDataTable LoadDataToRemove = CurLoadData;

	// ���� �÷��� Ȯ��
	if (bResetUI)
	{
		// ������ ���, ��� ����
		bResetUI = false;
	}
	else
	{
		// ������ �ƴ� ���, �������� ���ƾ� �� UIComponent���� ����Ʈ���� ����
		LoadDataToRemove.ComponentClassArray.RemoveAll([&](TSubclassOf<UGZUIComponent> UIComponent) {
			return (NewLoadData.ComponentClassArray.IndexOfByKey(UIComponent) != INDEX_NONE);
		});
	}

	// ���� ����� �� UIComponent���� �߷��� ������
	UIComponentsToRemove = GetUIComponentsToRemove(LoadDataToRemove);

	// ������ UIComponent�� �ִ� �� Ȯ��
	if (UIComponentsToRemove.Num() <= 0)
	{
		// ������ ����� ���ٸ� �ٷ� ���ο� UIState�� ����
		AttachNewState(NewLoadData);
	}
	else
	{
		// ������ ����� �ִٸ� DestructAnim�� ��û�ϰ� Anim ���ٸ� �ٷ� ����
		TArray<UGZUIComponent*> TempRemoveArray;
		for (UGZUIComponent* UIComponent : UIComponentsToRemove)
		{
			// DestructAnim ����

			// DestructAnim�� �ִٸ� ��������Ʈ�� �ɾ�ΰ� �����

			// DestructAnim�� ������ ���� ����Ʈ�� �߰�.
			TempRemoveArray.Add(UIComponent);
		}

		// �ٷ� ������ UIComponent���� ���⼭ ����
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

	// ��������� �� UIComponent ����Ʈ�� �߸�
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

	// State ����
	FGZUILoadDataTable OldLoadData = CurLoadData;
	CurLoadData = InLoadData;

	// ���� ������ ���⼭����
	UCanvasPanelSlot* CanvasPanelSlot = nullptr;

	int32 ZOrder = 0;
	for (TSubclassOf<UGZUIComponent> UIComponentClass : NewLoadData.ComponentClassArray)
	{
		// UIComponent Class�� ���ٸ� ?
		check(UIComponentClass != nullptr);

		// ȭ�� �� �̹� �����ϴ� UIComponent�� �� Ȯ����
		int32 Index = UIComponentsOnScreen.IndexOfByPredicate([&](UGZUIComponent* UICompCached) {
			return UICompCached->GetClass() == UIComponentClass;
		});

		// ���Ӱ� ������ ������ �� Ȯ��
		if (Index == INDEX_NONE)
		{
			// ���� ������ UIComponent�� ���

			// UIComponent ����
			UGZUIComponent* NewUIComponent = CreateWidget<UGZUIComponent>(this, UIComponentClass);
			FGZUIInfoData UIInfoData = NewUIComponent->UIInfoData;
			GZ_LOG(GZ, Warning, TEXT("UIScreenBase::AttachNewState() CreateWidget = %s"), *UIComponentClass->GetName());

			// UIComponent�� UIInfoData�� ������� Layer�� ����
			AddUIComponentToLayer(NewUIComponent, UIInfoData.UIScreenLayerType);

			// ȭ�� �� �����ϴ� UIComponent���� ĳ��
			UIComponentsOnScreen.Add(NewUIComponent);

			// CanvasPanelSlot�� ������ Layout �����͸� ����
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
			// ȭ�� �� �����ϴ� UIComponent�� ���

			// ĳ�� ������ �� Ȯ��
// 			if (UIComponentsOnScreen[Index]->GetIsCached())
// 			{
// 				// ĳ�� ���̶�� Ȱ��ȭ ��û
// 				UIComponentsOnScreen[Index]->PostActivatedFromCaching();
// 			}

			CanvasPanelSlot = Cast<UCanvasPanelSlot>(UIComponentsOnScreen[Index]->Slot);
		}
	}

	// AttachNewState�� �ݽ����� Paint �ݽ����� ��찡 ����(�ִϸ��̼� Tick ���� Delegate ����� ����)
	// Paint ���� �߿� ���ο� ������ ������ Prepass �����Ͱ� ���� ������ ������ �߻��ϴ� ��찡 ����(RetainerBox ũ�� ���� ����, ���� ����...)
	//ForceLayoutPrepass();

	// ���� ���� �Ŀ� ���� ���� �˸�.
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
	
	// ���� �� �ִϸ��̼� ��������Ʈ �����ϱ�.

	// �����ϱ�.
	{
		GZ_LOG(GZ, Warning, TEXT("UIScreenBase::OnReadyToDestroyChild() RemoveUI = %s"), *UIComponent->GetName());

		// ����Ʈ���� �����ϰ� �θ�κ��� ���
		UIComponentsOnScreen.Remove(UIComponent);
		UIComponent->RemoveFromParent();

		// �� ������ UIComponent�� �θ�κ��� �и����� �� �޸� �󿡴� �״�� ���������� ���� �ʿ�
		// ���������� GC�� �Ͼ�� ������ �Ǿ� UIComponent�� �޸𸮿��� ������
	}

	UIComponentsToRemove.Remove(UIComponent);

	// ���� UIState�� UIComponent���� ��� �����ƴٸ� ���� UIState�� ����
	if (UIComponentsToRemove.Num() <= 0)
	{
		AttachNewState(NewLoadData);
	}
}