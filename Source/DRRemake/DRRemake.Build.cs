using UnrealBuildTool;

public class DRRemake : ModuleRules
{
    public DRRemake(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp20;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine",
            "InputCore",
            "NavigationSystem",   // UNavigationSystemV1, ARecastNavMesh
            "AIModule",           // AIController etc.
            "GameplayTasks",      // AI/Tasks
            "EnhancedInput",      // Enhanced input
            "Niagara"             // Niagara types if referenced
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Slate", "SlateCore", "UMG"
        });
    }
}
