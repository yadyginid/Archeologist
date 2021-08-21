// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcheologistPawn.h"
#include "ArcheologistGameModeBase.h"

AArcheologistPawn::AArcheologistPawn()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AArcheologistPawn::BeginPlay()
{
    Super::BeginPlay();
    OnChangeValueCountShovels.AddUObject(this, &AArcheologistPawn::SumToCurrentCountShovels);
}

void AArcheologistPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AArcheologistPawn::SumToCurrentCountGolds(int32 SumValue)
{
    CurrentCountGolds = CurrentCountGolds + SumValue;
}

void AArcheologistPawn::IncrCountGolds()
{
    CurrentCountGolds++;

    if (!GetWorld()) return;

    const auto GameMode = Cast<AArcheologistGameModeBase>(GetWorld()->GetAuthGameMode());
    if (!GameMode) return;

    GameMode->CheckEndGame();
}

void AArcheologistPawn::SumToCurrentCountShovels(int32 SumValue)
{
    CurrentCountShovels = CurrentCountShovels + SumValue;

    if (!GetWorld()) return;

    const auto GameMode = Cast<AArcheologistGameModeBase>(GetWorld()->GetAuthGameMode());
    if (!GameMode) return;

    GameMode->CheckEndGame();
}