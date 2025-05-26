/**
@file zwapi_dataexchange.h
@copyright (C) Copyright 2023, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Exchange API
*/

#pragma once
#ifndef ZW_API_DATAEXCHANGE_H /* this ifndef surrounds entire header */
#define ZW_API_DATAEXCHANGE_H

#include "zwapi_util.h"
#include "zwapi_dataexchange_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name External Feature Query */
    //===================================================================================================================
    /**
    @ingroup ZwDataExchange

    Gets information about the source file associated with the specified
    external reference feature, including file name, root name.

    A file that is too long (longer than "nFileBytes") is truncated.
    A rootName that is too long (longer than "nRootBytes") is truncated.

    It is assumed that the input "fileName" is no longer than 512 bytes.
    It is assumed that the input "rootName" is no longer than 256 bytes.

    @param [in] featureHandle handle data of external feature in active part
    @param [in] nFileBytes max size of file name
    @param [out] fileName associated external file name
    @param [in] nRootBytes max size of root name
    @param [out] rootName associated external root name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        Zw_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwExternalFeatureFileAndRootNameGet(szwEntityHandle featureHandle, int nFileBytes, char *fileName, int nRootBytes, char *rootName);

    //====================================================================================================================
    /** @name Import */
    //====================================================================================================================

    /**
    @ingroup ZwDataexchage

    Copy and insert the specified part at the specified location.  
    Outputs a list of handles of the new shapes.  
    Function Guide: Data Exchange->Import->ExternalPart

    @note
    The caller is responsible to free the shapeList by using ZwEntityHandleListFree().

    @param [in] data component data
    @param [out] count number of shapes (NULL to ignore)
    @param [out] shapeList list of shape handles (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CCMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwExternalPartImport(szwPartImportData data, int *count, szwEntityHandle **shapeList);

    /**
    @ingroup ZwDataExchange
    
    Creates a copy of the specified external geometry (face, shape, curve or edge) in the active
    target part. The input geometry handle must give the full traversal path to the external geometry
    relative to the top-level part of the parent assembly of the active target part. The handle of
    the new geometry created in the active part is output via "handle".
    Function Guide: Data Exchange->Import->Reference
    
    @note
    The caller is responsible to free the handle by using ZwEntityHandleFree().
    
    @param [in] geometry handle of external geometry relative to top-level parent file
    @param [in] associativeCopy reference copy option
    @param [out] handle handle of new geometry (NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwReferenceCreate(szwEntityHandle geometry, ezwReferenceCopyOption associativeCopy, szwEntityHandle *handle);

   /*
   *********************************************************************
   **  END HEADER FILE
   *********************************************************************
   */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATAEXCHANGE_H */
