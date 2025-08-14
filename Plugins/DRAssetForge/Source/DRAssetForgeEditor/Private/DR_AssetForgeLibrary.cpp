// DR_AssetForgeLibrary.cpp (UE 5.6.1)
#include "DR_AssetForgeLibrary.h"        // MUST be first

#include "Engine/DataTable.h"            // UDataTable
#include "UObject/Package.h"             // CreatePackage(), UPackage
#include "UObject/SoftObjectPtr.h"

#if WITH_EDITOR
#include "AssetRegistry/AssetRegistryModule.h"
#include "Modules/ModuleManager.h"
#include "Misc/PackageName.h"
#endif

bool UDR_AssetForgeLibrary::ImportCSVToDataTable(UDataTable* TargetDataTable, const FString& CSVString)
{
    if (!TargetDataTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("ImportCSVToDataTable: TargetDataTable is null"));
        return false;
    }

    // UE 5.6: returns error strings (empty == success)
    TArray<FString> Errors = TargetDataTable->CreateTableFromCSVString(CSVString);
    if (Errors.Num() > 0)
    {
        for (const FString& Err : Errors)
        {
            UE_LOG(LogTemp, Error, TEXT("CSV import error: %s"), *Err);
        }
        return false;
    }

#if WITH_EDITOR
    if (UPackage* Pkg = TargetDataTable->GetOutermost())
    {
        Pkg->SetDirtyFlag(true); // mark asset needing save in the editor
    }
#endif
    return true;
}

#if WITH_EDITOR
UDataTable* UDR_AssetForgeLibrary::CreateDataTableAsset(const FString& PackagePath, const FString& AssetName, UScriptStruct* RowStruct)
{
    if (PackagePath.IsEmpty() || AssetName.IsEmpty() || RowStruct == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("CreateDataTableAsset: invalid args"));
        return nullptr;
    }

    // Normalize path: ensure it starts with /Game
    FString SafePath = PackagePath;
    if (!SafePath.StartsWith(TEXT("/Game")))
    {
        SafePath = TEXT("/Game") / SafePath;
    }

    const FString LongPackageName = SafePath / AssetName;

    // Create package using the global function (UE 5.x)
    UPackage* Package = CreatePackage(*LongPackageName);
    if (!Package)
    {
        UE_LOG(LogTemp, Error, TEXT("CreateDataTableAsset: failed to create package %s"), *LongPackageName);
        return nullptr;
    }

    // Create the DataTable object
    UDataTable* NewTable = NewObject<UDataTable>(Package, *AssetName, RF_Public | RF_Standalone);
    if (!NewTable)
    {
        UE_LOG(LogTemp, Error, TEXT("CreateDataTableAsset: failed to create DataTable in %s"), *LongPackageName);
        return nullptr;
    }

    NewTable->RowStruct = RowStruct;
    NewTable->MarkPackageDirty();

    // Register with asset registry so it shows up in Content Browser
    FAssetRegistryModule::AssetCreated(NewTable);

    // We do NOT call UPackage::SavePackage here to avoid signature drift across UE versions.
    // The asset is created, registered, and marked dirty — the user can Ctrl+S in the editor.

    return NewTable;
}
#endif // WITH_EDITOR
