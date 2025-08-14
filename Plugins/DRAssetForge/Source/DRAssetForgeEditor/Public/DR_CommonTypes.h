#pragma once

#include "CoreMinimal.h"
#include "DR_CommonTypes.generated.h"

UENUM(BlueprintType)
enum class EDR_ItemRarity : uint8
{
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

UENUM(BlueprintType)
enum class EDR_ItemType : uint8
{
    Consumable,
    Material,
    Weapon,
    Armor,
    Quest,
    Misc
};

UENUM(BlueprintType)
enum class EDR_WeaponDamageType : uint8
{
    Physical,
    Fire,
    Ice,
    Lightning,
    Poison,
    Holy,
    Shadow
};

UENUM(BlueprintType)
enum class EDR_ArmorSlot : uint8
{
    Head,
    Chest,
    Legs,
    Hands,
    Feet,
    Cape,
    Accessory
};

USTRUCT(BlueprintType)
struct FDR_StatBlock
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") int32 MaxHP = 100;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") int32 MaxMP = 50;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") int32 Attack = 10;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") int32 Defense = 5;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") int32 MagicResist = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") float MoveSpeed = 600.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") float AttackSpeed = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") float CritChance = 0.05f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats") float CritDamage = 1.5f;
};
