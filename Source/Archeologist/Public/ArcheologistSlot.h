// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcheologistSlot.generated.h"

class AArcheologistTreasure;

UCLASS()
class ARCHEOLOGIST_API AArcheologistSlot : public AActor
{
    GENERATED_BODY()

public:
    AArcheologistSlot();

    bool GetBlock() const { return isBlocked; };

    UPROPERTY(EditDefaultsOnly)
    int32 Chance = 10;

protected:
    virtual void BeginPlay() override;

private:
    bool CheckCanDig();

    bool isBlocked = false;

    void SetBlock(bool value) { isBlocked = value; };

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AArcheologistTreasure> TreasureClass;

    UFUNCTION()
    void TryGenerateTreasure(AActor* Target, FKey ButtonPressed);
};
