/**
@file zwapi_feature_data_exchange.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE  ZW3D Feature Data Exchange API
*/

#pragma once
#ifndef ZW_API_FEATURE_DATA_EXCHANGE_H
#define ZW_API_FEATURE_DATA_EXCHANGE_H

#include "zwapi_feature_data_exchange_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Import */
    //====================================================================================================================

    /**
    @ingroup ZwFeatureDataExchange

    Initializes the parameters of the szwExternalGeometryCopyData.  

    @note
    Do not assign a value to variable "data" before calling this function.  
    The ZwMemoryZero() is called inside the interface to empty everything.  

    @param [in] copyType type of the command 'External Geom Copy'
    @param [out] data data of the command 'External Geom Copy'

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureExternalGeometryCopyInit(ezwExternalGeometryCopyType copyType, szwExternalGeometryCopyData *data);

    /**
    @ingroup ZwFeatureDataExchange

    Copy the geometries from external data, it can be from a file or a component.  

    @note
    The caller is responsible to free the featureHandle by using ZwEntityHandleFree().  
    When data.copyType is ZW_GEOMETRY_COPY_FROM_EXTERNAL_FILE, the entity handles should be retrieved from the file.  
    When data.copyType is ZW_GEOMETRY_COPY_FROM_LOCAL, the entity handles be retrieved from the components.  

    @param [in] data data to copy geometries
    @param [out] featureHandle the generated feature of the command 'External Geom Copy' (NULLto ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_ENT_PATH_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureExternalGeometryCopyCreate(szwExternalGeometryCopyData data, szwEntityHandle *featureHandle);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // !ZW_API_FEATURE_DATA_EXCHANGE_H
