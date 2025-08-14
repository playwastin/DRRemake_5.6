// DR_AssetForgeLibrary.h
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DR_AssetTypes.h"
#include "DR_AssetForgeLibrary.generated.h"

/**
 * Blueprint-callable helpers to import CSVs and generate assets.
 * Editor-only because we save packages.
 */
UCLASS()
class DRASSETFORGEEDITOR_API UDR_AssetForgeLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Create (or load) a DataTable at PackagePath and import CSV into it (using the provided RowStruct). */
    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|Assets")
    static bool ImportCSVToDataTableAsset(const FString& PackagePath, const FString& CSV, UScriptStruct* RowStruct);

    /** Convenience overloads for your known rows */
    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|Assets")
    static bool ImportItemsCSV(const FString& PackagePath, const FString& CSV) { return ImportCSVToDataTableAsset(PackagePath, CSV, FDR_ItemRow::StaticStruct()); }

    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|Assets")
    static bool ImportWeaponsCSV(const FString& PackagePath, const FString& CSV) { return ImportCSVToDataTableAsset(PackagePath, CSV, FDR_WeaponRow::StaticStruct()); }

    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|Assets")
    static bool ImportArmorsCSV(const FString& PackagePath, const FString& CSV) { return ImportCSVToDataTableAsset(PackagePath, CSV, FDR_ArmorRow::StaticStruct()); }

    UFUNCTION(CallInEditor, BlueprintCallable, Category="DR|Assets")
    static bool ImportMonstersCSV(const FString& PackagePath, const FString& CSV) { return ImportCSVToDataTableAsset(PackagePath, CSV, FDR_MonsterRow::StaticStruct()); }
};
