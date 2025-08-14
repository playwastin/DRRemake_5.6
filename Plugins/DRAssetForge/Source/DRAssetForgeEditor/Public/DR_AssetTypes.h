// DR_AssetTypes.h (UE 5.6.1) — DataAsset types only
#pragma once

#include "CoreMinimal.h"
#include "Engine/PrimaryDataAsset.h"    // <- correct path in UE 5.6
#include "DR_CommonTypes.h"             // your enums/structs used by assets
#include "DR_AssetTypes.generated.h"

// Forward declarations
class UTexture2D;
class UStaticMesh;
class USkeletalMesh;
class UNiagaraSystem;
class USoundBase;

/** Base item DataAsset */
UCLASS(BlueprintType)
class DRASSETFORGEEDITOR_API UDR_ItemAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName ItemId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") EDR_ItemType ItemType = EDR_ItemType::Misc;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") EDR_ItemRarity Rarity = EDR_ItemRarity::Common;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") int32 RequiredLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visual") TSoftObjectPtr<UTexture2D> Icon;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") FDR_StatBlock Grants;
};

/** Weapon DataAsset */
UCLASS(BlueprintType)
class DRASSETFORGEEDITOR_API UDR_WeaponAsset : public UDR_ItemAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visual") TSoftObjectPtr<USkeletalMesh> WeaponMesh;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat") EDR_WeaponDamageType DamageType = EDR_WeaponDamageType::Physical;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0")) int32 MinDamage = 5;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0")) int32 MaxDamage = 10;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.05")) float AttackRate = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VFX") TSoftObjectPtr<UNiagaraSystem> HitFX;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SFX") TSoftObjectPtr<USoundBase>    HitSFX;
};

/** Armor DataAsset */
UCLASS(BlueprintType)
class DRASSETFORGEEDITOR_API UDR_ArmorAsset : public UDR_ItemAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor") EDR_ArmorSlot Slot = EDR_ArmorSlot::Chest;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visual") TSoftObjectPtr<USkeletalMesh> ArmorMesh;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor") int32 Armor = 10;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Armor") int32 MagicResist = 0;
};

/** Monster DataAsset */
UCLASS(BlueprintType)
class DRASSETFORGEEDITOR_API UDR_MonsterAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName MonsterId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") int32 Level = 1;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats") FDR_StatBlock Stats;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visual") TSoftObjectPtr<USkeletalMesh> SkeletalMesh;
};

/** Mount DataAsset */
UCLASS(BlueprintType)
class DRASSETFORGEEDITOR_API UDR_MountAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FName MountId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visual") TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0")) float SpeedBonus   = 300.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0")) float Acceleration = 2048.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0")) float TurnRate     = 90.f;
};
