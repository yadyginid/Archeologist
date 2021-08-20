// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArcheologistHUD.generated.h"

class UArcheologistUserWidget;

UCLASS() class ARCHEOLOGIST_API AArcheologistHUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> MainGameWidgetClass;

    UArcheologistUserWidget* MainGameWidget;
};
