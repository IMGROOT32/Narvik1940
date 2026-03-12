// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Variant_Shooter/AI/ShooterNPC.h"

#ifdef NARVIK1940_ShooterNPC_generated_h
#error "ShooterNPC.generated.h already included, missing '#pragma once' in ShooterNPC.h"
#endif
#define NARVIK1940_ShooterNPC_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Delegate FPawnDeathDelegate ****************************************************
#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_10_DELEGATE \
NARVIK1940_API void FPawnDeathDelegate_DelegateWrapper(const FMulticastScriptDelegate& PawnDeathDelegate);


// ********** End Delegate FPawnDeathDelegate ******************************************************

// ********** Begin Class AShooterNPC **************************************************************
NARVIK1940_API UClass* Z_Construct_UClass_AShooterNPC_NoRegister();

#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShooterNPC(); \
	friend struct Z_Construct_UClass_AShooterNPC_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend NARVIK1940_API UClass* Z_Construct_UClass_AShooterNPC_NoRegister(); \
public: \
	DECLARE_CLASS2(AShooterNPC, ANarvik1940Character, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Narvik1940"), Z_Construct_UClass_AShooterNPC_NoRegister) \
	DECLARE_SERIALIZER(AShooterNPC) \
	virtual UObject* _getUObject() const override { return const_cast<AShooterNPC*>(this); }


#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShooterNPC(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AShooterNPC(AShooterNPC&&) = delete; \
	AShooterNPC(const AShooterNPC&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooterNPC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooterNPC); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AShooterNPC) \
	NO_API virtual ~AShooterNPC();


#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_19_PROLOG
#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_22_INCLASS_NO_PURE_DECLS \
	FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AShooterNPC;

// ********** End Class AShooterNPC ****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Variant_Shooter_AI_ShooterNPC_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
