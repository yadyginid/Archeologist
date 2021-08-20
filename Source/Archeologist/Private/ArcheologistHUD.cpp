// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcheologistHUD.h"
#include "ArcheologistUserWidget.h"

void AArcheologistHUD::BeginPlay()
{
    Super::BeginPlay();

    if (!MainGameWidgetClass) return;

    MainGameWidget = CreateWidget<UArcheologistUserWidget>(GetWorld(), MainGameWidgetClass);

    if (MainGameWidget)
    {
        MainGameWidget->AddToViewport();
    }
}