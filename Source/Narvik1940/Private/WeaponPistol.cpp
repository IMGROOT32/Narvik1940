// Copyright 2026. HyunJun. All rights reserved.


#include "WeaponPistol.h"
#include "PlayerCharacter.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"

AWeaponPistol::AWeaponPistol()
{
	WeaponType = EWeaponType::Pistol;
	WeaponSlot = EWeaponSlot::Secondary;
	MagazineSize = 8;
    ReserveAmmo = 24;
	bRequiresBothArms = false;
    ReloadTime = 1.2f;
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

        if (bShowDebugTrace)
        {
            DrawDebugLine(GetWorld(), CameraLocation, HitResult.ImpactPoint,
                FColor::Blue, false, 2.0f, 0, 1.0f);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No Hit"));

        if (bShowDebugTrace)
        {
            DrawDebugLine(GetWorld(), CameraLocation, TraceEnd,
                FColor::Red, false, 2.0f, 0, 1.0f);
        }

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

