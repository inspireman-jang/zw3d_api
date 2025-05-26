/**
@file zwapi_dimension.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Form API
*/


#pragma once
#ifndef ZW_API_DIMENSION_H /* this ifndef surrounds entire header */
#define ZW_API_DIMENSION_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name dimension */
    //====================================================================================================================
    /**
    @ingroup ZwDimension

    Get dimension (include dimension bundle) text point location of specified dimension.

    @param [in] dimensionHandle handle of dimension (include dimension bundle).
    @param [out] textPoint dimension text origin

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDimensionTextPointGet(szwEntityHandle dimensionHandle, szwPoint *textPoint);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DIMENSION_H */
