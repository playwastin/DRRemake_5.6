using UnrealBuildTool;

public class DRRemakeEditorTarget : TargetRules
{
    public DRRemakeEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        // UE 5.6 recommended settings
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

        // Your primary game module (plugins load themselves)
        ExtraModuleNames.AddRange(new string[] { "DRRemake" });
    }
}
