
#pragma once

#include "CoreMinimal.h"
#include "GZGameInstance.h"
#include "GZUIDelegates.generated.h"

/**
 * UI�� ���� �� ���� � ���� �����ϴ� ���� �� ��Ʈ��ũ ���� ������ ���� ����
 *
 * (����)
 *  Ʈ���� ȭ���� ����� �Ϳ� ���� ��������Ʈ�� �ް� ���� �� 
 *   - UGZUIDelegates::Register(UGZUIDelegates::T::Trophy, UGZUIDelegates::S::Out, this, &ThisClass::OnTrophyShowingEnd);
 *
 *  UI���� Ʈ���� ȭ���� ������ٴ� ���� �˸��� ���� ��
 *   - UGZUIDelegates::Notify(UGZUIDelegates::T::Trophy, UGZUIDelegates::S::Out);
 * 
 *  ��������Ʈ ����� �����ϰ� ���� ��
 *   - UGZUIDelegates::RemoveAll(this);	
 */

UCLASS()
class GZPROJECT_API UGZUIDelegates : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// ����
	enum class State
	{		
		In,		// ����
		Out,	// ����
		All
	};

	// ����
	enum class Type
	{
		BestRecord,		// ����Ʈ ���ڵ�
		BestShot,		// ����Ʈ ��
		Trophy,			// Ʈ����
		PhotoTime,		// ����Ÿ��
		TrainingNasmo,	// ������ ������
		ENUM_COUNT
	};

	// Ư�� ���·� ���� �� ��������Ʈ
	DECLARE_DELEGATE(FOnUIChanged);

	// ���� ���� �� ��� ��������Ʈ
	DECLARE_DELEGATE_OneParam(FOnUIChangedOneParam, UGZUIDelegates::State);	

protected:
	// ��������Ʈ ��� ������ �����ϱ� ���� ����
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
	 * Ư�� Ÿ���� UI�� ��� ���� ��ȭ �� ��������Ʈ �ϵ��� ���
	 * @param InType ��������Ʈ�� �ް��� �ϴ� Ÿ��
	 * @param InObj ��� ������Ʈ
	 * @param InMethod ��� ������Ʈ�� Ŭ���� �޼ҵ�
	 * @return ��������Ʈ ��� ���� or ����
	 */
	template< class UserClass >
	static bool Register(UGZUIDelegates::Type InType, UserClass* InObj, typename FOnUIChangedOneParam::TUObjectMethodDelegate< UserClass >::FMethodPtr InMethod)
	{
		// �ߺ� ��� Ȯ��
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
	 * Ư�� Ÿ���� ���¿��� ��������Ʈ �ϵ��� ���
	 * @param InType ��������Ʈ�� �ް��� �ϴ� Ÿ��
	 * @param InState ��������Ʈ�� �ް��� �ϴ� ����
	 * @param InObj ��� ������Ʈ
	 * @param InMethod ��� ������Ʈ�� Ŭ���� �޼ҵ�
	 * @return ��������Ʈ ��� ���� or ����
	 */
	template< class UserClass >
	static bool Register(UGZUIDelegates::Type InType, UGZUIDelegates::State InState, UserClass* InObj, typename FOnUIChanged::TUObjectMethodDelegate< UserClass >::FMethodPtr InMethod)
	{		
		int32 Index = GetInfoArray().IndexOfByPredicate([InType, InState, InObj](auto Info) {
			return Info.Type == InType && Info.State == InState && Info.DelegateOneParam.IsBoundToObject(InObj);
		});
		
		// �ߺ� ��� Ȯ��
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
	 * ��������Ʈ ��� ����
	 * @param InType �����ϰ��� �ϴ� ������Ʈ ���
	 */
	static void RemoveAll(UObject* InObj);

	/**
	 * ���� ���� �˸�
	 * @param InType Ÿ��
	 * @param InState ���� (�⺻�� : All)
	 */
	static void Notify(UGZUIDelegates::Type InType, UGZUIDelegates::State InState = State::All);

protected:
	static TArray<UGZUIDelegates::FInfo>& GetInfoArray();

protected:
	// ��������Ʈ ��� ������ ��� �ִ� �迭
	TArray<FInfo> InfoArray;

	/** GameInstance */
	static class UGZGameInstance* GameInstance;
};
