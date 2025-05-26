/**
@file zwapi_drawing_general_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the
drawing functions.
*/

#pragma once

#ifndef ZW_API_DRAWING_GENERAL_DATA_H /* *his ifndef surrounds entire header */
#define ZW_API_DRAWING_GENERAL_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Hatch */
    //====================================================================================================================
    /**
    @brief hatch type
    @ingroup ZwDrawingWireframeData
    */
    typedef enum ezwHatchType
    {
        ZW_HATCH_CUSTOM = -1, /**<@brief  custom hatch style */
        ZW_HATCH_STANDARD,    /**<@brief  from standard */
        ZW_HATCH_ANSI,        /**<@brief  hatch style (ANSI) */
        ZW_HATCH_ISO,         /**<@brief  hatch style (ISO) */
        ZW_HATCH_DIN,         /**<@brief  hatch style (DIN) */
        ZW_HATCH_JIS,         /**<@brief  hatch style (JIS) */
        ZW_HATCH_GB,          /**<@brief  hatch style (GB) */
    } ezwHatchType;

    /**
    @brief hatch pattern
    @ingroup ZwDrawingWireframeData
    */
    typedef enum ezwHatchPatternType
    {
        ZW_HATCH_PATTERN_ANSI31,         /**<@brief  ANSI31 */
        ZW_HATCH_PATTERN_ANSI32,         /**<@brief  ANSI32 */
        ZW_HATCH_PATTERN_ANSI33,         /**<@brief  ANSI33 */
        ZW_HATCH_PATTERN_ANSI34,         /**<@brief  ANSI34 */
        ZW_HATCH_PATTERN_ANSI35,         /**<@brief  ANSI35 */
        ZW_HATCH_PATTERN_ANSI36,         /**<@brief  ANSI36 */
        ZW_HATCH_PATTERN_ANSI37,         /**<@brief  ANSI37 */
        ZW_HATCH_PATTERN_ANSI38,         /**<@brief  ANSI38 */
        ZW_HATCH_PATTERN_SHADOW_PLATE,   /**<@brief  SHADOW_PLATE */
        ZW_HATCH_PATTERN_BRICK,          /**<@brief  BRICK */
        ZW_HATCH_PATTERN_CORK,           /**<@brief  CORK */
        ZW_HATCH_PATTERN_CROSS,          /**<@brief  CROSS */
        ZW_HATCH_PATTERN_DASH,           /**<@brief  DASH */
        ZW_HATCH_PATTERN_LIMESTONE,      /**<@brief  LIMESTONE */
        ZW_HATCH_PATTERN_DOTS,           /**<@brief  DOTS */
        ZW_HATCH_PATTERN_EARTH,          /**<@brief  EARTH */
        ZW_HATCH_PATTERN_EXPANSION,      /**<@brief  EXPANSION */
        ZW_HATCH_PATTERN_GRASS,          /**<@brief  GRASS */
        ZW_HATCH_PATTERN_GRATE,          /**<@brief  GRATE */
        ZW_HATCH_PATTERN_HEXAGON,        /**<@brief  HEXAGON */
        ZW_HATCH_PATTERN_HONEYCOMB,      /**<@brief  HONEYCOMB */
        ZW_HATCH_PATTERN_SQUARES,        /**<@brief  SQUARES */
        ZW_HATCH_PATTERN_MOONYANG,       /**<@brief  MOONYANG */
        ZW_HATCH_PATTERN_BOX,            /**<@brief  BOX */
        ZW_HATCH_PATTERN_BRASS,          /**<@brief  BRASS */
        ZW_HATCH_PATTERN_BRSTONE,        /**<@brief  BRSTONE */
        ZW_HATCH_PATTERN_CLAY,           /**<@brief  CLAY */
        ZW_HATCH_PATTERN_ESCHER,         /**<@brief  ESCHER */
        ZW_HATCH_PATTERN_GRAVEL,         /**<@brief  GRAVEL */
        ZW_HATCH_PATTERN_HOUND,          /**<@brief  HOUND */
        ZW_HATCH_PATTERN_INSUL,          /**<@brief  INSUL */
        ZW_HATCH_PATTERN_ACAD_ISO02W100, /**<@brief  ACAD_ISO02W100 */
        ZW_HATCH_PATTERN_ACAD_ISO03W100, /**<@brief  ACAD_ISO03W100 */
        ZW_HATCH_PATTERN_ACAD_ISO04W100, /**<@brief  ACAD_ISO04W100 */
        ZW_HATCH_PATTERN_ACAD_ISO05W100, /**<@brief  ACAD_ISO05W100 */
        ZW_HATCH_PATTERN_ACAD_ISO06W100, /**<@brief  ACAD_ISO06W100 */
        ZW_HATCH_PATTERN_ACAD_ISO07W100, /**<@brief  ACAD_ISO07W100 */
        ZW_HATCH_PATTERN_ACAD_ISO08W100, /**<@brief  ACAD_ISO08W100 */
        ZW_HATCH_PATTERN_ACAD_ISO09W100, /**<@brief  ACAD_ISO09W100 */
        ZW_HATCH_PATTERN_ACAD_ISO10W100, /**<@brief  ACAD_ISO10W100 */
        ZW_HATCH_PATTERN_ACAD_ISO11W100, /**<@brief  ACAD_ISO11W100 */
        ZW_HATCH_PATTERN_ACAD_ISO12W100, /**<@brief  ACAD_ISO12W100 */
        ZW_HATCH_PATTERN_ACAD_ISO13W100, /**<@brief  ACAD_ISO13W100 */
        ZW_HATCH_PATTERN_ACAD_ISO14W100, /**<@brief  ACAD_ISO14W100 */
        ZW_HATCH_PATTERN_ACAD_ISO15W100, /**<@brief  ACAD_ISO15W100 */
        ZW_HATCH_PATTERN_JIS_LC_20,      /**<@brief  JIS_LC_20 */
        ZW_HATCH_PATTERN_JIS_LC_20A,     /**<@brief  JIS_LC_20A */
        ZW_HATCH_PATTERN_JIS_LC_8A,      /**<@brief  JIS_LC_8A */
        ZW_HATCH_PATTERN_JIS_LC_8,       /**<@brief  JIS_LC_8 */
        ZW_HATCH_PATTERN_JIS_RC_10,      /**<@brief  JIS_RC_10 */
        ZW_HATCH_PATTERN_JIS_RC_15,      /**<@brief  JIS_RC_15 */
        ZW_HATCH_PATTERN_JIS_RC_18,      /**<@brief  JIS_RC_18 */
        ZW_HATCH_PATTERN_JIS_RC_30,      /**<@brief  JIS_RC_30 */
        ZW_HATCH_PATTERN_JIS_STN_1E,     /**<@brief  JIS_STN_1E */
        ZW_HATCH_PATTERN_JIS_STN_2_5,    /**<@brief  JIS_STN_2_5 */
        ZW_HATCH_PATTERN_JIS_WOOD,       /**<@brief  JIS_WOOD */
        ZW_HATCH_PATTERN_LINE,           /**<@brief  LINE */
        ZW_HATCH_PATTERN_MUDST,          /**<@brief  MUDST */
        ZW_HATCH_PATTERN_NET,            /**<@brief  NET */
        ZW_HATCH_PATTERN_NET3,           /**<@brief  NET3 */
        ZW_HATCH_PATTERN_PLAST,          /**<@brief  PLAST */
        ZW_HATCH_PATTERN_PLASTI,         /**<@brief  PLASTI */
        ZW_HATCH_PATTERN_SACNCR,         /**<@brief  SACNCR */
        ZW_HATCH_PATTERN_STARS,          /**<@brief  STARS */
        ZW_HATCH_PATTERN_STEEL,          /**<@brief  STEEL */
        ZW_HATCH_PATTERN_SWAMP,          /**<@brief  SWAMP */
        ZW_HATCH_PATTERN_TRANS,          /**<@brief  TRANS */
        ZW_HATCH_PATTERN_TRIANG,         /**<@brief  TRIANG */
        ZW_HATCH_PATTERN_ZIGZAG,         /**<@brief  ZIGZAG */
        ZW_HATCH_PATTERN_SOLID,          /**<@brief  SOLID */
    } ezwHatchPatternType;

    /**
    @brief cross hatch data
    @ingroup ZwDrawingWireframeData
    */
    typedef struct szwCrossHatchData
    {
        ezwHatchType type;           /**<@brief  hatch type
                                       default: ZW_HATCH_STANDARD */
        ezwHatchPatternType pattern; /**<@brief  hatch pattern method
                                       default: ZW_HATCH_PATTERN_ANSI31 */
        double angle;                /**<@brief  angle attribute
                                       default: 0.0 */
        double space;                /**<@brief  spacing attribute
                                       default: 3.175 */
        szwPoint2 origin;            /**<@brief  origin point
                                       default: {0.0,0.0} */
        ezwColor color;              /**<@brief  color attribute
                                       default: ZW_COLOR_BLACK */
        ezwLineWidth width;          /**<@brief  line width
                                       default: ZW_WIDTH_018 */
    } szwCrossHatchData;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_GENERAL_DATA_H */
