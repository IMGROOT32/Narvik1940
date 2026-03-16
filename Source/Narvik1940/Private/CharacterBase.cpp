//Copyright 2026. HyunJun.All rights reserved.

#include "CharacterBase.h"
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

void ACharacterBase::TakeDamageByPart(FName BodyPart, float Damage)
{
	
}

void ACharacterBase::OnDead()
{

}