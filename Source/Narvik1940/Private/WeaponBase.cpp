//Copyright 2026. HyunJun.All rights reserved.
#include "WeaponBase.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	WeaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponSkeletalMesh"));
	RootComponent = WeaponSkeletalMesh;

	WeaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponStaticMesh"));
	WeaponStaticMesh->SetupAttachment(RootComponent);
	WeaponStaticMesh->SetVisibility(false);

}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MagazineSize;
}

void AWeaponBase::OnEquip()
{
	WeaponSkeletalMesh->SetVisibility(true);
	WeaponStaticMesh->SetVisibility(true);
}

void AWeaponBase::OnUnEquip()
{
	WeaponSkeletalMesh->SetVisibility(false);
	WeaponStaticMesh->SetVisibility(false);
}

void AWeaponBase::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("WeaponBase Fire Called"));
}

void AWeaponBase::Reload()
{
}