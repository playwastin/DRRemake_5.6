// DR_AssetForgeLibrary.h (UE 5.6.1)
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DR_AssetForgeLibrary.generated.h"

class UDataTable;
class UScriptStruct;

UCLASS()
class DRASSETFORGEEDITOR_API UDR_AssetForgeLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Import CSV into an existing DataTable. Returns true when there are no errors. */
    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|AssetForge")
    static bool ImportCSVToDataTable(UDataTable* TargetDataTable, const FString& CSVString);

#if WITH_EDITOR
    /** Create a new DataTable asset at /Game/... using a given RowStruct. */
    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|AssetForge|Editor")
    static UDataTable* CreateDataTableAsset(const FString& PackagePath /*e.g. /Game/Data*/,
                                            const FString& AssetName /*e.g. Items*/,
                                            UScriptStruct* RowStruct);
#endif
};
