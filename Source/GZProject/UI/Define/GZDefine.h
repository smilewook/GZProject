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

	Lobby,
	Ingame,

	Max
};

/**
 * UI State
 */
UENUM()
enum class EGZUIState : uint8
{
	None,

	Loading,
	Ingame
};