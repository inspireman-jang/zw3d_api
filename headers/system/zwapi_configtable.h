/**
@file zwapi_configtable.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Global Table Config Table API
*/

#pragma once
#ifndef ZW_API_CONFIGTABLE_H /* this ifndef surrounds entire header */
#define ZW_API_CONFIGTABLE_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Config Table Query */
    //====================================================================================================================
    /**
    @ingroup ZwConfigTable

    Outputs the active configuration handle data of active file.

    @see ZwConfigActivate

    @note
    The caller is responsible to free the config by using ZwEntityHandleFree().

    @param [out] config the handle of current active configuration

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwConfigActiveGet(szwEntityHandle *config);

    /**
    @ingroup ZwConfigTable

    Outputs the configuration handle list of current active part.

    @note
    The caller is responsible to free the configList by using ZwEntityHandleListFree().

    @param [out] countConfig the number of part configuration
    @param [out] configList the list of part configuration handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_AIP_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwConfigListGet(int *countConfig, szwEntityHandle **configList);
    
    /**
    @ingroup ZwConfigTable

    Outputs the configuration handle list of the specified component.

    @note
    The caller is responsible to free the configList by using ZwEntityHandleListFree().

    @param [int] componentHandle handle data of component 
    @param [out] countConfig the number of part configuration
    @param [out] configList the list of part configuration handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentConfigListGet(szwEntityHandle componentHandle, int *countConfig, szwEntityHandle **configList);

    /**
    @ingroup ZwConfigTable

    Gets the handle of the specified component configuration.

    @see ZwComponentConfigSet

    @note
    The caller is responsible to free the configHandle by using ZwEntityHandleFree().

    @param [in] componentHandle component handle
    @param [out] configHandle config handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentConfigGet(szwEntityHandle componentHandle, szwEntityHandle *configHandle);

    /**
    @ingroup ZwConfigTable

    Sets the handle of the specified component configuration.

    @see ZwComponentConfigGet

    @param [in] componentHandle component handle
    @param [in] configHandle config handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentConfigSet(szwEntityHandle componentHandle, szwEntityHandle configHandle);

    //====================================================================================================================
    /** @name Config Table Activate */
    //====================================================================================================================
    /**
    @ingroup ZwConfigTable

    Actives the specified configuration to current part.

    @see ZwConfigActiveGet

    @param [in] configHandle config handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwConfigActivate(szwEntityHandle configHandle);

    //====================================================================================================================
    /** @name Config Table Refresh */
    //====================================================================================================================
    /**
    @ingroup ZwConfigTable

    Refresh the config table form data.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwConfigTableRefresh();

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_CONFIG_H */
