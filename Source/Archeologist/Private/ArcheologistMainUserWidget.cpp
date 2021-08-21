// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcheologistMainUserWidget.h"
#include "ArcheologistPawn.h"

int32 UArcheologistMainUserWidget::GetCurrentCountShovels() const
{
    const auto ArcheologistPawn = Cast<AArcheologistPawn>(GetOwningPlayerPawn());
    if (!ArcheologistPawn) return 0;

    return ArcheologistPawn->CurrentCountShovels;
}

int32 UArcheologistMainUserWidget::GetCurrentCountGolds() const
{
    const auto ArcheologistPawn = Cast<AArcheologistPawn>(GetOwningPlayerPawn());
    if (!ArcheologistPawn) return 0;

    return ArcheologistPawn->CurrentCountGolds;
}