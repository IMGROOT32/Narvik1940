// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Narvik1940Character.h"

#ifdef NARVIK1940_Narvik1940Character_generated_h
#error "Narvik1940Character.generated.h already included, missing '#pragma once' in Narvik1940Character.h"
#endif
#define NARVIK1940_Narvik1940Character_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ANarvik1940Character *****************************************************
#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoAim);


NARVIK1940_API UClass* Z_Construct_UClass_ANarvik1940Character_NoRegister();

#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANarvik1940Character(); \
	friend struct Z_Construct_UClass_ANarvik1940Character_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend NARVIK1940_API UClass* Z_Construct_UClass_ANarvik1940Character_NoRegister(); \
public: \
	DECLARE_CLASS2(ANarvik1940Character, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Narvik1940"), Z_Construct_UClass_ANarvik1940Character_NoRegister) \
	DECLARE_SERIALIZER(ANarvik1940Character)


#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ANarvik1940Character(ANarvik1940Character&&) = delete; \
	ANarvik1940Character(const ANarvik1940Character&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANarvik1940Character); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANarvik1940Character); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ANarvik1940Character) \
	NO_API virtual ~ANarvik1940Character();


#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_21_PROLOG
#define FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_INCLASS_NO_PURE_DECLS \
	FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ANarvik1940Character;

// ********** End Class ANarvik1940Character *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940Character_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
