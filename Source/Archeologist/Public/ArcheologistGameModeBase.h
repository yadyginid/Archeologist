// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcheologistGameModeBase.generated.h"

UCLASS()
class ARCHEOLOGIST_API AArcheologistGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AArcheologistGameModeBase();

    virtual void StartPlay() override;
};
