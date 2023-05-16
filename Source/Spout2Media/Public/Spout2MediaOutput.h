// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MediaOutput.h"
#include "MediaIOCoreDefinitions.h"

#include "Spout2MediaOutput.generated.h"

UCLASS(BlueprintType, meta=(DisplayName="Spout2 Media Output"))
class SPOUT2MEDIA_API USpout2MediaOutput
	: public UMediaOutput
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spout2 Media")
	FString SenderName = FString("UnrealEngine");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spout2 Media")
	FIntPoint OutputSize = FIntPoint(1920, 1080);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spout2 Media")
	TEnumAsByte<EPixelFormat> Format = PF_A2B10G10R10;
	
	virtual bool Validate(FString& OutFailureReason) const override;

	virtual FIntPoint GetRequestedSize() const override;
	virtual EPixelFormat GetRequestedPixelFormat() const override;
	virtual EMediaCaptureConversionOperation
	GetConversionOperation(EMediaCaptureSourceType InSourceType) const override;

protected:
	virtual UMediaCapture* CreateMediaCaptureImpl() override;
};
