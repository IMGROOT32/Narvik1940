// Copyright 2026. HyunJun. All rights reserved.


#include "WeaponPistol.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"

AWeaponPistol::AWeaponPistol()
{
	WeaponType = EWeaponType::Pistol;
	WeaponSlot = EWeaponSlot::Secondary;
	MagazineSize = 8;
	bRequiresBothArms = false;
}

void AWeaponPistol::Fire()
{
	if (!bCanFire || CurrentAmmo <= 0) return;

	bCanFire = false;
	CurrentAmmo--;

	UE_LOG(LogTemp, Warning, TEXT("Pistol Fire! Ammo : %d"), CurrentAmmo);

	APlayerController* PC = Cast<APlayerController>(GetInstigatorController());
	if (!PC)
	{
		return;
	}

	FVector CameraLocation;
	FRotator CameraRotation;
	PC->GetPlayerViewPoint(CameraLocation, CameraRotation);

	FVector TraceEnd = CameraLocation + CameraRotation.Vector() * Range;

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, TraceEnd,
		ECC_Visibility, Params);

	if (bHit)
	{
		if (bHit)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Hit"));
		}

		GetWorldTimerManager().SetTimer(
			FireTimer, this, &AWeaponPistol::ResetFire, FireRate, false);
	}
}

void AWeaponPistol::ResetFire()
{
	bCanFire = true;
}


