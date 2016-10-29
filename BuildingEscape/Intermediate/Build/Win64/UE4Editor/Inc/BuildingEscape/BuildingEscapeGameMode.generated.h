// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BUILDINGESCAPE_BuildingEscapeGameMode_generated_h
#error "BuildingEscapeGameMode.generated.h already included, missing '#pragma once' in BuildingEscapeGameMode.h"
#endif
#define BUILDINGESCAPE_BuildingEscapeGameMode_generated_h

#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_RPC_WRAPPERS
#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABuildingEscapeGameMode(); \
	friend BUILDINGESCAPE_API class UClass* Z_Construct_UClass_ABuildingEscapeGameMode(); \
	public: \
	DECLARE_CLASS(ABuildingEscapeGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/BuildingEscape"), NO_API) \
	DECLARE_SERIALIZER(ABuildingEscapeGameMode) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesABuildingEscapeGameMode(); \
	friend BUILDINGESCAPE_API class UClass* Z_Construct_UClass_ABuildingEscapeGameMode(); \
	public: \
	DECLARE_CLASS(ABuildingEscapeGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/BuildingEscape"), NO_API) \
	DECLARE_SERIALIZER(ABuildingEscapeGameMode) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABuildingEscapeGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABuildingEscapeGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABuildingEscapeGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABuildingEscapeGameMode); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABuildingEscapeGameMode(const ABuildingEscapeGameMode& InCopy); \
public:


#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABuildingEscapeGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABuildingEscapeGameMode(const ABuildingEscapeGameMode& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABuildingEscapeGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABuildingEscapeGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABuildingEscapeGameMode)


#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_11_PROLOG
#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_RPC_WRAPPERS \
	BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_INCLASS \
	BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_INCLASS_NO_PURE_DECLS \
	BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BuildingEscape_Source_BuildingEscape_BuildingEscapeGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
