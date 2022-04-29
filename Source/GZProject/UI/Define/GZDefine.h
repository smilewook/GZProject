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
	// LOADING
	Loading,						// �ε�
	Intro,							// ��Ʈ��
	Patch,							// ��ġ �� �ε�
	AdminSetting,					// ������ �޴�

	//-----------------------------------------------------------------------------------------------
	// LOBBY
	Login,							// �α���
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
	Ingame,							// �ΰ���(����̺� ������, ��Ʈ��ũ ç����, ��������)
	
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

	ExitProgram,					// ���α׷� ����

	Max
};