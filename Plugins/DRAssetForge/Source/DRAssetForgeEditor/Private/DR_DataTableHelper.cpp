// DR_DataTableHelper.cpp
#include "DR_DataTableHelper.h"                 // must be first include
#include "Kismet/DataTableFunctionLibrary.h"    // UDataTableFunctionLibrary
#include "UObject/SavePackage.h"                // UPackage::SavePackage + FSavePackageArgs
#include "AssetToolsModule.h"
#include "Editor.h"
#include "PackageTools.h"                       // UPackageTools (from UnrealEd)
#include "Misc/PackageName.h"
#include "UObject/Package.h"
#include "HAL/FileManager.h"

bool FDR_DataTableHelper::ImportCSVToDataTable(UDataTable* DataTable, const FString& CSV, UScriptStruct* RowStruct)
{
    if (!DataTable || !RowStruct)
    {
        UE_LOG(LogTemp, Error, TEXT("ImportCSVToDataTable: invalid inputs"));
        return false;
    }

    // In 5.x use UDataTableFunctionLibrary
    const bool bOk = UDataTableFunctionLibrary::FillDataTableFromCSVString(DataTable, CSV, RowStruct);
    return bOk;
}

UDataTable* FDR_DataTableHelper::CreateOrLoadDataTableAsset(const FString& PackagePath, UScriptStruct* RowStruct)
{
    if (PackagePath.IsEmpty() || !RowStruct)
    {
        UE_LOG(LogTemp, Error, TEXT("CreateOrLoadDataTableAsset: bad params"));
        return nullptr;
    }

    FString Sanitized = UPackageTools::SanitizePackageName(PackagePath);

    // Create or find package
    UPackage* Package = FindPackage(nullptr, *Sanitized);
    if (!Package)
    {
        Package = CreatePackage(*Sanitized);
    }

    // Asset name is the leaf of the package path
    FString AssetName;
    {
        FString PackageNameOnly;
        FString PackagePathOnly;
        FPackageName::SplitLongPackageName(Sanitized, PackagePathOnly, PackageNameOnly);
        AssetName = PackageNameOnly;
    }

    UDataTable* DataTable = FindObject<UDataTable>(Package, *AssetName);
    if (!DataTable)
    {
        DataTable = NewObject<UDataTable>(Package, *AssetName, RF_Public | RF_Standalone);
        DataTable->RowStruct = RowStruct;
        DataTable->MarkPackageDirty();
    }
    return DataTable;
}

bool FDR_DataTableHelper::SavePackageToDisk(UPackage* Package, UObject* Asset, const FString& FilePath)
{
    if (!Package || !Asset || FilePath.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("SavePackageToDisk: bad params"));
        return false;
    }

    IFileManager::Get().MakeDirectory(*FPaths::GetPath(FilePath), true);

    FSavePackageArgs Args;
    Args.TopLevelFlags = RF_Public | RF_Standalone;
    Args.SaveFlags = SAVE_NoError;
    Args.Error = GError;

    const bool bSaved = UPackage::SavePackage(Package, Asset, *FilePath, Args);
    if (!bSaved)
    {
        UE_LOG(LogTemp, Error, TEXT("SavePackageToDisk: SavePackage failed: %s"), *FilePath);
    }
    return bSaved;
}
