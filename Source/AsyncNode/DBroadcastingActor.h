// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBroadcastingActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsDeadChanged, bool, NewValue);

UCLASS()
class ASYNCNODE_API ADBroadcastingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADBroadcastingActor();

protected:

	bool bIsDead;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMeshComp;

public:

	// Delegate that is broadcasted when IsDead changes
	FIsDeadChanged OnIsDeadChanged;

	UFUNCTION(BlueprintCallable)
	void SetIsDead(bool NewValue);

	UFUNCTION(BlueprintCallable)
	bool GetIsDead();

};
