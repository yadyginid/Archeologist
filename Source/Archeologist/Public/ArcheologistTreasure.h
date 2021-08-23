// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcheologistTreasure.generated.h"

class AArcheologistSlot;

UCLASS()
class ARCHEOLOGIST_API AArcheologistTreasure : public AActor
{
    GENERATED_BODY()
public:
    AArcheologistTreasure();

    void SetArcheologistSlotRef(AArcheologistSlot* AArcheologistSlot) { ArcheologistSlotRef = AArcheologistSlot; };

    UFUNCTION(BlueprintCallable)
    AArcheologistSlot* ArcheologistSlotRefGet() const { return ArcheologistSlotRef; };

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly)
    int32 points = 1;

    AArcheologistSlot* ArcheologistSlotRef;
};
