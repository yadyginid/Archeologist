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

    UFUNCTION(BlueprintCallable)
    bool GetBlock() const { return isBlocked; };

    UFUNCTION(BlueprintCallable)
    void SetBlock(bool value) { isBlocked = value; };

protected:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void SetDeep(int32 value);

    UFUNCTION(BlueprintCallable)
    int32 GetDeep() const { return Deep; }

private:
    bool CheckCanDig();

    bool isBlocked = false;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AArcheologistTreasure> TreasureClass;

    UFUNCTION()
    void TryGenerateTreasure(AActor* Target, FKey ButtonPressed);

    FOnChangeValueCountShovels OnChangeValueCountShovels;

    UPROPERTY(EditDefaultsOnly)
    int32 Chance = 10;

    UPROPERTY(EditDefaultsOnly)
    int32 Deep = 3;

    AArcheologistTreasure* Treasure;
};
