
#pragma once

#include "CoreMinimal.h"
#include "GZGameInstance.h"
#include "GZUIDelegates.generated.h"

/**
 * UI의 등장 및 퇴장 등에 맞춰 동작하는 골프 및 네트워크 등의 로직을 위해 만듬
 *
 * (예시)
 *  트로피 화면이 사라진 것에 대한 델리게이트를 받고 싶을 때 
 *   - UGZUIDelegates::Register(UGZUIDelegates::T::Trophy, UGZUIDelegates::S::Out, this, &ThisClass::OnTrophyShowingEnd);
 *
 *  UI에서 트로피 화면이 사라졌다는 것을 알리고 싶을 때
 *   - UGZUIDelegates::Notify(UGZUIDelegates::T::Trophy, UGZUIDelegates::S::Out);
 * 
 *  델리게이트 등록을 제거하고 싶을 때
 *   - UGZUIDelegates::RemoveAll(this);	
 */

UCLASS()
class GZPROJECT_API UGZUIDelegates : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// 상태
	enum class State
	{		
		In,		// 등장
		Out,	// 퇴장
		All
	};

	// 종류
	enum class Type
	{
		BestRecord,		// 베스트 레코드
		BestShot,		// 베스트 샷
		Trophy,			// 트로피
		PhotoTime,		// 포토타임
		TrainingNasmo,	// 연습장 나스모
		ENUM_COUNT
	};

	// 특정 상태로 변경 시 델리게이트
	DECLARE_DELEGATE(FOnUIChanged);

	// 상태 변경 시 모두 델리게이트
	DECLARE_DELEGATE_OneParam(FOnUIChangedOneParam, UGZUIDelegates::State);	

protected:
	// 델리게이트 등록 정보를 저장하기 위한 구조
	struct FInfo
	{
		UGZUIDelegates::State State = State::All;
		UGZUIDelegates::Type Type;

		FOnUIChanged Delegate;
		FOnUIChangedOneParam DelegateOneParam;
	};

public:
	//~ Begin USubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End USubsystem Interface

	/**
	 * 특정 타입의 UI의 모든 상태 변화 시 델리게이트 하도록 등록
	 * @param InType 델리게이트를 받고자 하는 타입
	 * @param InObj 대상 오브젝트
	 * @param InMethod 대상 오브젝트의 클래스 메소드
	 * @return 델리게이트 등록 성공 or 실패
	 */
	template< class UserClass >
	static bool Register(UGZUIDelegates::Type InType, UserClass* InObj, typename FOnUIChangedOneParam::TUObjectMethodDelegate< UserClass >::FMethodPtr InMethod)
	{
		// 중복 등록 확인
		for (auto Info : GetInfoArray())
		{
			if (Info.Type == InType && Info.DelegateOneParam.IsBoundToObject(InObj))
			{
				return false;
			}
		}

		FInfo NewInfo;
		NewInfo.Type = InType;
		NewInfo.State = State::All;
		NewInfo.DelegateOneParam.BindUObject(InObj, InMethod);
		GetInfoArray().Add(NewInfo);

		return true;
	}

	/**
	 * 특정 타입의 상태에만 델리게이트 하도록 등록
	 * @param InType 델리게이트를 받고자 하는 타입
	 * @param InState 델리게이트를 받고자 하는 상태
	 * @param InObj 대상 오브젝트
	 * @param InMethod 대상 오브젝트의 클래스 메소드
	 * @return 델리게이트 등록 성공 or 실패
	 */
	template< class UserClass >
	static bool Register(UGZUIDelegates::Type InType, UGZUIDelegates::State InState, UserClass* InObj, typename FOnUIChanged::TUObjectMethodDelegate< UserClass >::FMethodPtr InMethod)
	{		
		int32 Index = GetInfoArray().IndexOfByPredicate([InType, InState, InObj](auto Info) {
			return Info.Type == InType && Info.State == InState && Info.DelegateOneParam.IsBoundToObject(InObj);
		});
		
		// 중복 등록 확인
		if (Index != INDEX_NONE)
		{
			return false;
		}

		FInfo NewInfo;
		NewInfo.Type = InType;
		NewInfo.State = InState;
		NewInfo.Delegate.BindUObject(InObj, InMethod);
		GetInfoArray().Add(NewInfo);		

		return true;
	}

	/**
	 * 델리게이트 등록 제거
	 * @param InType 제거하고자 하는 오브젝트 대상
	 */
	static void RemoveAll(UObject* InObj);

	/**
	 * 상태 변경 알림
	 * @param InType 타입
	 * @param InState 상태 (기본값 : All)
	 */
	static void Notify(UGZUIDelegates::Type InType, UGZUIDelegates::State InState = State::All);

protected:
	static TArray<UGZUIDelegates::FInfo>& GetInfoArray();

protected:
	// 델리게이트 등록 정보를 담고 있는 배열
	TArray<FInfo> InfoArray;

	/** GameInstance */
	static class UGZGameInstance* GameInstance;
};
