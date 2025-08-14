// DR_DataTableHelper.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

class DRASSETFORGEEDITOR_API FDR_DataTableHelper
{
public:
    /**
     * Import CSV text into a UDataTable using the correct 5.6 API.
     * Returns true on success.
     */
    static bool ImportCSVToDataTable(UDataTable* DataTable, const FString& CSV, UScriptStruct* RowStruct);

    /**
     * Create or find a DataTable asset at /Game/... and save it.
     * PackagePath is like "/Game/Data/DT_Items".
     */
    static UDataTable* CreateOrLoadDataTableAsset(const FString& PackagePath, UScriptStruct* RowStruct);

    /**
     * Save a package using 5.6 signature (FSavePackageArgs).
     * FilePath is disk path ending with .uasset
     */
    static bool SavePackageToDisk(UPackage* Package, UObject* Asset, const FString& FilePath);
};
