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
	DDMMO_API UClass* Z_Construct_UClass_ADDMMOCharacter_NoRegister();
	DDMMO_API UClass* Z_Construct_UClass_ADDMMOCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_DDMMO();
	DDMMO_API UFunction* Z_Construct_UFunction_ADDMMOCharacter_AttemptToSendChatMessage();
	DDMMO_API UFunction* Z_Construct_UFunction_ADDMMOCharacter_OnRep_CurrentMessage();
	DDMMO_API UFunction* Z_Construct_UFunction_ADDMMOCharacter_ServerSendChatMessage();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	static FName NAME_ADDMMOCharacter_ServerSendChatMessage = FName(TEXT("ServerSendChatMessage"));
	void ADDMMOCharacter::ServerSendChatMessage(const FString& Message)
	{
		DDMMOCharacter_eventServerSendChatMessage_Parms Parms;
		Parms.Message=Message;
		ProcessEvent(FindFunctionChecked(NAME_ADDMMOCharacter_ServerSendChatMessage),&Parms);
	}
	void ADDMMOCharacter::StaticRegisterNativesADDMMOCharacter()
	{
		UClass* Class = ADDMMOCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AttemptToSendChatMessage", (Native)&ADDMMOCharacter::execAttemptToSendChatMessage },
			{ "OnRep_CurrentMessage", (Native)&ADDMMOCharacter::execOnRep_CurrentMessage },
			{ "ServerSendChatMessage", (Native)&ADDMMOCharacter::execServerSendChatMessage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ADDMMOCharacter_AttemptToSendChatMessage()
	{
		struct DDMMOCharacter_eventAttemptToSendChatMessage_Parms
		{
			FString Message;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(DDMMOCharacter_eventAttemptToSendChatMessage_Parms, Message), METADATA_PARAMS(NewProp_Message_MetaData, ARRAY_COUNT(NewProp_Message_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Message,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Chat/Messaging" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ADDMMOCharacter, "AttemptToSendChatMessage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(DDMMOCharacter_eventAttemptToSendChatMessage_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ADDMMOCharacter_OnRep_CurrentMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ADDMMOCharacter, "OnRep_CurrentMessage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ADDMMOCharacter_ServerSendChatMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(DDMMOCharacter_eventServerSendChatMessage_Parms, Message), METADATA_PARAMS(NewProp_Message_MetaData, ARRAY_COUNT(NewProp_Message_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Message,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
				{ "ToolTip", "Clears the current message, called automatically after 5 seconds after sending the message." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ADDMMOCharacter, "ServerSendChatMessage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80240CC1, sizeof(DDMMOCharacter_eventServerSendChatMessage_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
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
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ADDMMOCharacter_AttemptToSendChatMessage, "AttemptToSendChatMessage" }, // 4237290101
				{ &Z_Construct_UFunction_ADDMMOCharacter_OnRep_CurrentMessage, "OnRep_CurrentMessage" }, // 2653711532
				{ &Z_Construct_UFunction_ADDMMOCharacter_ServerSendChatMessage, "ServerSendChatMessage" }, // 3863712617
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Player/DDMMOCharacter.h" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentMessage_MetaData[] = {
				{ "Category", "Chat/Messaging" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
				{ "ToolTip", "Chat System" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_CurrentMessage = { UE4CodeGen_Private::EPropertyClass::Str, "CurrentMessage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080100022025, 1, "OnRep_CurrentMessage", STRUCT_OFFSET(ADDMMOCharacter, CurrentMessage), METADATA_PARAMS(NewProp_CurrentMessage_MetaData, ARRAY_COUNT(NewProp_CurrentMessage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoomOut_Max_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZoomOut_Max = { UE4CodeGen_Private::EPropertyClass::Float, "ZoomOut_Max", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, ZoomOut_Max), METADATA_PARAMS(NewProp_ZoomOut_Max_MetaData, ARRAY_COUNT(NewProp_ZoomOut_Max_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoomIn_Max_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZoomIn_Max = { UE4CodeGen_Private::EPropertyClass::Float, "ZoomIn_Max", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, ZoomIn_Max), METADATA_PARAMS(NewProp_ZoomIn_Max_MetaData, ARRAY_COUNT(NewProp_ZoomIn_Max_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Zoom_Power_MetaData[] = {
				{ "Category", "DDMMOCharacter" },
				{ "ModuleRelativePath", "Player/DDMMOCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Zoom_Power = { UE4CodeGen_Private::EPropertyClass::Float, "Zoom_Power", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADDMMOCharacter, Zoom_Power), METADATA_PARAMS(NewProp_Zoom_Power_MetaData, ARRAY_COUNT(NewProp_Zoom_Power_MetaData)) };
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
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentMessage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoomOut_Max,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoomIn_Max,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Zoom_Power,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseLookUpRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseTurnRate,
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
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(ADDMMOCharacter, 2230251998);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADDMMOCharacter(Z_Construct_UClass_ADDMMOCharacter, &ADDMMOCharacter::StaticClass, TEXT("/Script/DDMMO"), TEXT("ADDMMOCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADDMMOCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
