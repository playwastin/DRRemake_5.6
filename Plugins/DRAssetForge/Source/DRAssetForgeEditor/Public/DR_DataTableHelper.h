// DR_DataTableHelper.h (UE 5.6.1)
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

/**
 * Thin helpers around UDataTable that match UE5.6 signatures.
 * NOTE: ForeachRow passes 'const RowType&' — not a pointer.
 */
namespace DR_DataTableHelper
{
    template<typename RowType>
    inline void ForEachRow(const UDataTable* Table, TFunctionRef<void(const FName& RowName, const RowType& Row)> Visitor)
    {
        if (!Table) return;
        Table->ForeachRow<RowType>(TEXT("DR_DataTableHelper"), Visitor); // :contentReference[oaicite:11]{index=11}
    }

    template<typename RowType>
    inline bool GetAllRows(const UDataTable* Table, TArray<const RowType*>& OutRows)
    {
        if (!Table) return false;

        TArray<RowType*> TempRows;
        Table->GetAllRows<RowType>(TEXT("DR_DataTableHelper"), TempRows); // gives TArray<RowType*>
        OutRows.Reset();
        OutRows.Reserve(TempRows.Num());
        for (RowType* R : TempRows)
        {
            OutRows.Add(R);
        }
        return true;
    }
}
