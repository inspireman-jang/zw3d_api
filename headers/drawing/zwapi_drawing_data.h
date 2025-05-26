/**
@file zwapi_drawing_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Data Types and Structures 
for the Drawing API function
*/

#pragma once
#ifndef ZW_API_DRAWING_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_DATA_H

#include "zwapi_util.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Text Data */
    //====================================================================================================================
    /**
    @brief drawing text type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingTextType
    {
        ZW_DRAWING_DIMENSION_TEXT_STANDARD = 0, /**<@brief  standard attribute */
        ZW_DRAWING_DIMENSION_TEXT_PHYSICAL,     /**<@brief  physical attribute */
        ZW_DRAWING_DIMENSION_TEXT_FILE,         /**<@brief  file information */
        ZW_DRAWING_DIMENSION_TEXT_ECAD,         /**<@brief  ecad attribute */
        ZW_DRAWING_DIMENSION_TEXT_USER,         /**<@brief  user attribute */
        ZW_DRAWING_DIMENSION_TEXT_USER_TEXT,    /**<@brief  custom text */
    } ezwDrawingTextType;

    /**
    @brief drawing text sub type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingTextSubType
    {
        /* ezwDrawingTextType::ZW_DRAWING_DIMENSION_TEXT_STANDARD */
        ZW_DRAWING_DIMENSION_TEXT_ID          = 0,  /**<@brief  id */
        ZW_DRAWING_DIMENSION_TEXT_DERIVEDFROM = 1,  /**<@brief  derived from, merge support */
        ZW_DRAWING_DIMENSION_TEXT_NUMBER      = 2,  /**<@brief  number, merge support */
        ZW_DRAWING_DIMENSION_TEXT_DESIGNER    = 3,  /**<@brief  designer, merge support */
        ZW_DRAWING_DIMENSION_TEXT_MANAGER     = 4,  /**<@brief  manager, merge support */
        ZW_DRAWING_DIMENSION_TEXT_REMARKS     = 5,  /**<@brief  remarks */
        ZW_DRAWING_DIMENSION_TEXT_SUPPLIER    = 6,  /**<@brief  supplier, merge support */
        ZW_DRAWING_DIMENSION_TEXT_COST        = 7,  /**<@brief  cost, merge support */
        ZW_DRAWING_DIMENSION_TEXT_CLASS       = 8,  /**<@brief  class, merge support */
        ZW_DRAWING_DIMENSION_TEXT_KEYWORDS    = 9,  /**<@brief  keywords, merge support */
        ZW_DRAWING_DIMENSION_TEXT_DESCRIPTION = 10, /**<@brief  description, merge support */
        ZW_DRAWING_DIMENSION_TEXT_QUANTITY    = 11, /**<@brief  quantity */
        ZW_DRAWING_DIMENSION_TEXT_VISIBLE     = 12, /**<@brief  visible */

        /* ezwDrawingTextType::ZW_DRAWING_DIMENSION_TEXT_PHYSICAL */
        ZW_DRAWING_DIMENSION_TEXT_DENSITY   = 0, /**<@brief  density */
        ZW_DRAWING_DIMENSION_TEXT_MASS      = 1, /**<@brief  mass */
        ZW_DRAWING_DIMENSION_TEXT_AREA      = 2, /**<@brief  area */
        ZW_DRAWING_DIMENSION_TEXT_VOLUME    = 3, /**<@brief  volume */
        ZW_DRAWING_DIMENSION_TEXT_LENGTH    = 4, /**<@brief  length */
        ZW_DRAWING_DIMENSION_TEXT_WIDTH     = 5, /**<@brief  width */
        ZW_DRAWING_DIMENSION_TEXT_HEIGHT    = 6, /**<@brief  height */
        ZW_DRAWING_DIMENSION_TEXT_STOCKSIZE = 7, /**<@brief  stock size */
        ZW_DRAWING_DIMENSION_TEXT_SIZE      = 8, /**<@brief  size */
        ZW_DRAWING_DIMENSION_TEXT_MATERIAL  = 9, /**<@brief  material */

        /* ezwDrawingTextType::ZW_DRAWING_DIMENSION_TEXT_FILE */
        ZW_DRAWING_DIMENSION_TEXT_NAME      = 0, /**<@brief  legend */
        ZW_DRAWING_DIMENSION_TEXT_FILEPATH  = 1, /**<@brief  source file path */
        ZW_DRAWING_DIMENSION_TEXT_STARTDATE = 2, /**<@brief  start date */
        ZW_DRAWING_DIMENSION_TEXT_ENDDATE   = 3, /**<@brief  end date */

        /* ezwDrawingTextType::ZW_DRAWING_DIMENSION_TEXT_ECAD */
        ZW_DRAWING_DIMENSION_TEXT_ECAD_REF_DES    = 0, /**<@brief  ECAD_RefDes */
        ZW_DRAWING_DIMENSION_TEXT_ECAD_BOARD_SIDE = 1, /**<@brief  ECAD board side */

        /* ezwDrawingTextType::ZW_DRAWING_DIMENSION_TEXT_USER and ezwDrawingTextType::ZW_DRAWING_DIMENSION_TEXT_USER_TEXT */
        ZW_DRAWING_DIMENSION_TEXT_NULL = -1,
    } ezwDrawingTextSubType;
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_DATA_H */
