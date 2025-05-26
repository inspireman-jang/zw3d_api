/**
@file zwapi_drawing_symbol_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Data Types and Structures
*/

#pragma once
#ifndef ZW_API_DRAWING_SYMBOL_DATA_H
#define ZW_API_DRAWING_SYMBOL_DATA_H

#include "zwapi_symbol_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief drawing symbol hole mark pattern method
    @ingroup ZwDrawingData
    */
    typedef enum ezwDrawingSymbolHoleMarkPattern
    {
        ZW_DRAWING_SYMBOL_HOLE_MARK_UP_LEFT_4,      /**<@brief  up-left 1/4 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_UP_RIGHT_4,     /**<@brief  up-right 1/4 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_DOWN_LEFT_4,    /**<@brief  down-left 1/4 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_DOWN_RIGHT_4,   /**<@brief  down-right 1/4 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_LEFT_BEVEL_4,   /**<@brief  left-bevel 1/4 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_RIGHT_BEVEL_4,  /**<@brief  right-bevel 1/4 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_UP_LEFT_12,     /**<@brief  up-left 1/12 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_UP_RIGHT_12,    /**<@brief  up-right 1/12 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_DOWN_LEFT_12,   /**<@brief  down-left 1/12 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_DOWN_RIGHT_12,  /**<@brief  down-right 1/12 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_LEFT_BEVEL_12,  /**<@brief  left-bevel 1/12 */
        ZW_DRAWING_SYMBOL_HOLE_MARK_RIGHT_BEVEL_12, /**<@brief  right-bevel 1/12 */
    } ezwDrawingSymbolHoleMarkPattern;
    
    /**
    @brief drawing symbol hole mark method
    @ingroup ZwDrawingData
    */
    typedef enum ezwDrawingSymbolHoleMarkType
    {
        ZW_DRAWING_SYMBOL_HOLE_MARK_AUTO   = 0, /**<@brief  auto pick */
        ZW_DRAWING_SYMBOL_HOLE_MARK_MANUAL = 1, /**<@brief  manual pick*/
    } ezwDrawingSymbolHoleMarkType;

    /**
    @brief drawing symbol surface finish Method
    @ingroup ZwDrawingSymbolData
    */
    typedef enum ezwDrawingSymbolSurfaceFinishMethod
    {
        ZW_DRAWING_SYMBOL_SURFACE_FINISH_NO_LEADER   = 0, /**<@brief  no leader */
        ZW_DRAWING_SYMBOL_SURFACE_FINISH_LEADER      = 1, /**<@brief  with leader */
        ZW_DRAWING_SYMBOL_SURFACE_FINISH_UNSPECIFIED = 2, /**<@brief  unspecified */
    } ezwDrawingSymbolSurfaceFinishMethod;

    /**
    @brief symbol type of surface finish
    @ingroup ZwDrawingSymbolData
    */
    typedef enum ezwSymbolSurfFinishType
    {
        ZW_SYMBOL_SURFACE_FINISH_BASIC = 0,            /**<@brief  basic */
        ZW_SYMBOL_SURFACE_FINISH_MACHINING_REQUIRED,   /**<@brief  material removal required */
        ZW_SYMBOL_SURFACE_FINISH_MACHINING_PROHIBITED, /**<@brief  material removal prohibited */
        ZW_SYMBOL_SURFACE_FINISH_JIS1,                 /**<@brief  JIS surface texture 1 */
        ZW_SYMBOL_SURFACE_FINISH_JIS2,                 /**<@brief  JIS surface texture 2 */
        ZW_SYMBOL_SURFACE_FINISH_JIS3,                 /**<@brief  JIS surface texture 3 */
        ZW_SYMBOL_SURFACE_FINISH_JIS4,                 /**<@brief  JIS surface texture 4 */
        ZW_SYMBOL_SURFACE_FINISH_JIS_NO_MACHINING      /**<@brief  JIS no machining */
    } ezwSymbolSurfFinishType;

    /**
    @brief lay direction symbol of surface finish
    @ingroup ZwDrawingSymbolData
    */
    typedef enum ezwSurfaceFinishLayDirection
    {
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_NONE = 0,      /**<@brief  none */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_RADIAL,        /**<@brief  radial */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_PERPENDICULAR, /**<@brief  perpendicular */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_ANGULAR,       /**<@brief  angular */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_MULTI_DIR,     /**<@brief  multi-directional */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_CIRCULAR,      /**<@brief  circular */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_PARALLEL,      /**<@brief  parallel */
        ZW_SYMBOL_SURFACE_FINISH_LAY_DIRCTION_PARTICULATE    /**<@brief  particulate */
    } ezwSurfaceFinishLayDirection;

    /**
    @brief drawing symbol hole mark data
    @ingroup ZwDrawingData
    */
    typedef struct szwDrawingSymbolHoleMark
    {
        ezwDrawingSymbolHoleMarkType type; /**<@brief  hole mark type */
        int numberCircle;                  /**<@brief  number of circle entities need to be marked */
        szwEntityHandle *circleHandle;     /**<@brief  list handle of circle entities need to be marked
                                                    if type = ZW_DRAWING_SYMBOL_HOLE_MARK_MANUAL, the circle is given by user
                                                    other type can be null */
        szwEntityHandle *viewHandle;       /**<@brief  handle of view
                                                    if type = ZW_DRAWING_SYMBOL_HOLE_MARK_AUTO, auto mark the hole in the view, 
                                                    other type can be null */
        int backfacing;                    /**<@brief  whether to mark backfacing holes(0 = no, 1 = yes).default:0
                                                    if type = ZW_DRAWING_SYMBOL_HOLE_MARK_AUTO, the option is available */
        int hidden;                        /**<@brief  whether to mark hidden holes(0 = no, 1 = yes).default:0
                                                    if type = ZW_DRAWING_SYMBOL_HOLE_MARK_AUTO, the option is available */
        int boolean;                       /**<@brief  whether to mark boolean holes(0 = no, 1 = yes).default:0
                                                    if type = ZW_DRAWING_SYMBOL_HOLE_MARK_AUTO, the option is available */

        ezwDrawingSymbolHoleMarkPattern pattern; /**<@brief  pattern of manual hole mark
                                                    (if type = ZW_DRAWING_SYMBOL_HOLE_MARK_MANUAL, the option is available).
                                                    default:ZW_DRAWING_SYMBOL_HOLE_MARK_UP_LEFT_4 */
    } szwDrawingSymbolHoleMark;
	
	/**
    @brief Weld data
    @ingroup ZwDrawingSymbolData
    */
    typedef struct szwSymbolWeldData
    {
        szwPointOnEntity referencePoint; /**<@brief  reference point */
        int useLocationPoint;            /**<@brief  whether to use location point setting, 0 to use default point */
        szwPointOnEntity locationPoint;  /**<@brief  the coordinate of location point */
        int jogNumber;                   /**<@brief  number of jog points */
        szwPointOnEntity *jogPoints;     /**<@brief  list of coordinate of jog points */
        int leaderNumber;                /**<@brief  number of leader points */
        szwPointOnEntity *leaderPoints;  /**<@brief  list of coordinate of leader points */
        szwSymbolWeldSetting settings;   /**<@brief  general settings for symbol weld */
    } szwSymbolWeldData;

    /**
    @brief surface finish settings data
    @ingroup ZwDrawingSymbolData
    */
    typedef struct szwSymbolSurfaceFinishSetting
    {
        int perpendicularFlag; /**<@brief  perpendicular flag (1-perpendicular, 2-reverse), only when method = ZW_DRAWING_SYMBOL_SURFACE_FINISH_NO_LEADER */
        double rotation;       /**<@brief  rotation angle(degree), taking effect only when method != ZW_DRAWING_SYMBOL_SURFACE_FINISH_UNSPECIFIED */

        ezwSymbolSurfFinishType symbolType; /**<@brief  symbol type */
        int isGrinding;                     /**<@brief  grinding (0/1), taking effect only when symbolType =  
                                                              ZW_SYMBOL_SURFACE_FINISH_JIS1 ~ ZW_SYMBOL_SURFACE_FINISH_JIS4 */

        zwString64 maxRoughnessAverage;            /**<@brief  max roughness average (or empty) */
        zwString64 minRoughnessAverage;            /**<@brief  min roughness average (or empty) */
        zwString64 processingMethod;               /**<@brief  processing method/treatment (or empty) */
        zwString64 samplintRoughness;              /**<@brief  sampling length/roughness cutout (or empty) */
        zwString64 machiningAllowance;             /**<@brief  machining allowance (or empty) */
        zwString64 roughnessValue;                 /**<@brief  Rz, roughness value (or empty) */
        zwString64 otherRoughnessValue;            /**<@brief  other roughness value/spacing (or empty) */
        ezwSurfaceFinishLayDirection layDirection; /**<@brief  surface pattern symbol */

    } szwSymbolSurfaceFinishSetting;

    /**
    @brief surface finish data
    @ingroup ZwDrawingSymbolData
    */
    typedef struct szwDrawingSymbolSurfaceFinish
    {
        ezwDrawingSymbolSurfaceFinishMethod method; /**<@brief  surface finish place method */
        union SurfaceFinishRequired
        {

            struct SurfaceFinishNoLeader
            {
                szwPointOnEntity referencePoint; /**<@brief  Ref.Point */
            } NoLeader;

            struct SurfaceFinishLead
            {
                szwPointOnEntity referencePoint; /**<@brief  Ref.Point */
                szwPointOnEntity leadPoint;      /**<@brief  lead point */
            } Leader;

            struct SurfaceFinishUnspecified
            {
                double distanceX; /**<@brief  unspecified surface distance finish X, used only when method = ZW_DRAWING_SYMBOL_SURFACE_FINISH_UNSPECIFIED */
                double distanceY; /**<@brief  unspecified surface distance finish Y, used only when method = ZW_DRAWING_SYMBOL_SURFACE_FINISH_UNSPECIFIED */
            } Unspecified;        /** @brief when method=ZW_DRAWING_SYMBOL_SURFACE_FINISH_UNSPECIFIED, the original point in this situation is at the top-right corner of the sheet,  
                                                            which is different from normal situation(original point is at the bottom-left corner of the sheet) **/

        } Required;


        szwSymbolSurfaceFinishSetting settings; /**<@brief  general settings for symbol surface finish */
    } szwDrawingSymbolSurfaceFinish;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_DRAWING_SYMBOL_DATA_H */
