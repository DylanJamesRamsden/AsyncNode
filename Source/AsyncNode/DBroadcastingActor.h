// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBroadcastingActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FIsDeadChanged);

UCLASS()
class ASYNCNODE_API ADBroadcastingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADBroadcastingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsDead;

public:

	FIsDeadChanged OnIsDeadChanged;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
