/**
@file zwapi_point_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE MODULE FOR THE ZW3D Data Types and Structures of the point objects.
*/

#pragma once

#ifndef ZW_API_POINT_DATA_H
#define ZW_API_POINT_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief point input options
    @ingroup ZwPointData
    */
    typedef enum ezwPointInputOption
    {
        ZW_INPUT_POINT_GENERAL           = 0,  /**<@brief  general point */
        ZW_INPUT_POINT_ON_ENTITY         = 1,  /**<@brief  point on entity */
        ZW_INPUT_POINT_ON_CURVE          = 2,  /**<@brief  point on curve */
        ZW_INPUT_POINT_ON_EDGE           = 3,  /**<@brief  point on edge  */
        ZW_INPUT_POINT_ON_CURVE_OR_EDGE  = 4,  /**<@brief  point on curve or edge */
        ZW_INPUT_POINT_ON_ANY_FACE       = 5,  /**<@brief  point on any face */
        ZW_INPUT_POINT_ON_FIELD_1_FACE   = 6,  /**<@brief  point on fidle 1 face(specifial face) */
        ZW_INPUT_POINT_END               = 7,  /**<@brief  point end */
        ZW_INPUT_POINT_ASSEMBLY          = 8,  /**<@brief  point in assembly environment */
        ZW_INPUT_POINT_DIRECTION         = 9,  /**<@brief  point direction */
        ZW_INPUT_POINT_ON_CRV_OR_PROFILE = 10, /**<@brief  point on curve or profile */
        ZW_INPUT_POINT_ASSEM_FACE        = 11, /**<@brief  point on assembly face */
        ZW_INPUT_POINT_ASSEM_EDGE        = 12, /**<@brief  point on assembly edge  */
        ZW_INPUT_POINT_ASSEM_CURVE       = 13  /**<@brief  point on assembly curve */
    } ezwPointInputOption;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_POINT_DATA_H */
