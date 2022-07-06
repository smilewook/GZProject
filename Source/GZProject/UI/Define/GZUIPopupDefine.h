// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Define/GZUIDefine.h"

/**
 * UIPopup에 공통으로 사용할 Define 값들 정리.
 */

 /**
 * 팝업 오픈 타입 :  팝업을 구분하는 유니크 값.
 */
UENUM()
enum class EGZUIPopupOpenType : uint8
{
	None,

	Loading,						// 로딩 화면
	AdminPassword,					// 관리자 암호 입력
	PlayerNameInput,				// 플레이어 이름 변경	
	ScreenKeyboard,					// 스크린 키보드

	Max
};

 /**
  * 팝업 스타일
  */
UENUM()
enum class EGZUIPopupStyle : uint8
{
	None,

	SmallNotice,					// 작은 알림 팝업
	LargeNotice,					// 큰 알림 팝업
	OneButtonConfirm,				// 확인 팝업(버튼 1개)
	TwoButtonConfirm,				// 확인 팝업(버튼 2개)
	ThreeButtonConfirm,				// 확인 팝업(버튼 3개)
	Input,							// 입력 팝업
	Password,						// 암호 입력 팝업
	Loading,						// 데이터 로딩, 통신 중 팝업
	ScreenKeyboard,					// 스크린 키보드
	ScreenNumpad,					// 스크린 숫자패드

	Max
};

/**
 * 응답 타입
 */
UENUM()
enum class EGZUIPopupResponseType : uint8
{
	None,	
	Yes,		// (예, 확인)
	No,			// (아니오, 취소)
	Input,		// 유저가 입력한 데이터
	Timeout		// 시간 오버
};

 /**
  * 팝업 오픈 파라미터
  * @param PopupStyle 팝업 스타일
  * @param MessageArray 메세지 배열
  * @param ErrorMessageArray 에러 메세지 배열
  * @param ButtonTextArray 버튼 텍스트 배열
  * @param ScreenKeyboardTitleTextArray 스크린키보드 타이틀 배열
  * @param IntArray 넘버 배열
  * @param BoolArray 부울값 배열
  * @param TargetScreen 종속된 스크린 타입
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
  * 팝업 응답 파라미터
  * @param OpenType 팝업 오픈 타입(유니크)
  * @param ResponseType 응답 타입
  * @param UserInputString 응답 메세지
  */
struct FU1UIPopupResponseData
{
	EGZUIPopupOpenType OpenType;
	EGZUIPopupResponseType ResponseType;
	FString UserInputString;
};