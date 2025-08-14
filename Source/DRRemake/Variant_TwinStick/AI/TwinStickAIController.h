// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"  // if you derive from AAIController

// Forward declare classes when you can; include full headers only in .cpp files:
// class ATwinStickNPC;

#include "TwinStickAIController.generated.h"

class UStateTreeAIComponent;

/**
 *  A StateTree-Enabled AI Controller for a Twin Stick Shooter game
 *  Runs NPC logic through a StateTree
 */
UCLASS(abstract)
class ATwinStickAIController : public AAIController
{
	GENERATED_BODY()
	
	/** StateTree Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UStateTreeAIComponent* StateTreeAI;

public:

	/** Constructor */
	ATwinStickAIController();
};
