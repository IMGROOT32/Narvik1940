//Copyright 2026. HyunJun.All rights reserved.

#include "CharacterBase.h"

#include "Algo/Contains.h"
#include "Chaos/PBDRigidsSOAs.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterBase::TakeDamageByPart(EBodyPart BodyPart, float Damage)
{
	if (!BodyPartHP.Contains(BodyPart)) return;

	float& HP = BodyPartHP[BodyPart];
	HP = FMath::Max(0.0f, HP - Damage);

	UE_LOG(LogTemp, Warning, TEXT("BodyPart : %d, HP : %.1f"), (int32)BodyPart, HP);

	UpdateBodyPartStatus(BodyPart);

	if (BodyPart == EBodyPart::Head || BodyPart == EBodyPart::Chest)
	{
		if (HP <= 0.0f) OnDead();
	}
}

void ACharacterBase::UpdateBodyPartStatus(EBodyPart BodyPart)
{
	if (!BodyPartHP.Contains(BodyPart)) return;

	float HP = BodyPartHP[BodyPart];
	float MaxHP = 0.0f;

	switch (BodyPart)
	{
	case EBodyPart::Head: MaxHP = 35.0f;
		break;
	case EBodyPart::Chest: MaxHP = 100.0f;
		break;
	case EBodyPart::LeftArm: MaxHP = 60.0f;
		break;
	case EBodyPart::RightArm: MaxHP = 60.0f;
		break;
	case EBodyPart::LeftLeg: MaxHP = 70.0f;
		break;
	case EBodyPart::RightLeg: MaxHP = 70.0f;
		break;
	}
	
	EBodyStatus NewStatus;
	
	if (HP<= 0.0f)
	{
		NewStatus = EBodyStatus::Disabled;
	}
	else if (HP / MaxHP <= InjuredThreshold)
	{
		NewStatus = EBodyStatus::Injured;
	}
	else
	{
			NewStatus = EBodyStatus::Normal;
	}
		
	BodyPartStatus[BodyPart] = NewStatus;
	
	ApplyInjuryPenalty(BodyPart, NewStatus);
}

void ACharacterBase::ApplyInjuryPenalty(EBodyPart BodyPart, EBodyStatus Status)
{
	switch (BodyPart)
	{
	case EBodyPart::LeftLeg:
	case EBodyPart::RightLeg:
		if (Status == EBodyStatus::Injured)
		{
			GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		}
		else if (Status == EBodyStatus::Disabled)
		{
			GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
			
			if (BodyPartStatus[EBodyPart::LeftLeg] == EBodyStatus::Disabled &&
				BodyPartStatus[EBodyPart::RightLeg] == EBodyStatus::Disabled)
			{
				OnDead();
			}
		}
		break;
		
	default:
		break;
	}
}

void ACharacterBase::OnDead()
{
	
}

EBodyStatus ACharacterBase::GetBodyPartStatus(EBodyPart BodyPart) const
{
	if (BodyPartStatus.Contains(BodyPart))
	{
		return BodyPartStatus[BodyPart];
	}
	return EBodyStatus::Normal;
}

float ACharacterBase::GetBodyPartHP(EBodyPart BodyPart) const
{
	if (BodyPartHP.Contains(BodyPart))
	{
		return BodyPartHP[BodyPart];
	}
	return 0.0f;
}