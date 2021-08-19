// Fill out your copyright notice in the Description page of Project Settings.

#include "ArcheologistField.h"
#include "ArcheologistSlot.h"

AArcheologistField::AArcheologistField()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AArcheologistField::BeginPlay()
{
    Super::BeginPlay();

    SpawnSlots();
}

void AArcheologistField::SpawnSlots()
{
    if (!GetWorld() || !SlotClass) return;

    int32 y = 0;
    int32 x = 0;

    for (int i = 0; i < count_y; i++)
    {
        y = y + 165;  // 165 - отступ
        x = 0;

        for (int j = 0; j < count_x; j++)
        {
            x = x + 165;

            FVector SpawnLocation = FVector(x, y, 0);
            FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, SpawnLocation, FVector(0.2));

            AArcheologistSlot* SpawnSlotNew = GetWorld()->SpawnActor<AArcheologistSlot>(SlotClass, SpawnTransform);

            if (!SpawnSlotNew) return;
            ArrSlots.Push(SpawnSlotNew);
        }
    }
}