// Copyright 2026. HyunJun. All rights reserved.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	FPSCamera->SetupAttachment(GetMesh(), TEXT("head"));
	FPSCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
	FPSCamera->bUsePawnControlRotation = true;

	ArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ArmsMesh"));
	ArmsMesh->SetupAttachment(FPSCamera);
	ArmsMesh->bCastDynamicShadow = false;
	ArmsMesh->CastShadow = false;

	GetMesh()->SetOwnerNoSee(true);

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovementSpeed = GetVelocity().Size();
	bIsInAir = GetCharacterMovement()->IsFalling();

	FVector CurrentLocation = FPSCamera->GetRelativeLocation();
	FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetCameraLocation, DeltaTime,
		CrouchCameraSpeed);
	FPSCamera->SetRelativeLocation(NewLocation);
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
		AddControllerYawInput(-LookVector.X);
		AddControllerPitchInput(LookVector.Y);
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
	TargetCameraLocation = FVector(0.0f, 0.0f, 0.0f);
}

void APlayerCharacter::CrouchEnd(const FInputActionValue& Value)
{
	UnCrouch();
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	TargetCameraLocation = FVector(0.0f, 0.0f, 60.0f);
}

