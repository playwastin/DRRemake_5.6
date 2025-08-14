using UnrealBuildTool;

public class DRAssetForgeEditor : ModuleRules
{
    public DRAssetForgeEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
            "UMG",
        });

        // Editor-only helpers/APIs live in these modules.
        // (The plugin is Editor-type via the .uplugin, so these are fine.)
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "UnrealEd",          // UPackageTools, content ops
            "AssetTools",
            "Projects",
            "EditorSubsystem",
            "Kismet",            // UDataTableFunctionLibrary
            "DataTableEditor"    // editor helpers for data tables (optional)
        });

        // Recommended modern defaults
        bUseUnity = true;
        CppStandard = CppStandardVersion.Cpp20;
    }
}
