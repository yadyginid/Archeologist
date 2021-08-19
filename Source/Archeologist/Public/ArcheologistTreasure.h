// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcheologistTreasure.generated.h"

UCLASS()
class ARCHEOLOGIST_API AArcheologistTreasure : public AActor
{
    GENERATED_BODY()

public:
    AArcheologistTreasure();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly)
    int32 points = 1;
};
