// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


/**
 * UI�� ����� Define ���� ����.
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
	DrivingRange,					//	����̺�������
	DrivingRangeLongGame,			//	����̺������� - �հ���
	DrivingRangeShortGame,			//	����̺������� - ������
	DrivingRangePutting,			//	����̺������� - ����

	NetworkChallenge,				//	��Ʈ��ũç����
	NetworkChallengePersonal,		//	��Ʈ��ũç���� - �۽���
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

	Loading,						//	�ε�
	Intro,							//	��Ʈ��

	Ingame,

	Max
};