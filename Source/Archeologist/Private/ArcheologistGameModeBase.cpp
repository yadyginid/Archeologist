// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcheologistGameModeBase.h"
#include "ArcheologistPawn.h"
#include "ArcheologistPlayerController.h"
#include "ArcheologistField.h"

AArcheologistGameModeBase::AArcheologistGameModeBase()
{
    DefaultPawnClass = AArcheologistPawn::StaticClass();
    PlayerControllerClass = AArcheologistPlayerController::StaticClass();
}

void AArcheologistGameModeBase::StartPlay()
{
    Super::StartPlay();

    SpawnField();
}

void AArcheologistGameModeBase::SpawnField()
{
    if (!FieldClass) return;

    GetWorld()->SpawnActor<AArcheologistField>(FieldClass, FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector::ZeroVector));
}