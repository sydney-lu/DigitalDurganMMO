// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DDMMO_DDMMOCharacter_generated_h
#error "DDMMOCharacter.generated.h already included, missing '#pragma once' in DDMMOCharacter.h"
#endif
#define DDMMO_DDMMOCharacter_generated_h

#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_RPC_WRAPPERS \
	virtual bool ServerSendChatMessage_Validate(const FString& ); \
	virtual void ServerSendChatMessage_Implementation(const FString& Message); \
 \
	DECLARE_FUNCTION(execOnRep_CurrentMessage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_CurrentMessage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSendChatMessage) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerSendChatMessage_Validate(Z_Param_Message)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSendChatMessage_Validate")); \
			return; \
		} \
		this->ServerSendChatMessage_Implementation(Z_Param_Message); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttemptToSendChatMessage) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AttemptToSendChatMessage(Z_Param_Message); \
		P_NATIVE_END; \
	}


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_CurrentMessage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_CurrentMessage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerSendChatMessage) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerSendChatMessage_Validate(Z_Param_Message)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerSendChatMessage_Validate")); \
			return; \
		} \
		this->ServerSendChatMessage_Implementation(Z_Param_Message); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttemptToSendChatMessage) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AttemptToSendChatMessage(Z_Param_Message); \
		P_NATIVE_END; \
	}


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_EVENT_PARMS \
	struct DDMMOCharacter_eventServerSendChatMessage_Parms \
	{ \
		FString Message; \
	};


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_CALLBACK_WRAPPERS
#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADDMMOCharacter(); \
	friend DDMMO_API class UClass* Z_Construct_UClass_ADDMMOCharacter(); \
public: \
	DECLARE_CLASS(ADDMMOCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DDMMO"), NO_API) \
	DECLARE_SERIALIZER(ADDMMOCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADDMMOCharacter(); \
	friend DDMMO_API class UClass* Z_Construct_UClass_ADDMMOCharacter(); \
public: \
	DECLARE_CLASS(ADDMMOCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DDMMO"), NO_API) \
	DECLARE_SERIALIZER(ADDMMOCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADDMMOCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADDMMOCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADDMMOCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADDMMOCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADDMMOCharacter(ADDMMOCharacter&&); \
	NO_API ADDMMOCharacter(const ADDMMOCharacter&); \
public:


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADDMMOCharacter(ADDMMOCharacter&&); \
	NO_API ADDMMOCharacter(const ADDMMOCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADDMMOCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADDMMOCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADDMMOCharacter)


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ADDMMOCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ADDMMOCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CurrentMessage() { return STRUCT_OFFSET(ADDMMOCharacter, CurrentMessage); }


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_9_PROLOG \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_EVENT_PARMS


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_RPC_WRAPPERS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_CALLBACK_WRAPPERS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_INCLASS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_CALLBACK_WRAPPERS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_INCLASS_NO_PURE_DECLS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DDMMO_Source_DDMMO_Player_DDMMOCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
