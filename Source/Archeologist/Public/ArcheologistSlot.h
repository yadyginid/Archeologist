// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcheologistSlot.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeValueCountShovels, int);

class AArcheologistTreasure;

UCLASS()
class ARCHEOLOGIST_API AArcheologistSlot : public AActor
{
    GENERATED_BODY()

public:
    AArcheologistSlot();

    bool GetBlock() const { return isBlocked; };

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

    FOnChangeValueCountShovels OnChangeValueCountShovels;

    UPROPERTY(EditDefaultsOnly)
    int32 Chance = 10;

    UPROPERTY(EditDefaultsOnly)
    int32 Deep = 3;
};
