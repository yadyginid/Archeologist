// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcheologistGameModeBase.h"
#include "ArcheologistPawn.h"
#include "ArcheologistPlayerController.h"
#include "ArcheologistField.h"
#include "ArcheologistHUD.h"

AArcheologistGameModeBase::AArcheologistGameModeBase()
{
    DefaultPawnClass = AArcheologistPawn::StaticClass();
    PlayerControllerClass = AArcheologistPlayerController::StaticClass();
    HUDClass = AArcheologistHUD::StaticClass();
}

void AArcheologistGameModeBase::StartPlay()
{
    Super::StartPlay();

    // SpawnField();

    MainArcheologistPawn = Cast<AArcheologistPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AArcheologistGameModeBase::SpawnField()
{
    if (!FieldClass) return;

    GetWorld()->SpawnActor<AArcheologistField>(FieldClass, FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector::ZeroVector));
}

void AArcheologistGameModeBase::CheckEndGame()
{
    if (MainArcheologistPawn->CurrentCountGolds >= MainArcheologistPawn->GetMaxCountGolds())
    {
        PawnWin = true;
        ShowResult();
    }

    if (0 >= MainArcheologistPawn->CurrentCountShovels)
    {
        PawnWin = false;
        ShowResult();
    }
}