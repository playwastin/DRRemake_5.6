// DR_AssetTypes.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/PrimaryDataAsset.h" // correct path in 5.x
#include "Engine/DataTable.h"
#include "DR_AssetTypes.generated.h"

// Row structs for your CSV/DataTable imports.
// Keep names unique (avoid collisions). Prefix with DR_ to be safe.

UENUM(BlueprintType)
enum class EDR_ItemType : uint8
{
    Weapon UMETA(DisplayName="Weapon"),
    Armor  UMETA(DisplayName="Armor"),
    Monster UMETA(DisplayName="Monster"),
    Mount  UMETA(DisplayName="Mount")
};

USTRUCT(BlueprintType)
struct FDR_ItemRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EDR_ItemType Type = EDR_ItemType::Weapon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Power = 0;
};

USTRUCT(BlueprintType)
struct FDR_WeaponRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MinDamage = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxDamage = 0;
};

USTRUCT(BlueprintType)
struct FDR_ArmorRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Defense = 0;
};

USTRUCT(BlueprintType)
struct FDR_MonsterRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level = 1;
};

// Example PrimaryDataAsset you might generate programmatically
UCLASS(BlueprintType)
class UDR_ItemCatalog : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TMap<FName, FDR_ItemRow> Items;
};
