// Fill out your copyright notice in the Description page of Project Settings.


#include "GZEventAnimUserWidget.h"

bool UGZEventAnimUserWidget::PlayAnimByEvent(EGZWidgetAnimType InAnimEvent)
{
	UWidgetBlueprintGeneratedClass* WidgetBPGeneratedClass = Cast<UWidgetBlueprintGeneratedClass>(GetClass());
	if (WidgetBPGeneratedClass == nullptr || WidgetBPGeneratedClass->Animations.Num() <= 0)
		return false;

	bool bIsAnimPlayed = false;
	for (auto AnimData : EventAnimData)
	{
		if (AnimData.AnimEvent != InAnimEvent)
			continue;

		UWidgetAnimation* WidgetAnimation = GetAnimationFromName(AnimData.WidgetAnimName);
		if (WidgetAnimation == nullptr)
			continue;

		PlayAnimation(WidgetAnimation, AnimData.StartAtTime, AnimData.NumberOfLoops, AnimData.PlayMode, AnimData.PlaybackSpeed);
		bIsAnimPlayed = true;
	}

	return bIsAnimPlayed;
}

void UGZEventAnimUserWidget::PlayAnimById(FString InAnimId, bool bForceReverse /*= false*/)
{
	UWidgetBlueprintGeneratedClass* WidgetBPGeneratedClass = Cast<UWidgetBlueprintGeneratedClass>(GetClass());
	if (WidgetBPGeneratedClass == nullptr || WidgetBPGeneratedClass->Animations.Num() <= 0)
		return;

	for (FGZUIComponentAnimData AnimData : EventAnimData)
	{
		if (!AnimData.AnimId.Equals(InAnimId))
			continue;

		UWidgetAnimation* WidgetAnimation = GetAnimationFromName(AnimData.WidgetAnimName);
		if (WidgetAnimation == nullptr)
			continue;

		TEnumAsByte<EUMGSequencePlayMode::Type> PlayMode = (bForceReverse) ? EUMGSequencePlayMode::Reverse : AnimData.PlayMode;

		PlayAnimation(WidgetAnimation, AnimData.StartAtTime, AnimData.NumberOfLoops, PlayMode, AnimData.PlaybackSpeed);
	}
}

FGZUIComponentAnimData UGZEventAnimUserWidget::FindFirstAnimData(const UWidgetAnimation* WidgetAnimation)
{
	FGZUIComponentAnimData Empty;

	int32 AnimDataIndex = EventAnimData.IndexOfByPredicate(
		[&](const FGZUIComponentAnimData AnimData)
		{
			return AnimData.WidgetAnimName == WidgetAnimation->GetName();
		}
	);

	if (AnimDataIndex == INDEX_NONE)
		return Empty;

	return EventAnimData[AnimDataIndex];
}
