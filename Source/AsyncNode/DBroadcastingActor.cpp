// Fill out your copyright notice in the Description page of Project Settings.


#include "DBroadcastingActor.h"

// Sets default values
ADBroadcastingActor::ADBroadcastingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	RootComponent = StaticMeshComp;
}

void ADBroadcastingActor::SetIsDead(bool NewValue)
{
	// Could add a check here to see if the new value is not equal to the old. But doing that in the
	// AsyncNode class on change
	
	bIsDead = NewValue;

	OnIsDeadChanged.Broadcast(NewValue);
}

bool ADBroadcastingActor::GetIsDead()
{
	return bIsDead;
}

