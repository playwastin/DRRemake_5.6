using UnrealBuildTool;

public class DRAssetForgeEditor : ModuleRules
{
    public DRAssetForgeEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "Slate",
            "SlateCore",
            "AssetRegistry",
            "Json",
            "JsonUtilities",
            "Niagara"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "UnrealEd",               // editor-only helpers
            "AssetTools",
            "EditorFramework",
            "Kismet",
            "Projects",
            "AIModule",
            "NavigationSystem",
            "GameplayTasks",
            "StateTreeModule",
            "GameplayStateTreeModule"
        });
    }
}
