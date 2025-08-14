using UnrealBuildTool;

public class DRRemake : ModuleRules
{
    public DRRemake(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",          // UInputAction, MappingContext
            "Niagara",                // UNiagaraSystem
            "NavigationSystem",       // UNavigationSystemV1::K2_* helpers
            "AIModule",               // AIController, Behavior
            "GameplayTasks"           // AI tasks
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "StateTreeModule",        // if you use StateTree
            "GameplayStateTreeModule" // UStateTreeAIComponent
        });
    }
}
