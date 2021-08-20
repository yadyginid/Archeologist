// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ArcheologistPawn.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeValueCountShovels, int);

UCLASS()
class ARCHEOLOGIST_API AArcheologistPawn : public APawn
{
    GENERATED_BODY()

public:
    AArcheologistPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    int32 GetCurrentCountShovels() const { return CurrentCountShovels; }
    int32 GetMaxCountShovels() const { return MaxCountShovels; }

    UFUNCTION(BlueprintCallable)
    bool IsNotEmptyShovels() const { return CurrentCountShovels > 0; }

    int32 GetCurrentCountGolds() const { return CurrentCountGolds; }
    int32 GetMaxCountGolds() const { return MaxCountGolds; }

    UFUNCTION()
    void SumToCurrentCountGolds(int32 SumValue) { CurrentCountGolds = CurrentCountGolds + SumValue; }

    UFUNCTION()
    void SumToCurrentCountShovels(int32 SumValue) { CurrentCountShovels = CurrentCountShovels + SumValue; }

    FOnChangeValueCountShovels OnChangeValueCountShovels;

    UFUNCTION(BlueprintCallable)
    void IncrCountGolds() { CurrentCountGolds++; }

private:
    UPROPERTY(EditDefaultsOnly)
    int32 MaxCountShovels = 20;

    int32 CurrentCountShovels = 20;

    bool isEmptyShovels = false;

    UPROPERTY(EditDefaultsOnly)
    int32 MaxCountGolds = 3;

    int32 CurrentCountGolds = 0;
};
