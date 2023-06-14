// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncIsDeadChangedNode.generated.h"

class ADBroadcastingActor;

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanCheckOutputPin);

UCLASS()
class ASYNCNODE_API UAsyncIsDeadCheckNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:
	
	const UObject* WorldContextObject;

	// The actor that will broadcast it's boolean change
	UPROPERTY()
	ADBroadcastingActor* MyBroadcastingActor;

	bool InitialBoolValue;

	virtual void Activate() override;

public:
	UPROPERTY(BlueprintAssignable)
	FBooleanCheckOutputPin BooleanChanged;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static UAsyncIsDeadCheckNode* AsyncIsDeadChanged(const UObject* WorldContextObject, ADBroadcastingActor* BroadcastingActor);

	UFUNCTION()
	void IsDeadChanged(bool NewValue);
};