// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMontage.h"
#include "WeaponData.generated.h"
/**
 * 
 */


UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None	UMETA(DisplayName = "None"),
	Pistol	UMETA(DisplayName = "Pistol"),
	Rifle	UMETA(DisplayName = "Rifle"),
	Sniper	UMETA(DisplayName = "Sniper"),
	LMG		UMETA(DisplayName = "Light Machine Gun"),
};


USTRUCT(BlueprintType)
struct FWeaponAnimProfile
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Animations", meta = (Tooltip = "Animation montage played when the weapon is fired."))
	UAnimSequence* FireAnimation = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Animations", meta = (Tooltip = "Animation montage played when the weapon is reloaded."))
	UAnimSequence* ReloadAnimation = nullptr;
};

USTRUCT(BlueprintType)
struct FAmmunitionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentAmmo = 30;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0"))
	int32 MaxAmmo = 90;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="1"))
	int32 ClipAmmo = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmmoCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsReloading = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReloadTime = 2.0f;
};

USTRUCT(BlueprintType)
struct FPlayerAnimProfile
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Animations", meta = (Tooltip = "Player firing animation montage."))
	UAnimMontage* FireMontage_EquipShield = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Animations", meta = (Tooltip = "Player firing animation montage."))
	UAnimMontage* FireMontage_DeployedShield = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Animations", meta = (Tooltip = "Player reloading animation montage."))
	UAnimMontage* ReloadMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Animations", meta = (Tooltip = "Player equip animation montage."))
	UAnimMontage* EquipMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Animations", meta = (Tooltip = "Player unequip animation montage."))
	UAnimMontage* UnequipMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Animations", meta = (Tooltip = "Player unequip animation montage."))
	UAnimMontage* AimMontage = nullptr;
};

USTRUCT(BlueprintType)
struct FAIAnimProfile
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Animations", meta = (Tooltip = "AI firing animation montage."))
	UAnimMontage* AIFireMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Animations", meta = (Tooltip = "AI reloading animation montage."))
	UAnimMontage* AIReloadMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Animations", meta = (Tooltip = "AI unequip animation montage."))
	UAnimMontage* AIAimMontage = nullptr;
};


USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|General")
	EWeaponType WeaponType = EWeaponType::Pistol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|General", meta = (Tooltip = "Reference to the weapon actor class"))
	TSubclassOf<AActor> Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats", meta = (ClampMin = "0.0", Tooltip = "Maximum effective range of the weapon in Unreal units (1 UU = 1 cm)."))
	float BulletRange = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats", meta = (ClampMin = "0.0", Tooltip = "Base damage applied to targets hit by this weapon."))
	float WeaponDamage = 25.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ammunition")
	FAmmunitionInfo AmmunitionInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Sockets", meta = (Tooltip = "Socket name where the weapon attaches when equipped."))
	FName EquippedSocket = FName("WeaponSocket");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Sockets", meta = (Tooltip = "Socket name where the weapon attaches when not equipped."))
	FName RestSocket = FName("SpineSocket");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Sockets", meta = (Tooltip = "Socket name representing the muzzle or barrel end where bullets are fired from."))
	FName MuzzleSocket = FName("MuzzleSocket");
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Animations")
	FWeaponAnimProfile WeaponAnimations;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	FPlayerAnimProfile PlayerAnimations;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FAIAnimProfile AIAnimations;
	
};


USTRUCT(BlueprintType)
struct FEquippedWeaponInfo
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Instance")
	AActor* WeaponActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Data")
	FWeaponData WeaponInfo;
};