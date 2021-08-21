// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcheologistGameModeBase.generated.h"

class AArcheologistField;
class AArcheologistPawn;
class USaveGame;

UCLASS()
class ARCHEOLOGIST_API AArcheologistGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AArcheologistGameModeBase();

    virtual void StartPlay() override;

    AArcheologistPawn* GetArcheologistPawn() const { return MainArcheologistPawn; }

private:
    UPROPERTY(EditDefaultsOnly, Category = "ArcheologistGameMode")
    TSubclassOf<AArcheologistField> FieldClass;

    UPROPERTY(EditDefaultsOnly, Category = "ArcheologistGameMode")
    TSubclassOf<USaveGame> SaveObject;

    void SpawnField();

    AArcheologistPawn* MainArcheologistPawn;
};
