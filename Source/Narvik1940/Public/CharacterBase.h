// Copyright 2026. HyunJun. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UInputAction;
UCLASS()
class NARVIK1940_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeed = 700.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float CrouchSpeed = 300.f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float HeadHP = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float ChestHP = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float LeftArmHP = 40.0f;
	
	UPROPERTY(EditAnywhere, Category = "Health")
	float RightArmHP = 40.0f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float LeftLegHP = 30.0f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float RightLegHP = 30.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Status")
	bool bLeftArmDisabled = false;

	UPROPERTY(BlueprintReadOnly, Category = "Status")
	bool bRightArmDisabled = false;

	UPROPERTY(BlueprintReadOnly, Category = "Status")
	bool bLeftLegDisabled = false;

	UPROPERTY(BlueprintReadOnly, Category = "Status")
	bool bRightLegDisabled = false;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void TakeDamageByPart(FName BodyPart, float Damage);

	virtual void OnDead();
};
