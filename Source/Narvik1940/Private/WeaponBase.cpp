//Copyright 2026. HyunJun.All rights reserved.
#include "WeaponBase.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MagazineSize;
	
}

void AWeaponBase::OnEquip()
{
	WeaponMesh->SetVisibility(true);

	//임시
	UE_LOG(LogTemp, Warning, TEXT("OnEquip Called, Visibility : true"));
}

void AWeaponBase::OnUnEquip()
{
	WeaponMesh->SetVisibility(false);
}

void AWeaponBase::Fire()
{

}

void AWeaponBase::Reload()
{

}
