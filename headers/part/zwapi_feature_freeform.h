/**
@file zwapi_feature_freeform.h
@copyright (C) Copyright 2023, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Feature API
*/

#pragma once
#ifndef ZW_API_FEATURE_FREEFORM_H /* this ifndef surrounds entire header */
#define ZW_API_FEATURE_FREEFORM_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Edit Face */
    //====================================================================================================================
    /**
    @ingroup ZwFeatureFreeForm

    Offset a face with distance "distance".  
    Original surface will be deleted if "keep=0".

    @param [in] faceHandle face handle data
    @param [in] distance offset distance
    @param [in] keep 1 to keep "Original surface"; 0 to delete it

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureFaceOffset(szwEntityHandle faceHandle, double distance, int keep);


   /*
   *********************************************************************
   **  END HEADER FILE
   *********************************************************************
   */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FEATURE_FREEFORM_H */
