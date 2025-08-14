// DR_AssetForgeLibrary.cpp
#include "DR_AssetForgeLibrary.h"   // must be first
#include "DR_DataTableHelper.h"
#include "Misc/PackageName.h"
#include "UObject/Package.h"
#include "Misc/Paths.h"

bool UDR_AssetForgeLibrary::ImportCSVToDataTableAsset(const FString& PackagePath, const FString& CSV, UScriptStruct* RowStruct)
{
    if (PackagePath.IsEmpty() || CSV.IsEmpty() || !RowStruct)
    {
        UE_LOG(LogTemp, Error, TEXT("ImportCSVToDataTableAsset: invalid inputs"));
        return false;
    }

    UDataTable* Table = FDR_DataTableHelper::CreateOrLoadDataTableAsset(PackagePath, RowStruct);
    if (!Table)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create/load DataTable at %s"), *PackagePath);
        return false;
    }

    if (!FDR_DataTableHelper::ImportCSVToDataTable(Table, CSV, RowStruct))
    {
        UE_LOG(LogTemp, Error, TEXT("CSV import failed for %s"), *PackagePath);
        return false;
    }

    // Resolve content file path for saving
    FString PackageFilename;
    if (!FPackageName::DoesPackageExist(PackagePath, &PackageFilename))
    {
        // First save; compose .uasset path under Content
        FString RelContent;
        const bool bOk = FPackageName::TryConvertLongPackageNameToFilename(PackagePath, RelContent, TEXT(".uasset"));
        if (!bOk)
        {
            UE_LOG(LogTemp, Error, TEXT("Cannot convert package path to file path: %s"), *PackagePath);
            return false;
        }
        PackageFilename = RelContent;
    }

    UPackage* Package = Table->GetOutermost();
    if (!FDR_DataTableHelper::SavePackageToDisk(Package, Table, PackageFilename))
    {
        UE_LOG(LogTemp, Error, TEXT("Save package failed: %s"), *PackageFilename);
        return false;
    }

    UE_LOG(LogTemp, Display, TEXT("Imported & saved DataTable: %s"), *PackagePath);
    return true;
}
