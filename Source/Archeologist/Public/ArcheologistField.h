// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcheologistField.generated.h"

class AArcheologistSlot;

UCLASS()
class ARCHEOLOGIST_API AArcheologistField : public AActor
{
    GENERATED_BODY()

public:
    AArcheologistField();

protected:
    virtual void BeginPlay() override;

private:
    void SpawnSlots();

    UPROPERTY(EditDefaultsOnly)
    int32 count_x = 10;

    UPROPERTY(EditDefaultsOnly)
    int32 count_y = 10;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AArcheologistSlot> SlotClass;

    UPROPERTY(EditDefaultsOnly)
    TArray<AArcheologistSlot*> ArrSlots;
};
