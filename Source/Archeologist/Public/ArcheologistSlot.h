// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcheologistSlot.generated.h"

UCLASS()
class ARCHEOLOGIST_API AArcheologistSlot : public AActor
{
    GENERATED_BODY()

public:
    AArcheologistSlot();

protected:
    virtual void BeginPlay() override;
};
