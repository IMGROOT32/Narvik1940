// Copyright 2026. HyunJun. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponPistol.generated.h"

/**
 * 
 */
UCLASS()
class NARVIK1940_API AWeaponPistol : public AWeaponBase
{
	GENERATED_BODY()

public:
	AWeaponPistol();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float Damage = 30.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float HeadShotMultiplier = 2.0f;
	 
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float Range = 1500.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float FireRate = 0.3f;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bCanFire = true;

	FTimerHandle FireTimer;

	void ResetFire();

public:
	virtual void Fire() override;

	
};
