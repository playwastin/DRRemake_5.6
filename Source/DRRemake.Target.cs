using UnrealBuildTool;

public class DRRemakeTarget : TargetRules
{
    public DRRemakeTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        // UE 5.6 recommended settings
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

        // Your primary game module (plugins are loaded via .uplugin, not here)
        ExtraModuleNames.AddRange(new string[] { "DRRemake" });
    }
}
