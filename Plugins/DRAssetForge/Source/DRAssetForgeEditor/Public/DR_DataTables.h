#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DR_CommonTypes.h"
#include "DR_DataTables.generated.h"

USTRUCT(BlueprintType)
struct FDR_ItemRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName ItemId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") EDR_ItemType ItemType = EDR_ItemType::Misc;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") EDR_ItemRarity Rarity = EDR_ItemRarity::Common;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Requirements") int32 RequiredLevel = 1;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") FDR_StatBlock Grants;
};

USTRUCT(BlueprintType)
struct FDR_WeaponRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName ItemId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat") EDR_WeaponDamageType DamageType = EDR_WeaponDamageType::Physical;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0")) int32 MinDamage = 5;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0")) int32 MaxDamage = 10;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.05")) float AttackRate = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") FDR_StatBlock Grants;
};

USTRUCT(BlueprintType)
struct FDR_ArmorRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName ItemId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor") int32 Armor = 10;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor") int32 MagicResist = 0;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor") EDR_ArmorSlot Slot = EDR_ArmorSlot::Chest;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") FDR_StatBlock Grants;
};

USTRUCT(BlueprintType)
struct FDR_MonsterRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName MonsterId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") int32 Level = 1;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") FDR_StatBlock Stats;
};
