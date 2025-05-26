/**
@file zwapi_command_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Command Common Data
*/

#pragma once
#ifndef ZW_API_COMMAND_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_COMMAND_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Command Operation Data */
    //====================================================================================================================
    /**
    @brief variable pointer of command
    @ingroup ZwCommandData
    */
    typedef void *zwVariablePointer;

    /**
    @brief command execution priority
    @ingroup ZwCommandData
    */
    typedef enum ezwCommandPostPriority
    {
        ZW_COMMAND_POST_PRIORITY_LOW = 0, /**<@brief  post a command with lower priority */
        ZW_COMMAND_POST_PRIORITY_HIGH,    /**<@brief  post a command with higher priority */
    } ezwCommandPostPriority;

    /**
    @brief The type of command reactor
    @ingroup ZwCommandData
    */
    typedef enum ezwCommandReactorType
    {
        ZW_COMMAND_START = 0,            /**<@brief  called before command starts */
        ZW_COMMAND_FINISH,               /**<@brief  called after command finished (notify only) */
        ZW_TEMPLATE_COMMAND_EXEC_START,  /**<@brief  called before the main function of a template command starts */
        ZW_TEMPLATE_COMMAND_EXEC_FINISH, /**<@brief  called after the main function of a template command finished (notify only) */
    } ezwCommandReactorType;

    /**
    @brief The structure for command reactor
    @ingroup ZwCommandData
    */
    typedef struct szwCommandReactorData
    {
        zwString256 uniqueName;                /**<@brief  unique name to label the callback function */
        int (*callbackFunction)(const char *); /**<@brief  callback function. This parameter should be a valid function pointer
                                                       when adding it the command reactor. And to delete the callback, it
                                                       should be NULL and use the same unique name. */
    } szwCommandReactorData;

    /**
    @brief function pointer of command
    @ingroup ZwCommandData
    */
    typedef void *zwFunctionPointer;

    /**
    @brief command license type
    @ingroup ZwCommandData
    */
    typedef enum ezwCommandLicenseType
    {
        ZW_LICENSE_CODE_GENERAL = 0,        /**<@brief  general */
        ZW_LICENSE_CODE_ADVANCED_RENDERING, /**<@brief  advanced rendering */
        ZW_LICENSE_CODE_ASSEMBLY,           /**<@brief  assembly */
        ZW_LICENSE_CODE_ADVANCED_ASSEMBLY,  /**<@brief  advanced assembly */
        ZW_LICENSE_CODE_DRAFTING,           /**<@brief  drafting */
        ZW_LICENSE_CODE_WIREFRAME,          /**<@brief  wireframe */
        ZW_LICENSE_CODE_MODELING,           /**<@brief  modeling */
        ZW_LICENSE_CODE_ADVANCED_MODELING,  /**<@brief  advanced modeling */
        ZW_LICENSE_CODE_SURFACE,            /**<@brief  surface */
        ZW_LICENSE_CODE_MOLD_DESIGN,        /**<@brief  mold design */
        ZW_LICENSE_CODE_HEALING,            /**<@brief  healing */
        ZW_LICENSE_CODE_POST,               /**<@brief  post */
        ZW_LICENSE_CODE_KEYSHOT,            /**<@brief  KeyShot */
        ZW_LICENSE_CODE_ELECTRODE,          /**<@brief  electrode */
        ZW_LICENSE_CODE_PARTSOLUTIONS,      /**<@brief  PARTsolutions */
        ZW_LICENSE_CODE_MISUMI,             /**<@brief  Misumi */
    } ezwCommandLicenseType;


    //====================================================================================================================
    /** @name Macro Data */
    //====================================================================================================================

    /**
    @brief macro type
    @ingroup ZwCommandData
    */
    typedef enum ezwMacroType
    {
        ZW_MACRO_STATEMENTS = 0, /**<@brief  statements of macro format */
        ZW_MACRO_FILE       = 1, /**<@brief  fullpath of a macro file */
    } ezwMacroType;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_COMMAND_DATA_H */
