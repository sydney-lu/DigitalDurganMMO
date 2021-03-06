// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
class UCharacterSkillData;
class UPlayerInfoWidget;
#ifdef DDMMO_DDMMOCharacter_generated_h
#error "DDMMOCharacter.generated.h already included, missing '#pragma once' in DDMMOCharacter.h"
#endif
#define DDMMO_DDMMOCharacter_generated_h

#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnMeleeHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnMeleeHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSkillDelegate) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_OBJECT(UCharacterSkillData,Z_Param_skillData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetSkillDelegate(Z_Param_index,Z_Param_skillData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSkillSelection) \
	{ \
		P_GET_OBJECT(UPlayerInfoWidget,Z_Param_widget); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetSkillSelection(Z_Param_widget); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindTarget) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FindTarget(); \
		P_NATIVE_END; \
	}


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnMeleeHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnMeleeHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSkillDelegate) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_index); \
		P_GET_OBJECT(UCharacterSkillData,Z_Param_skillData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetSkillDelegate(Z_Param_index,Z_Param_skillData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSkillSelection) \
	{ \
		P_GET_OBJECT(UPlayerInfoWidget,Z_Param_widget); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetSkillSelection(Z_Param_widget); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindTarget) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FindTarget(); \
		P_NATIVE_END; \
	}


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADDMMOCharacter(); \
	friend DDMMO_API class UClass* Z_Construct_UClass_ADDMMOCharacter(); \
public: \
	DECLARE_CLASS(ADDMMOCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DDMMO"), NO_API) \
	DECLARE_SERIALIZER(ADDMMOCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_INCLASS \
private: \
	static void StaticRegisterNativesADDMMOCharacter(); \
	friend DDMMO_API class UClass* Z_Construct_UClass_ADDMMOCharacter(); \
public: \
	DECLARE_CLASS(ADDMMOCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DDMMO"), NO_API) \
	DECLARE_SERIALIZER(ADDMMOCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_STANDARD_CONSTRUCTORS \
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


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADDMMOCharacter(ADDMMOCharacter&&); \
	NO_API ADDMMOCharacter(const ADDMMOCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADDMMOCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADDMMOCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADDMMOCharacter)


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ADDMMOCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ADDMMOCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__MuzzleOffset() { return STRUCT_OFFSET(ADDMMOCharacter, MuzzleOffset); } \
	FORCEINLINE static uint32 __PPO__ProjectileClass() { return STRUCT_OFFSET(ADDMMOCharacter, ProjectileClass); } \
	FORCEINLINE static uint32 __PPO__SkeletalMesh() { return STRUCT_OFFSET(ADDMMOCharacter, SkeletalMesh); } \
	FORCEINLINE static uint32 __PPO__MeleeCollider() { return STRUCT_OFFSET(ADDMMOCharacter, MeleeCollider); }


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_35_PROLOG
#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_RPC_WRAPPERS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_INCLASS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_INCLASS_NO_PURE_DECLS \
	DDMMO_Source_DDMMO_Player_DDMMOCharacter_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DDMMO_Source_DDMMO_Player_DDMMOCharacter_h


#define FOREACH_ENUM_PLAYERCHARACTERSTATE(op) \
	op(PlayerCharacterState::IDLE) \
	op(PlayerCharacterState::ATTACKING) \
	op(PlayerCharacterState::RESTING) \
	op(PlayerCharacterState::CASTING) \
	op(PlayerCharacterState::TRAVERSAL_WALK) \
	op(PlayerCharacterState::TRAVERSAL_RUN) \
	op(PlayerCharacterState::TRAVERSAL_FLY) \
	op(PlayerCharacterState::TRAVERSAL_SWIM) \
	op(PlayerCharacterState::DISABLED) \
	op(PlayerCharacterState::HARDCROWDCONTROL) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
