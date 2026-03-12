// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNarvik1940_init() {}
	NARVIK1940_API UFunction* Z_Construct_UDelegateFunction_Narvik1940_BulletCountUpdatedDelegate__DelegateSignature();
	NARVIK1940_API UFunction* Z_Construct_UDelegateFunction_Narvik1940_DamagedDelegate__DelegateSignature();
	NARVIK1940_API UFunction* Z_Construct_UDelegateFunction_Narvik1940_PawnDeathDelegate__DelegateSignature();
	NARVIK1940_API UFunction* Z_Construct_UDelegateFunction_Narvik1940_SprintStateChangedDelegate__DelegateSignature();
	NARVIK1940_API UFunction* Z_Construct_UDelegateFunction_Narvik1940_UpdateSprintMeterDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Narvik1940;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Narvik1940()
	{
		if (!Z_Registration_Info_UPackage__Script_Narvik1940.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Narvik1940_BulletCountUpdatedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Narvik1940_DamagedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Narvik1940_PawnDeathDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Narvik1940_SprintStateChangedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Narvik1940_UpdateSprintMeterDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Narvik1940",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x170C8422,
				0x42024F79,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Narvik1940.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Narvik1940.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Narvik1940(Z_Construct_UPackage__Script_Narvik1940, TEXT("/Script/Narvik1940"), Z_Registration_Info_UPackage__Script_Narvik1940, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x170C8422, 0x42024F79));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
