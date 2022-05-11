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
	Ingame,

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
	// LOBBY
	Loading,						// 로딩
	Intro,							// 인트로
	Patch,							// 패치 및 로딩
	Login,							// 로그인
	Attention,						// 주의 사항
	AdminSetting,					// 관리자 메뉴		

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
	InGame,							// 인게임(드라이빙 레인지, 네트워크 챌린지, 연습라운드)	
	
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

	Menu,							// 메뉴

	ExitProgram,					// 프로그램 종료

	Max
};

/**
 * UI Name
 */
UENUM()
enum class EGZUIName : uint8
{
	None,

	//-----------------------------------------------------------------------------------------------
	// LOBBY
	Loading,						// 로딩

	Advertisement,					// 광고
	Admin,							// 관리자
	Attention,						// 주의사항
	GoodsSelect,					// 상품 선택
	GTMTime,						// GTM 시간표시
	GuestTimeSelect,				// 게스트 시간 선택
	IdleRank,						// 랭킹(매장,지역)
	Login,							// 로그인
	Menu,							// 메뉴
	Network,						// 네크워크
	Password,						// 비밀번호

	//-----------------------------------------------------------------------------------------------
	// INGAME
	InGame,							// 인게임(드라이빙 레인지, 네트워크 챌린지, 연습라운드)	

	PlayerInfo,						// 플레이어 정보
	TargetShow,						// 비거리 타겟 위치 표시 애니메이션
	TargetInfo,						// 타겟 정보(비거리..)
	BallIndicator,					// 볼 날아가는 위치 표시
	ShotResult,						// 샷 결과
	ShotHeight,						// 샷 높이
	GroundAttribute,				// 지형 속성(페어웨이,러프..)
	ShotDataRange,					// 샷 데이터(캐리,런,발사각...)
	ShotDataClub,					// 클럽 데이터(클럽패스..)
	BallSensor,						// 볼 센서
	SensorReady,					// 센서 레디 표시
	ModeInfo,						// 모드 정보(CC정보, 홀정보, 남은거리..)
	ScreenMinimap,					// 스크린 미니맵
	ShowCombo,						// 콤보 표시(똑딱이 연속 득점..)
	Notice,							// 경고
	ChallengeRanking,				// 챌린지 랭킹
	ChallengeLevelUp,				// 챌린지 레벨업 연출
	ChallengeCelebration,			// 챌린지 성공 연출

	PlayerDetail,					// 플레이어 세부 정보(현재 접속한 데이터)
	Nasmo,							// 나스모
	NasmoAuto,						// 자동 나스모
	ContactLesson,					// 샷 점검
	LocationSelect,					// 필드 연습 위치 변경
	ChallengeResult,				// 챌린지 결과
	RoundOption,					// 라운드 옵션(라운드 모드에서 환경설정)
	InterimResult,					// 중간 결과(분석 및 게임 중 결과창)
	FinalResult,					// 최종 결과

	ClubSelect,						// 클럽 선택
	CommonOption,					// 환경 설정
	TeeHeight,						// 티 높이 선택

	CommonPopup,					// 팝업
	

	Max
};