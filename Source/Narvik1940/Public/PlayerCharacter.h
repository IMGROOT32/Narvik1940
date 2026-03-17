// Copyright 2026. HyunJun. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "WeaponBase.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UInputAction;

UCLASS()
class NARVIK1940_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FPSCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	class USkeletalMeshComponent* ArmsMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Look;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Jump;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Sprint;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Crouch;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float LookSensitivity = 20.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Fire;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsSprinting = false;

	UPROPERTY(BlueprintReadOnly, Category = "Anim")
	float MovementSpeed = 0.0f;

	UPROPERTY(BluePrintReadOnly, Category = "Anim")
	bool bIsInAir = false;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	AWeaponBase* PrimaryWeapon;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	AWeaponBase* SecondaryWeapon;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	AWeaponBase* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_PrimaryWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_SecondaryWeapon;

	void CameraSet();
	void MeshSet();
	void MovementSet();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void SprintStart(const FInputActionValue& Value);
	void SprintEnd(const FInputActionValue& Value);
	void CrouchStart(const FInputActionValue& Value);
	void CrouchEnd(const FInputActionValue& Value);

	void EquipWeapon(AWeaponBase* Weapon);
	void SwitchToPrimary(const FInputActionValue& Value);
	void SwitchToSecondary(const FInputActionValue& Value);

	void FireStart(const FInputActionValue& Value);
	void FireEnd(const FInputActionValue& Value);

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:	
	virtual void Tick(float DeltaTime) override;

};
