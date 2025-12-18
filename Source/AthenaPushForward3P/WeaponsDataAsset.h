// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponData.h"
#include "Engine/DataAsset.h"
#include "WeaponsDataAsset.generated.h"


UCLASS(BlueprintType)
class ATHENAPUSHFORWARD3P_API UWeaponsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	/** Contains weapon-specific configuration, sockets, and animation profiles. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (ShowOnlyInnerProperties))
	FWeaponData WeaponData;
};