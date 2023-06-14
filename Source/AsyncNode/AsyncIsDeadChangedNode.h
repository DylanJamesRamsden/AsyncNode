// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncIsDeadChangedNode.generated.h"

class ADBroadcastingActor;

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FIsDeadChangedOutputPin);

UCLASS()
class ASYNCNODE_API UAsyncIsDeadCheckNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:

	// The actor that will broadcast it's boolean change
	UPROPERTY()
	ADBroadcastingActor* MyBroadcastingActor;

	// A reference to the initial value of IsDead from MyBroadcastingActor. Used to compare
	// with the new value to ensure the BooleanChanged delegate isn't misfired
	bool InitialBoolValue;

	virtual void Activate() override;

public:
	UPROPERTY(BlueprintAssignable)
	FIsDeadChangedOutputPin OnIsDeadChanged;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncIsDeadCheckNode* AsyncIsDeadChanged(ADBroadcastingActor* BroadcastingActor);

	UFUNCTION()
	void IsDeadChanged(bool NewValue);
};
