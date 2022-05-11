// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


/**
 * UI�� ����� Define ���� ����.
 */


 /**
  * ������ ��ġ�� Ÿ�� ������
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

	DrivingRange,					//	����̺�������
	DrivingRangeLongGame,			//	����̺������� - �հ���
	DrivingRangeShortGame,			//	����̺������� - �±׸�(������)
	DrivingRangePutting,			//	����̺������� - ����
	DrivingRangeTroubleShot,		//	����̺������� - Ʈ����

	NetworkChallenge,				//	��Ʈ��ũç����
	NetworkChallengeTimeAttack,		//	��Ʈ��ũç���� - Ÿ�Ӿ���
	NetworkChallengeSponsor,		//	��Ʈ��ũç���� - ������

	PracticeRound,					//	��������
	PracticeRoundNineHole,			//	�������� - 9Ȧ
	PracticeRoundEighteenHole,		//	�������� - 18Ȧ

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
	Loading,						// �ε�
	Intro,							// ��Ʈ��
	Patch,							// ��ġ �� �ε�
	Login,							// �α���
	Attention,						// ���� ����
	AdminSetting,					// ������ �޴�		

	PlayerSetting,					// �÷��̾� ����
	PlayerRegistration,				// �÷��̾� ���
	TimeSetting,					// �ð� ����
	HoleTimeSetting,				// Ȧ/�ð� ����
	ModeSelection,					// ��� ����
	ModeGuide,						// ��庰 �ȳ�
	RangeTypeSelection,				// ������ ���� ����(����̺� ������)
	ClubSelection,					// Ŭ�� ����(����̺� ������)
	ChallengeTypeSelection,			// ç���� ���� ����(��ũ��ũ ������)
	ChallengeSelection,				// ç���� ����(��ũ��ũ ç����)	
	HoleTypeSelection,				// Ȧ ���� ����(��������)
	CCSelection,					// CC ����(��������)

	//-----------------------------------------------------------------------------------------------
	// INGAME
	InGame,							// �ΰ���(����̺� ������, ��Ʈ��ũ ç����, ��������)	
	
	CoursePreview,					// �ڽ� �̸�����
	AnalysisHole,					// Ȧ �м�
	LowView,						// �ü� ���߱�
	GreenUndulation,				// �׸� ����
	Replay,							// ���÷���
	Scorecard,						// ���ھ�ī��	
	RoundBoard,						// ���庸��
	DropBall,						// �� ���
	ShotReady,						// �� �غ�
	Shot,							// ��
	ShotEnd,						// �� ����
	HoleEnd,						// Ȧ ����
	GameEnd,						// ���� ����

	Menu,							// �޴�

	ExitProgram,					// ���α׷� ����

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
	Loading,						// �ε�

	Advertisement,					// ����
	Admin,							// ������
	Attention,						// ���ǻ���
	GoodsSelect,					// ��ǰ ����
	GTMTime,						// GTM �ð�ǥ��
	GuestTimeSelect,				// �Խ�Ʈ �ð� ����
	IdleRank,						// ��ŷ(����,����)
	Login,							// �α���
	Menu,							// �޴�
	Network,						// ��ũ��ũ
	Password,						// ��й�ȣ

	//-----------------------------------------------------------------------------------------------
	// INGAME
	InGame,							// �ΰ���(����̺� ������, ��Ʈ��ũ ç����, ��������)	

	PlayerInfo,						// �÷��̾� ����
	TargetShow,						// ��Ÿ� Ÿ�� ��ġ ǥ�� �ִϸ��̼�
	TargetInfo,						// Ÿ�� ����(��Ÿ�..)
	BallIndicator,					// �� ���ư��� ��ġ ǥ��
	ShotResult,						// �� ���
	ShotHeight,						// �� ����
	GroundAttribute,				// ���� �Ӽ�(������,����..)
	ShotDataRange,					// �� ������(ĳ��,��,�߻簢...)
	ShotDataClub,					// Ŭ�� ������(Ŭ���н�..)
	BallSensor,						// �� ����
	SensorReady,					// ���� ���� ǥ��
	ModeInfo,						// ��� ����(CC����, Ȧ����, �����Ÿ�..)
	ScreenMinimap,					// ��ũ�� �̴ϸ�
	ShowCombo,						// �޺� ǥ��(�ȵ��� ���� ����..)
	Notice,							// ���
	ChallengeRanking,				// ç���� ��ŷ
	ChallengeLevelUp,				// ç���� ������ ����
	ChallengeCelebration,			// ç���� ���� ����

	PlayerDetail,					// �÷��̾� ���� ����(���� ������ ������)
	Nasmo,							// ������
	NasmoAuto,						// �ڵ� ������
	ContactLesson,					// �� ����
	LocationSelect,					// �ʵ� ���� ��ġ ����
	ChallengeResult,				// ç���� ���
	RoundOption,					// ���� �ɼ�(���� ��忡�� ȯ�漳��)
	InterimResult,					// �߰� ���(�м� �� ���� �� ���â)
	FinalResult,					// ���� ���

	ClubSelect,						// Ŭ�� ����
	CommonOption,					// ȯ�� ����
	TeeHeight,						// Ƽ ���� ����

	CommonPopup,					// �˾�
	

	Max
};