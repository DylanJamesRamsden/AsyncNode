// Fill out your copyright notice in the Description page of Project Settings.


#include "BooleanChangedCheck.h"

#include "DBroadcastingActor.h"

UBooleanChangedCheck* UBooleanChangedCheck::CheckForBooleanChange(const UObject* WorldContextObject,
                                                                  ADBroadcastingActor* BroadcastingActor)
{
	UBooleanChangedCheck* NewBooleanChangedCheck = NewObject<UBooleanChangedCheck>();
	NewBooleanChangedCheck->WorldContextObject = WorldContextObject;
	NewBooleanChangedCheck->MyBroadcastingActor = BroadcastingActor;

	return NewBooleanChangedCheck;
}

void UBooleanChangedCheck::Activate()
{
	Super::Activate();

	if (MyBroadcastingActor)
	{
		MyBroadcastingActor->OnIsDeadChanged.AddDynamic(this, &UBooleanChangedCheck::OnBooleanChanged);
	}
}

void UBooleanChangedCheck::OnBooleanChanged()
{
	BooleanChanged.Broadcast();
}
