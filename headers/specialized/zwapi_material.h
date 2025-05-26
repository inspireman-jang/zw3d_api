/**
@file zwapi_material.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Material API
*/

#pragma once
#ifndef ZW_API_MATERIAL_H /* this ifndef surrounds entire header */
#define ZW_API_MATERIAL_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Part Material */
    //====================================================================================================================
    /**
    @ingroup ZwMaterial

    Obtain the material list in the specified file.

    @note
    The caller is responsible to free the materialList by using ZwMemoryFree().

    @param [out] materialCount number of materials
    @param [out] materialList list of materials names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwMaterialListGet(int *materialCount, zwString256 **materialList);
    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_MATERIAL_H */
