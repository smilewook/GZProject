// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


/**
 * UI에 사용할 Define 값들 정리.
 */


 /**
  * 위젯을 배치할 타겟 윈도우
  */
UENUM()
enum class EGZUIScreen : uint8
{
	Main,
	All
};

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
	DrivingRangeShortGame,			//	드라이빙레인지 - 온그린(숏게임)
	DrivingRangePutting,			//	드라이빙레인지 - 퍼팅
	DrivingRangeTroubleShot,		//	드라이빙레인지 - 트러블샷

	NetworkChallenge,				//	네트워크챌린지
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

	//-----------------------------------------------------------------------------------------------
	// LOADING
	Loading,						// 로딩
	Intro,							// 인트로
	Patch,							// 패치 및 로딩
	AdminSetting,					// 관리자 메뉴

	//-----------------------------------------------------------------------------------------------
	// LOBBY
	Login,							// 로그인
	PlayerSetting,					// 플레이어 설정
	PlayerRegistration,				// 플레이어 등록
	TimeSetting,					// 시간 설정
	HoleTimeSetting,				// 홀/시간 설정
	ModeSelection,					// 모드 선택
	ModeGuide,						// 모드별 안내
	RangeTypeSelection,				// 연습장 유형 선택(드라이빙 레인지)
	ClubSelection,					// 클럽 선택(드라이빙 레인지)
	ChallengeTypeSelection,			// 챌린지 유형 선택(네크워크 레인지)
	ChallengeSelection,				// 챌린지 선택(네크워크 챌린지)	
	HoleTypeSelection,				// 홀 유형 선택(연습라운드)
	CCSelection,					// CC 선택(연습라운드)

	//-----------------------------------------------------------------------------------------------
	// INGAME
	Ingame,							// 인게임(드라이빙 레인지, 네트워크 챌린지, 연습라운드)
	
	CoursePreview,					// 코스 미리보기
	AnalysisHole,					// 홀 분석
	LowView,						// 시선 낮추기
	GreenUndulation,				// 그린 굴곡
	Replay,							// 리플레이
	Scorecard,						// 스코어카드	
	RoundBoard,						// 라운드보드
	DropBall,						// 볼 드롭
	ShotReady,						// 샷 준비
	Shot,							// 샷
	ShotEnd,						// 샷 종료
	HoleEnd,						// 홀 종료
	GameEnd,						// 라운드 종료

	ExitProgram,					// 프로그램 종료

	Max
};