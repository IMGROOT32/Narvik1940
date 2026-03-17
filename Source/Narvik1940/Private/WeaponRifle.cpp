// Copyright 2026. HyunJun. All rights reserved.


#include "WeaponRifle.h"
#include "Engine/World.h"	

AWeaponRifle::AWeaponRifle()
{
	WeaponType = EWeaponType::Rifle;
	WeaponSlot = EWeaponSlot::Primary;
	MagazineSize = 5;
	bRequiresBothArms = true;
}

void AWeaponRifle::Fire()
{
	if (!bCanFire || CurrentAmmo <= 0) return;

	bCanFire = false;
	CurrentAmmo--;

	APlayerController* PC = Cast<APlayerController>(GetOwner()->GetInstigatorController());
	if (!PC) return;

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
		AActor* HitActor = HitResult.GetActor();
		if (HitActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit : %s"), *HitActor->GetName());
		}
	}
	GetWorldTimerManager().SetTimer(BoltActionTimer, this, &AWeaponRifle::ResetBoltAction,
		BoltActionTime, false);
}

void AWeaponRifle::ResetBoltAction()
{
	bCanFire = true;
}