// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Narvik1940CameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeNarvik1940CameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
NARVIK1940_API UClass* Z_Construct_UClass_ANarvik1940CameraManager();
NARVIK1940_API UClass* Z_Construct_UClass_ANarvik1940CameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_Narvik1940();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANarvik1940CameraManager *************************************************
void ANarvik1940CameraManager::StaticRegisterNativesANarvik1940CameraManager()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ANarvik1940CameraManager;
UClass* ANarvik1940CameraManager::GetPrivateStaticClass()
{
	using TClass = ANarvik1940CameraManager;
	if (!Z_Registration_Info_UClass_ANarvik1940CameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("Narvik1940CameraManager"),
			Z_Registration_Info_UClass_ANarvik1940CameraManager.InnerSingleton,
			StaticRegisterNativesANarvik1940CameraManager,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ANarvik1940CameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_ANarvik1940CameraManager_NoRegister()
{
	return ANarvik1940CameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ANarvik1940CameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "Narvik1940CameraManager.h" },
		{ "ModuleRelativePath", "Narvik1940CameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANarvik1940CameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ANarvik1940CameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_Narvik1940,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANarvik1940CameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANarvik1940CameraManager_Statics::ClassParams = {
	&ANarvik1940CameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANarvik1940CameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ANarvik1940CameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANarvik1940CameraManager()
{
	if (!Z_Registration_Info_UClass_ANarvik1940CameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANarvik1940CameraManager.OuterSingleton, Z_Construct_UClass_ANarvik1940CameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANarvik1940CameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANarvik1940CameraManager);
ANarvik1940CameraManager::~ANarvik1940CameraManager() {}
// ********** End Class ANarvik1940CameraManager ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940CameraManager_h__Script_Narvik1940_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANarvik1940CameraManager, ANarvik1940CameraManager::StaticClass, TEXT("ANarvik1940CameraManager"), &Z_Registration_Info_UClass_ANarvik1940CameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANarvik1940CameraManager), 1514083131U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940CameraManager_h__Script_Narvik1940_1173841362(TEXT("/Script/Narvik1940"),
	Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940CameraManager_h__Script_Narvik1940_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940CameraManager_h__Script_Narvik1940_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
