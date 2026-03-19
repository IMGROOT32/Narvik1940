// Copyright 2026. HyunJun. All rights reserved.


#include "PlayerCharacter.h"
#include "WeaponSMG.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraSet();
	MeshSet();
	MovementSet();
}

void APlayerCharacter::CameraSet()
{
	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	FPSCamera->SetupAttachment(GetMesh(), TEXT("headSocket"));
	FPSCamera->bUsePawnControlRotation = true;
}

void APlayerCharacter::MeshSet()
{
	ArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmsMesh"));
	ArmsMesh->SetupAttachment(FPSCamera);
	ArmsMesh->bCastDynamicShadow = false;
	ArmsMesh->CastShadow = false;
	GetMesh()->SetOwnerNoSee(false);
}

void APlayerCharacter::MovementSet()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	//임시
	if (SecondaryWeaponClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("WeaponClass Found"));
		FActorSpawnParameters Params;
		Params.Owner = this;
		Params.Instigator = this;
		SecondaryWeapon = GetWorld()->SpawnActor<AWeaponBase>(SecondaryWeaponClass, Params);
		if (SecondaryWeapon)
		{
			UE_LOG(LogTemp, Warning, TEXT("Weapon Spawned"));
			EquipWeapon(SecondaryWeapon);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WeaponClass NULL"));
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovementSpeed = GetVelocity().Size();
	bIsInAir = GetCharacterMovement()->IsFalling();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &APlayerCharacter::Jump);
		EIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &APlayerCharacter::StopJumping);
		EIC->BindAction(IA_Sprint, ETriggerEvent::Triggered, this, &APlayerCharacter::SprintStart);
		EIC->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &APlayerCharacter::SprintEnd);
		EIC->BindAction(IA_Crouch, ETriggerEvent::Triggered, this, &APlayerCharacter::CrouchStart);
		EIC->BindAction(IA_Crouch, ETriggerEvent::Completed, this, &APlayerCharacter::CrouchEnd);
		EIC->BindAction(IA_PrimaryWeapon, ETriggerEvent::Triggered, this, &APlayerCharacter::SwitchToPrimary);
		EIC->BindAction(IA_SecondaryWeapon, ETriggerEvent::Triggered, this, &APlayerCharacter::SwitchToSecondary);
		EIC->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &APlayerCharacter::FireStart);
		EIC->BindAction(IA_Fire, ETriggerEvent::Completed, this, &APlayerCharacter::FireEnd);

	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDir, MovementVector.Y);
		AddMovementInput(RightDir, MovementVector.X);
	}
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();

	if (Controller)
	{
		float DeltaTime = GetWorld()->GetDeltaSeconds();
		AddControllerYawInput(-LookVector.X * DeltaTime * LookSensitivity);
		AddControllerPitchInput(LookVector.Y * DeltaTime * LookSensitivity);
	}
}

void APlayerCharacter::SprintStart(const FInputActionValue& Value)
{
	bIsSprinting = true;
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void APlayerCharacter::SprintEnd(const FInputActionValue& Value)
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::CrouchStart(const FInputActionValue& Value)
{
	Crouch();
	GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
}

void APlayerCharacter::CrouchEnd(const FInputActionValue& Value)
{
	UnCrouch();
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::EquipWeapon(AWeaponBase* Weapon)
{
	if (!Weapon) return;

	if (CurrentWeapon)
	{
		CurrentWeapon->OnUnEquip();
	}

	CurrentWeapon = Weapon;
	CurrentWeapon->OnEquip();

	FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, true);
	bool bAttached = CurrentWeapon->AttachToComponent(GetMesh(), Rules, TEXT("hand_r_socket")); //임시 ArmMesh-> GetMesh
}

void APlayerCharacter::SwitchToPrimary(const FInputActionValue& Value)
{
	if (PrimaryWeapon && CurrentWeapon != PrimaryWeapon)
	{
		EquipWeapon(PrimaryWeapon);
	}
}

void APlayerCharacter::SwitchToSecondary(const FInputActionValue& Value)
{
	if (SecondaryWeapon && CurrentWeapon != SecondaryWeapon)
	{
		EquipWeapon(SecondaryWeapon);
	}
}

void APlayerCharacter::FireStart(const FInputActionValue& Value)
{
	if (CurrentWeapon)
	{
		bIsFiring = true;
		CurrentWeapon->Fire();
	}
}

void APlayerCharacter::FireEnd(const FInputActionValue& Value)
{

}