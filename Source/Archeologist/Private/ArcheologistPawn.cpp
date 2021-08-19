// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcheologistPawn.h"

AArcheologistPawn::AArcheologistPawn()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AArcheologistPawn::BeginPlay()
{
    Super::BeginPlay();
}

void AArcheologistPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
