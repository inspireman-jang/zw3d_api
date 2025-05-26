/**
@file zwapi_harness.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Harness API
*/

#pragma once
#ifndef ZW_API_HARNESS_H /* this ifndef surrounds entire header */
#define ZW_API_HARNESS_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Harness Data Query */
    //====================================================================================================================
    /**
    @ingroup ZwGeneralHarness

    Gets shape handles from harness part in harness assembly.

    @note
    Harness part has two list of shapes, this function gets the shapes generated from harness operations.  
    If you want to get shapes generated from normal feature, please use cvxPartInqShapes().  
    The calling procedure MUST deallocate the output list with ZwEntityHandleListFree().

    @code
        szwEntityHandle* harnessPartHandle = NULL;
        int count = 0;
        szwEntityHandle *shapeHandleList = NULL;
        ZwHarnessShapeListGet(harnessPartHandle, &count, &shapeHandleList);
        ...
        ZwEntityHandleFree(harnessPartHandle);
        ZwEntityHandleListFree(count, &shapeHandleList);
    @endcode

    @param [in] harnessPartHandle handle of harness part, NULL to get shape handles from active part
    @param [out] count the count of shape handle
    @param [out] shapeHandleList list of shape handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwHarnessShapeListGet(const szwEntityHandle *harnessPartHandle, int *count, szwEntityHandle **shapeHandleList);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_HARNESS_H */