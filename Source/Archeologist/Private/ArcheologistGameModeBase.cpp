// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcheologistGameModeBase.h"
#include "ArcheologistPawn.h"
#include "ArcheologistPlayerController.h"

AArcheologistGameModeBase::AArcheologistGameModeBase()
{
    DefaultPawnClass = AArcheologistPawn::StaticClass();
    PlayerControllerClass = AArcheologistPlayerController::StaticClass();
}

void AArcheologistGameModeBase::StartPlay()
{
    Super::StartPlay();
}