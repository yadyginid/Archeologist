// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArcheologistUserWidget.h"
#include "ArcheologistMainUserWidget.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeValueCountShovels, int);

UCLASS()
class ARCHEOLOGIST_API UArcheologistMainUserWidget : public UArcheologistUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetCurrentCountShovels() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetCurrentCountGolds() const;

private:
    FOnChangeValueCountShovels OnChangeValueCountShovels;
};
