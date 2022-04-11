// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


/**
 * UI에 사용할 Define 값들 정리.
 */


 /**
  * UI Mode
  */
UENUM()
enum class EGZUIMode : uint8
{
	None,

	/*Lobby*/
	Lobby,

	/*Ingame*/
	DrivingRange,					//	드라이빙레인지
	DrivingRangeLongGame,			//	드라이빙레인지 - 롱게임
	DrivingRangeShortGame,			//	드라이빙레인지 - 숏게임
	DrivingRangePutting,			//	드라이빙레인지 - 퍼팅

	NetworkChallenge,				//	네트워크챌린지
	NetworkChallengePersonal,		//	네트워크챌린지 - 퍼스널
	NetworkChallengeTimeAttack,		//	네트워크챌린지 - 타임어택
	NetworkChallengeSponsor,		//	네트워크챌린지 - 스폰서

	PracticeRound,					//	연습라운드
	PracticeRoundNineHole,			//	연습라운드 - 9홀
	PracticeRoundEighteenHole,		//	연습라운드 - 18홀

	Max
};

/**
 * UI State
 */
UENUM()
enum class EGZUIState : uint8
{
	None,

	Loading,						//	로딩
	Intro,							//	인트로

	Ingame,

	Max
};