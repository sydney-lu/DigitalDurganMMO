// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Player/DDMMOCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDDMMOCharacter() {}
// Cross Module References
	DDMMO_API UEnum* Z_Construct_UEnum_DDMMO_PlayerCharacterState();
	UPackage* Z_Construct_UPackage__Script_DDMMO();
	DDMMO_API UClass* Z_Construct_UClass_ADDMMOCharacter_NoRegister();
	DDMMO_API UClass* Z_Construct_UClass_ADDMMOCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	DDMMO_API UClass* Z_Construct_UClass_ABaseProjectile_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	static UEnum* PlayerCharacterState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DDMMO_PlayerCharacterState, Z_Construct_UPackage__Script_DDMMO(), TEXT("PlayerCharacterState"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_PlayerCharacterState(PlayerCharacterState_StaticEnum, TEXT("/Script/DDMMO"), TEXT("PlayerCharacterState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DDMMO_PlayerCharacterState_CRC() { return 2519231667U; }
	UEnum* Z_Construct_UEnum_DDMMO_PlayerCharacterState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DDMMO();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("PlayerCharacterState"), 0, Get_Z_Construct_UEnum_DDMMO_PlayerCharacterState_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "PlayerCharacterState::IDLE", (int64)PlayerCharacterState::IDLE },
				{ "PlayerCharacterState::ATTACKING", (int64)PlayerCharacterState::ATTACKING },
				{ "PlayerCharacterState::RESTING", (int64)PlayerCharacterState::RESTING },
				{ "PlayerCharacterState::CASTING", (int64)PlayerCharacterState::CASTING },
				{ "PlayerCharacterState::TRAVERSAL_WALK", (int64)PlayerCharacterState::TRAVERSAL_WALK },
				{ "PlayerCharacterState::TRAVERSAL_RUN", (int64)PlayerCharacterState::TRAVERSAL_RUN },
				{ "PlayerCharacterState::TRAVERSAL_FLY", (int64)PlayerCharacterState::TRAVERSAL_FLY },
				{ "PlayerCharacterState::TRAVERSAL_SWIM", (int64)PlayerCharacterState::TRAVERSAL_SWIM },
				{ "PlayerCharacterState::DISABLED", (int64)PlayerCharacterState::DISABLED },
				{ "PlayerCharacterState::HARDCROWDCONTROL", (int64)PlayerCharacterState::HARDCROWDCONTROL },
				{ "PlayerCharacterState::SOFTCROWDCONTROL", (int64)PlayerCharacterState::SOFTCROWDCONTROL },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ATTACKING.DisplayName", "Attacking" },
				{ "BlueprintType", "true" },
				{ "CASTING.DisplayName", "Casting" },
				{ "DISABLED.DisplayName", "Disabled" },
				{ "HARDCROWDCONTROL.DisplayName", "HardCrowdControl" },
				{ "IDLE.DisplayName", "Idle" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
				{ "RESTING.DisplayName", "Resting" },
				{ "SOFTCROWDCONTROL.DisplayName", "SoftCrowdControl" },
				{ "ToolTip", "Player can only be in one state at a time" },
				{ "TRAVERSAL_FLY.DisplayName", "TraversalFly" },
				{ "TRAVERSAL_RUN.DisplayName", "TraversalRun" },
				{ "TRAVERSAL_SWIM.DisplayName", "TraversalSwim" },
				{ "TRAVERSAL_WALK.DisplayName", "TraversalWalk" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DDMMO,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"PlayerCharacterState",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"PlayerCharacterState",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void ADDMMOCharacter::StaticRegisterNativesADDMMOCharacter()
	{
	}
	UClass* Z_Construct_UClass_ADDMMOCharacter_NoRegister()
	{
		return ADDMMOCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ADDMMOCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_DDMMO,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Player/DDMMOCharacter.h" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
				{ "Category", "Projectile" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProjectileClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000010001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, ProjectileClass), Z_Construct_UClass_ABaseProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ProjectileClass_MetaData, ARRAY_COUNT(NewProp_ProjectileClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleOffset_MetaData[] = {
				{ "Category", "Weapon" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MuzzleOffset = { UE4CodeGen_Private::EPropertyClass::Struct, "MuzzleOffset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000005, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, MuzzleOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_MuzzleOffset_MetaData, ARRAY_COUNT(NewProp_MuzzleOffset_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoomOut_MAX_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZoomOut_MAX = { UE4CodeGen_Private::EPropertyClass::Float, "ZoomOut_MAX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, ZoomOut_MAX), METADATA_PARAMS(NewProp_ZoomOut_MAX_MetaData, ARRAY_COUNT(NewProp_ZoomOut_MAX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoomIn_MAX_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZoomIn_MAX = { UE4CodeGen_Private::EPropertyClass::Float, "ZoomIn_MAX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, ZoomIn_MAX), METADATA_PARAMS(NewProp_ZoomIn_MAX_MetaData, ARRAY_COUNT(NewProp_ZoomIn_MAX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Zoom_Power_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Zoom_Power = { UE4CodeGen_Private::EPropertyClass::Float, "Zoom_Power", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Zoom_Power), METADATA_PARAMS(NewProp_Zoom_Power_MetaData, ARRAY_COUNT(NewProp_Zoom_Power_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BasicAttackRange_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BasicAttackRange = { UE4CodeGen_Private::EPropertyClass::Float, "BasicAttackRange", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, BasicAttackRange), METADATA_PARAMS(NewProp_BasicAttackRange_MetaData, ARRAY_COUNT(NewProp_BasicAttackRange_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BasicAttackSpeed_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BasicAttackSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "BasicAttackSpeed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, BasicAttackSpeed), METADATA_PARAMS(NewProp_BasicAttackSpeed_MetaData, ARRAY_COUNT(NewProp_BasicAttackSpeed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Stamina_CUR_MetaData[] = {
				{ "Category", "Character" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Stamina_CUR = { UE4CodeGen_Private::EPropertyClass::Float, "Stamina_CUR", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Stamina_CUR), METADATA_PARAMS(NewProp_Stamina_CUR_MetaData, ARRAY_COUNT(NewProp_Stamina_CUR_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Stamina_MAX_MetaData[] = {
				{ "Category", "Character" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Stamina_MAX = { UE4CodeGen_Private::EPropertyClass::Float, "Stamina_MAX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Stamina_MAX), METADATA_PARAMS(NewProp_Stamina_MAX_MetaData, ARRAY_COUNT(NewProp_Stamina_MAX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mana_CUR_MetaData[] = {
				{ "Category", "Character" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Mana_CUR = { UE4CodeGen_Private::EPropertyClass::Float, "Mana_CUR", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Mana_CUR), METADATA_PARAMS(NewProp_Mana_CUR_MetaData, ARRAY_COUNT(NewProp_Mana_CUR_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mana_MAX_MetaData[] = {
				{ "Category", "Character" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Mana_MAX = { UE4CodeGen_Private::EPropertyClass::Float, "Mana_MAX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Mana_MAX), METADATA_PARAMS(NewProp_Mana_MAX_MetaData, ARRAY_COUNT(NewProp_Mana_MAX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_CUR_MetaData[] = {
				{ "Category", "Character" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health_CUR = { UE4CodeGen_Private::EPropertyClass::Float, "Health_CUR", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Health_CUR), METADATA_PARAMS(NewProp_Health_CUR_MetaData, ARRAY_COUNT(NewProp_Health_CUR_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MAX_MetaData[] = {
				{ "Category", "Character" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health_MAX = { UE4CodeGen_Private::EPropertyClass::Float, "Health_MAX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Health_MAX), METADATA_PARAMS(NewProp_Health_MAX_MetaData, ARRAY_COUNT(NewProp_Health_MAX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[] = {
				{ "Category", "Camera" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseLookUpRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, BaseLookUpRate), METADATA_PARAMS(NewProp_BaseLookUpRate_MetaData, ARRAY_COUNT(NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[] = {
				{ "Category", "Camera" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseTurnRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, BaseTurnRate), METADATA_PARAMS(NewProp_BaseTurnRate_MetaData, ARRAY_COUNT(NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
				{ "ToolTip", "UPROPERTY(EditAnywhere)\nclass USphereComponent* MeleeCollider;" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CurrentState = { UE4CodeGen_Private::EPropertyClass::Enum, "CurrentState", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, CurrentState), Z_Construct_UEnum_DDMMO_PlayerCharacterState, METADATA_PARAMS(NewProp_CurrentState_MetaData, ARRAY_COUNT(NewProp_CurrentState_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera = { UE4CodeGen_Private::EPropertyClass::Object, "FollowCamera", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_FollowCamera_MetaData, ARRAY_COUNT(NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_CameraBoom_MetaData, ARRAY_COUNT(NewProp_CameraBoom_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MuzzleOffset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoomOut_MAX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoomIn_MAX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Zoom_Power,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BasicAttackRange,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BasicAttackSpeed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Stamina_CUR,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Stamina_MAX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Mana_CUR,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Mana_MAX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Health_CUR,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Health_MAX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseLookUpRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseTurnRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentState,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentState_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FollowCamera,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CameraBoom,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ADDMMOCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ADDMMOCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADDMMOCharacter, 487230117);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADDMMOCharacter(Z_Construct_UClass_ADDMMOCharacter, &ADDMMOCharacter::StaticClass, TEXT("/Script/DDMMO"), TEXT("ADDMMOCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADDMMOCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
