#pragma once
#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "CoreMinimal.h"

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DR_AssetForgeSettings.generated.h"

/** Project-wide settings for DR Asset Forge */
UCLASS(Config=Editor, DefaultConfig, meta=(DisplayName="DR Asset Forge Settings"))
class DRASSETFORGEEDITOR_API UDR_AssetForgeSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    /** Where newly created assets are placed */
    UPROPERTY(EditAnywhere, Config, Category="Paths", meta=(ContentDir))
    FDirectoryPath ItemsFolder;

    UPROPERTY(EditAnywhere, Config, Category="Paths", meta=(ContentDir))
    FDirectoryPath MonstersFolder;

    UPROPERTY(EditAnywhere, Config, Category="Paths", meta=(ContentDir))
    FDirectoryPath MountsFolder;

    /** Target DataTables that should be updated when assets are created */
    UPROPERTY(EditAnywhere, Config, Category="DataTables")
    TSoftObjectPtr<UDataTable> DT_Items;

    UPROPERTY(EditAnywhere, Config, Category="DataTables")
    TSoftObjectPtr<UDataTable> DT_Monsters;

    UPROPERTY(EditAnywhere, Config, Category="DataTables")
    TSoftObjectPtr<UDataTable> DT_Mounts;
};



