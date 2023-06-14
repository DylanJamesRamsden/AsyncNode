// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncIsDeadChangedNode.h"

#include "DBroadcastingActor.h"

UAsyncIsDeadCheckNode* UAsyncIsDeadCheckNode::AsyncIsDeadChanged(ADBroadcastingActor* BroadcastingActor)
{
	UAsyncIsDeadCheckNode* NewBooleanChangedCheck = NewObject<UAsyncIsDeadCheckNode>();
	NewBooleanChangedCheck->MyBroadcastingActor = BroadcastingActor;

	return NewBooleanChangedCheck;
}

void UAsyncIsDeadCheckNode::Activate()
{
	Super::Activate();

	if (MyBroadcastingActor)
	{
		InitialBoolValue = MyBroadcastingActor->GetIsDead();
		MyBroadcastingActor->OnIsDeadChanged.AddDynamic(this, &UAsyncIsDeadCheckNode::IsDeadChanged);
	}
}

void UAsyncIsDeadCheckNode::IsDeadChanged(bool NewValue)
{
	if (NewValue != InitialBoolValue)
	{
		OnIsDeadChanged.Broadcast();
	}
}
