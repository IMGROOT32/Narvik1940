// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Narvik1940GameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeNarvik1940GameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
NARVIK1940_API UClass* Z_Construct_UClass_ANarvik1940GameMode();
NARVIK1940_API UClass* Z_Construct_UClass_ANarvik1940GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Narvik1940();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANarvik1940GameMode ******************************************************
void ANarvik1940GameMode::StaticRegisterNativesANarvik1940GameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ANarvik1940GameMode;
UClass* ANarvik1940GameMode::GetPrivateStaticClass()
{
	using TClass = ANarvik1940GameMode;
	if (!Z_Registration_Info_UClass_ANarvik1940GameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("Narvik1940GameMode"),
			Z_Registration_Info_UClass_ANarvik1940GameMode.InnerSingleton,
			StaticRegisterNativesANarvik1940GameMode,
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
	return Z_Registration_Info_UClass_ANarvik1940GameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ANarvik1940GameMode_NoRegister()
{
	return ANarvik1940GameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ANarvik1940GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Narvik1940GameMode.h" },
		{ "ModuleRelativePath", "Narvik1940GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANarvik1940GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ANarvik1940GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Narvik1940,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANarvik1940GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANarvik1940GameMode_Statics::ClassParams = {
	&ANarvik1940GameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANarvik1940GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ANarvik1940GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANarvik1940GameMode()
{
	if (!Z_Registration_Info_UClass_ANarvik1940GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANarvik1940GameMode.OuterSingleton, Z_Construct_UClass_ANarvik1940GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANarvik1940GameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANarvik1940GameMode);
ANarvik1940GameMode::~ANarvik1940GameMode() {}
// ********** End Class ANarvik1940GameMode ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940GameMode_h__Script_Narvik1940_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANarvik1940GameMode, ANarvik1940GameMode::StaticClass, TEXT("ANarvik1940GameMode"), &Z_Registration_Info_UClass_ANarvik1940GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANarvik1940GameMode), 1772019286U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940GameMode_h__Script_Narvik1940_3106858467(TEXT("/Script/Narvik1940"),
	Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940GameMode_h__Script_Narvik1940_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_HW_Narvik1940_Narvik1940_Source_Narvik1940_Narvik1940GameMode_h__Script_Narvik1940_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
