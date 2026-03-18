// Copyright 2026. HyunJun. All rights reserved.


#include "WeaponPistol.h"
#include "PlayerCharacter.h"
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
    if (!bCanFire) return;

    if (CurrentAmmo <= 0)
    {
        APlayerCharacter* PC = Cast<APlayerCharacter>(GetOwner());
        if (PC) PC->bIsFiring = false;
        return;
    }

    bCanFire = false;
    CurrentAmmo--;

    GetWorldTimerManager().SetTimer(
        FireTimer, this, &AWeaponPistol::ResetFire, FireRate, false);

    APlayerController* PC = Cast<APlayerController>(GetInstigatorController());
    if (!PC)
    {
        UE_LOG(LogTemp, Warning, TEXT("PC NULL"));
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

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult, CameraLocation, TraceEnd, ECC_Visibility, Params);

    if (bHit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No Hit"));
    }
}

void AWeaponPistol::ResetFire()
{
	bCanFire = true;
	UE_LOG(LogTemp, Warning, TEXT("ResetFire Called"));
	APlayerCharacter* PC = Cast<APlayerCharacter>(GetOwner());
	if (PC)
	{
		PC->bIsFiring = false;
		UE_LOG(LogTemp, Warning, TEXT("bIsFiring set to false"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PC NULL in ResetFire"));
	}
}

