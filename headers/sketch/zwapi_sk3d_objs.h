/**
@file zwapi_sk3d_objs.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note */

#pragma once
#ifndef ZW_API_SK3D_OBJS_H /* this ifndef surrounds entire header */
#define ZW_API_SK3D_OBJS_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketh3D objects */
    //====================================================================================================================
    /**
    @ingroup ZwSketch3D

    Outputs a curves list in specified 3d sketch .

    @note
    This function allocates memory for the out via "curves". 
    And the calling procedure is responsible to use 'ZwEntityHandleListFree' for memory deallocating.

    @see ZwEntityHandleListFree.

    @param [in] sketch the handle data of a specified 3d sketch entity 
    @param [out] count number of curves in the 3d sketch
    @param [out] curves the handle data list of curves in the 3d sketch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
        szwEntityHandle zSketchHandle{};
        ...
        int iCrvNum = 0;
        szwEntityHandle *pzCurveLists = nullptr;
        ...
        ZwSketch3DCurveListGet(zSketchHandle, &iCrvNum, &pzCurveLists);
        ...
        ZwEntityHandleListFree(iCrvNum, &pzCurveLists);
    @endcode
    */

    ZW_API_C ezwErrors ZwSketch3DCurveListGet(szwEntityHandle sketch, int *count, szwEntityHandle **curves);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK3D_OBJS_H */
