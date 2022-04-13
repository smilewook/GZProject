// Fill out your copyright notice in the Description page of Project Settings.


#include "GZGameInstance.h"

/** Global UGZGameInstance pointer.*/
UGZGameInstance* GInstance;

UGZGameInstance::UGZGameInstance()
{
	GZ_LOG_S(GZ, Warning);

	GInstance = this;
}

UGZGameInstance::~UGZGameInstance()
{}