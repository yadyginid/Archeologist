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
};
