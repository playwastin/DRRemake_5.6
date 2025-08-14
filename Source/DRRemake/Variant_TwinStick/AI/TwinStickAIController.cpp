// Copyright Epic Games, Inc. All Rights Reserved.
// --- includes ---
#include "Variant_TwinStick/TwinStickAIController.h"  // first
#include "Variant_TwinStick/AI/TwinStickNPC.h"

// If you’re using StateTree AI component, include its headers too (already handled in Build.cs):
// #include "Components/StateTreeAIComponent.h"

// (keep the rest of your includes here)


#include "TwinStickAIController.h"
#include "Components/StateTreeAIComponent.h"

ATwinStickAIController::ATwinStickAIController()
{
	// create the StateTree AI Component
	StateTreeAI = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeAI"));
	check(StateTreeAI);

	// ensure we start the StateTree when we possess the pawn
	bStartAILogicOnPossess = true;

	// ensure we're attached to the possessed character.
	// this is necessary for EnvQueries to work correctly
	bAttachToPawn = true;
}