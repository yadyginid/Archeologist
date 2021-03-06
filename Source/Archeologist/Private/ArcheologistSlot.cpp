// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcheologistSlot.h"
#include "ArcheologistGameModeBase.h"
#include "ArcheologistPawn.h"
#include "ArcheologistTreasure.h"
#include "Kismet/KismetMathLibrary.h"

AArcheologistSlot::AArcheologistSlot()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AArcheologistSlot::BeginPlay()
{
    Super::BeginPlay();

    this->OnClicked.AddDynamic(this, &AArcheologistSlot::TryGenerateTreasure);
}

bool AArcheologistSlot::CheckCanDig()
{
    if (!GetWorld()) return false;

    const AArcheologistGameModeBase* ArcheologistGameModeBase = Cast<AArcheologistGameModeBase>(GetWorld()->GetAuthGameMode());
    const AArcheologistPawn* ArcheologistPawn = Cast<AArcheologistPawn>(ArcheologistGameModeBase->GetArcheologistPawn());

    if (!ArcheologistGameModeBase || !ArcheologistPawn) return false;

    if (1 > Deep) SetBlock(true);
    if (GetBlock() || !ArcheologistPawn->IsNotEmptyShovels()) return false;

    return true;
}

void AArcheologistSlot::TryGenerateTreasure(AActor* Target, FKey ButtonPressed)
{
    if (!TreasureClass || !CheckCanDig()) return;

    const AArcheologistGameModeBase* ArcheologistGameModeBase = Cast<AArcheologistGameModeBase>(GetWorld()->GetAuthGameMode());
    AArcheologistPawn* ArcheologistPawn = Cast<AArcheologistPawn>(ArcheologistGameModeBase->GetArcheologistPawn());

    ArcheologistPawn->OnChangeValueCountShovels.Broadcast(-1);
    Deep--;

    if (1 > Deep) SetBlock(true);

    // generate chance
    if (FMath::RandRange(1, 100 / Chance) == 1)
    {
        FVector SpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 2);

        FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, SpawnLocation, FVector(1));

        Treasure = GetWorld()->SpawnActor<AArcheologistTreasure>(TreasureClass, SpawnTransform);
        Treasure->SetArcheologistSlotRef(this);
        SetBlock(true);
    }
}

void AArcheologistSlot::SetDeep(int32 value)
{
    Deep = value;
    if (1 > Deep)
    {
        SetBlock(true);
    }
    else
    {
        SetBlock(false);
    }
}