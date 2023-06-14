// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "BooleanChangedCheck.generated.h"

class ADBroadcastingActor;

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBooleanCheckOutputPin);

UCLASS()
class ASYNCNODE_API UBooleanChangedCheck : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:
	
	const UObject* WorldContextObject;

	// The actor that will broadcast it's boolean change
	UPROPERTY()
	ADBroadcastingActor* MyBroadcastingActor;

public:
	UPROPERTY(BlueprintAssignable)
	FBooleanCheckOutputPin BooleanChanged;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static UBooleanChangedCheck* CheckForBooleanChange(const UObject* WorldContextObject, ADBroadcastingActor* BroadcastingActor);
};
