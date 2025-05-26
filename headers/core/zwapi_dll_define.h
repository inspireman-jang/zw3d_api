/**
@file zwapi_dll_define.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
*/

#pragma once
#ifndef ZW_API_DLL_DEFINE_H

#ifndef ZW_API_C
#if defined ZS_API_BUILD
#if defined(_MSC_VER)
#define ZW_API_C __declspec(dllexport)
#elif defined(__GNUC__)
#if defined(__linux__)
#define ZW_API_C __attribute__((visibility("default")))
#elif defined(_WIN32)
#define ZW_API_C __declspec(dllexport)
#endif
#endif

#elif !defined ZS_STATIC_BUILD
#if defined(_MSC_VER)
#define ZW_API_C __declspec(dllimport)
#elif defined(__GNUC__)
#if defined(__linux__)
#define ZW_API_C __attribute__((visibility("default")))
#elif defined(_WIN32)
#define ZW_API_C
#endif
#endif

#else /* Static libraries should not import the symbols.(Fix warning LINK4217)*/
#define ZW_API_C
#endif // ZS_API_BUILD
#endif // !ZW_API_C

#endif // !ZW_API_DLL_DEFINE_H
