// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Define/GZUIDefine.h"

/**
 * UIPopup�� �������� ����� Define ���� ����.
 */

 /**
 * �˾� ���� Ÿ�� :  �˾��� �����ϴ� ����ũ ��.
 */
UENUM()
enum class EGZUIPopupOpenType : uint8
{
	None,

	Loading,						// �ε� ȭ��
	AdminPassword,					// ������ ��ȣ �Է�
	PlayerNameInput,				// �÷��̾� �̸� ����	
	ScreenKeyboard,					// ��ũ�� Ű����

	Max
};

 /**
  * �˾� ��Ÿ��
  */
UENUM()
enum class EGZUIPopupStyle : uint8
{
	None,

	SmallNotice,					// ���� �˸� �˾�
	LargeNotice,					// ū �˸� �˾�
	OneButtonConfirm,				// Ȯ�� �˾�(��ư 1��)
	TwoButtonConfirm,				// Ȯ�� �˾�(��ư 2��)
	ThreeButtonConfirm,				// Ȯ�� �˾�(��ư 3��)
	Input,							// �Է� �˾�
	Password,						// ��ȣ �Է� �˾�
	Loading,						// ������ �ε�, ��� �� �˾�
	ScreenKeyboard,					// ��ũ�� Ű����
	ScreenNumpad,					// ��ũ�� �����е�

	Max
};

/**
 * ���� Ÿ��
 */
UENUM()
enum class EGZUIPopupResponseType : uint8
{
	None,	
	Yes,		// (��, Ȯ��)
	No,			// (�ƴϿ�, ���)
	Input,		// ������ �Է��� ������
	Timeout		// �ð� ����
};

 /**
  * �˾� ���� �Ķ����
  * @param PopupStyle �˾� ��Ÿ��
  * @param MessageArray �޼��� �迭
  * @param ErrorMessageArray ���� �޼��� �迭
  * @param ButtonTextArray ��ư �ؽ�Ʈ �迭
  * @param ScreenKeyboardTitleTextArray ��ũ��Ű���� Ÿ��Ʋ �迭
  * @param IntArray �ѹ� �迭
  * @param BoolArray �οﰪ �迭
  * @param TargetScreen ���ӵ� ��ũ�� Ÿ��
  */
struct FGZUIPopupOpenParams
{
	EGZUIPopupStyle PopupStyle = EGZUIPopupStyle::None;
	TArray<FText> MessageArray;
	TArray<FText> ErrorMessageArray;
	TArray<FText> ButtonTextArray;
	TArray<FText> ScreenKeyboardTitleTextArray;
	TArray<int32> IntArray;
	TArray<bool> BoolArray;

	EGZUIScreen TargetScreen = EGZUIScreen::None;
};

/**
  * �˾� ���� �Ķ����
  * @param OpenType �˾� ���� Ÿ��(����ũ)
  * @param ResponseType ���� Ÿ��
  * @param UserInputString ���� �޼���
  */
struct FU1UIPopupResponseData
{
	EGZUIPopupOpenType OpenType;
	EGZUIPopupResponseType ResponseType;
	FString UserInputString;
};