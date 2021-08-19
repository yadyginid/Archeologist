// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ArcheologistPawn.generated.h"

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

private:
    UPROPERTY(EditDefaultsOnly)
    int32 MaxCountShovels = 20;

    int32 CurrentCountShovels = 20;

    bool isEmptyShovels = false;
};
