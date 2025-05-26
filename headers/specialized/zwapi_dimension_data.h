/**
@file zwapi_dimension_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for Dimension objects.
*/

#pragma once
#ifndef ZW_API_DIMENSION_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_DIMENSION_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Dimension Data */
    //====================================================================================================================
    /**
    @brief dimension type
    @ingroup ZwDimensionData
    */
    typedef enum ezwDimensionType
    {
        ZW_DIMENSION_NONE,             /**<@brief  invalid */
        ZW_LINEAR_DIMENSION,           /**<@brief  linear dimension */
        ZW_BASELINE_DIMENSION,         /**<@brief  baseline dimension */
        ZW_CONTINUOUS_DIMENSION,       /**<@brief  continuous dimension */
        ZW_ORDINATE_DIMENSION,         /**<@brief  ordinate dimension */
        ZW_LINEAR_OFFSET_DIMENSION,    /**<@brief  linear offset dimension */
        ZW_LINEAR_CHAMFER_DIMENSION,   /**<@brief  linear chamfer dimension */
        ZW_ANGULAR_DIMENSION,          /**<@brief  angular dimension */
        ZW_RADIAL_DIAMETRIC_DIMENSION, /**<@brief  radial/diametric dimension */
        ZW_ARC_LENGTH_DIMENSION,       /**<@brief  arc length dimension */
        ZW_SYMMETRY_DIMENSION,         /**<@brief  symmetry dimension*/
        ZW_HOLE_CALLOUT_DIMENSION,     /**<@brief  hole callout */
        ZW_LABEL_ANNOTATION,           /**<@brief  leader label annotation */
        ZW_BALLOON_ANNOTATION,         /**<@brief  balloon annotation */
        ZW_DATUM_FEATURE,              /**<@brief  datum feature */
        ZW_DATUM_TARGET,               /**<@brief  datum target */
        ZW_FEATURE_CONTROL,            /**<@brief  feature control */
        ZW_CENTER_LINE_MARK,           /**<@brief  centerline/center mark */
        ZW_INTERSECTION_SYMBOL,        /**<@brief  intersection symbol */
        ZW_LABEL_COORDINATE,           /**<@brief  label coordinate  */
        ZW_ELEVATION,                  /**<@brief  elevation */
        ZW_DIMENSION_LAST
    } ezwDimensionType;

    /**
    @brief feature control geometric characteristic symbol
    @ingroup ZwDimensionData
    */
    typedef enum ezwGeometricCharacteristic
    {
        ZW_FEATURE_CONTROL_STRAIGHTNESS,       /**<@brief  straightness */
        ZW_FEATURE_CONTROL_FLATNESS,           /**<@brief  flatness */
        ZW_FEATURE_CONTROL_CIRCULARITY,        /**<@brief  circularity */
        ZW_FEATURE_CONTROL_CYLINDRICITY,       /**<@brief  cylindricity */
        ZW_FEATURE_CONTROL_PARALLELISM,        /**<@brief  parallelism */
        ZW_FEATURE_CONTROL_PERPENDICULARITY,   /**<@brief  perpendicularity */
        ZW_FEATURE_CONTROL_ANGULARITY,         /**<@brief  angularity */
        ZW_FEATURE_CONTROL_POSITION,           /**<@brief  position */
        ZW_FEATURE_CONTROL_CONCENTRICITY,      /**<@brief  concentricity */
        ZW_FEATURE_CONTROL_SYMMETRY,           /**<@brief  symmetry */
        ZW_FEATURE_CONTROL_PROFILE_OF_LINE,    /**<@brief  profile of a line */
        ZW_FEATURE_CONTROL_PROFILE_OF_SURFACE, /**<@brief  profile of a surface */
        ZW_FEATURE_CONTROL_CIRCULAR_RUNOUT,    /**<@brief  circular run-out */
        ZW_FEATURE_CONTROL_TOTAL_RUNOUT,       /**<@brief  total run-out */
    } ezwGeometricCharacteristic;

    /**
    @brief datum target type
    @ingroup ZwDimensionData
    */
    typedef enum ezwDatumTargetType
    {
        ZW_DATUM_TARGET_CIRCLE = 0, /**<@brief  datum target circle */
        ZW_DATUM_TARGET_RECTANGLE,  /**<@brief  datum target rectangle */
        ZW_DATUM_TARGET_LINE,       /**<@brief  datum target line */
        ZW_DATUM_TARGET_POINT,      /**<@brief  datum target point */
    } ezwDatumTargetType;

    /**
    @brief datum target area size text
    @ingroup ZwDimensionData
    */
    typedef enum ezwDatumTargetUpperText
    {
        ZW_UPPER_TEXT_AREA_SIZE, /**<@brief  upper text: area size */
        ZW_UPPER_TEXT_USER_TEXT, /**<@brief  upper text: user text */
    } ezwDatumTargetUpperText;

    /**
    @brief datum target dimension data
    @ingroup ZwDimensionData
    */
    typedef struct szwDatumTargetData
    {
        ezwDatumTargetType type; /**<@brief  datum target type */
        union szwTarget
        {
            szwPointOnEntity point; /**<@brief  datum target point */
            struct szwTargetCircle  /**<@brief  datum target circle */
            {
                szwPointOnEntity center; /**<@brief  circle center */
                double diameter;         /**<@brief  circle diameter */
            } circle;
            struct szwTargetRectangle /**<@brief  datum target rectangle */
            {
                szwPointOnEntity center; /**<@brief  rectangle center */
                double width;            /**<@brief  rectangle width */
                double height;           /**<@brief  rectangle height */
            } rectangle;
            struct szwTargetLine /**<@brief  datum target line */
            {
                szwPointOnEntity start; /**<@brief  line start point */
                szwPointOnEntity end;   /**<@brief  line end point */
            } line;
        } target;

        szwPointOnEntity textPoint; /**<@brief  text point */
        zwString1024 datumText;     /**<@brief  the lower text of the datum target symbol */

        /* Optional settings */
        zwString1024 datumText2;           /**<@brief  the lower text of the second datum target symbol */
        zwString1024 datumText3;           /**<@brief  the lower text of the third datum target symbol */
        ezwDatumTargetUpperText upperText; /**<@brief  upper text generated method */
        zwString1024 userUpperText;        /**<@brief  user upper text, used when upperText is ZW_UPPER_TEXT_USER_TEXT */
    } szwDatumTargetData;

    /**
    @brief hole callout element
    @ingroup ZwDimensionData
    */
    typedef enum ezwHoleCalloutElement
    {
        ZW_HOLE_ELEMENT_INVALID           = 0x00000000, /**<@brief  all is not valid */
        ZW_HOLE_ELEMENT_QUALITY           = 0x00000001, /**<@brief  quality */
        ZW_HOLE_ELEMENT_DIAMETER          = 0x00000002, /**<@brief  diameter */
        ZW_HOLE_ELEMENT_DIAMETER_D2       = 0x00000004, /**<@brief  diameter(D2) */
        ZW_HOLE_ELEMENT_DEPTH             = 0x00000008, /**<@brief  depth */
        ZW_HOLE_ELEMENT_DEPTH_H2          = 0x00000010, /**<@brief  depth(H2) */
        ZW_HOLE_ELEMENT_THREAD_DIAMETER   = 0x00000020, /**<@brief  thread diameter */
        ZW_HOLE_ELEMENT_THREAD_PITCH      = 0x00000040, /**<@brief  thread pitch */
        ZW_HOLE_ELEMENT_THREAD_DEPTH      = 0x00000080, /**<@brief  thread depth */
        ZW_HOLE_ELEMENT_ANGLE             = 0x00000100, /**<@brief  angle */
        ZW_HOLE_ELEMENT_CALLOUT_LABEL     = 0x00000200, /**<@brief  callout label */
        ZW_HOLE_ELEMENT_MULTIPLE_LINES    = 0x00000400, /**<@brief  multiple lines */
        ZW_HOLE_ELEMENT_SLOT_LENGTH       = 0x00000800, /**<@brief  slot length */
        ZW_HOLE_ELEMENT_REVOLVE_DIRECTION = 0x00001000, /**<@brief  revolve direction */
        ZW_HOLE_ELEMENT_START_CHAMFER     = 0x00002000, /**<@brief  start chamfer */
        ZW_HOLE_ELEMENT_ALL               = 0xFFFFFFFF  /**<@brief  all is valid */
    } ezwHoleCalloutElement;
	
	/**
    @brief radial or diametric dimension type
    @ingroup ZwDimensionData
    */
    typedef enum ezwRadialDimensionType
    {
        ZW_RADIAL_RADIAL   = 1, /**<@brief  radial dimension */
        ZW_RADIAL_BROKEN   = 2, /**<@brief  broken radial dimension */
        ZW_RADIAL_LARGE    = 3, /**<@brief  large radial dimension */
        ZW_RADIAL_LEADER   = 4, /**<@brief  leader radial dimension */
        ZW_RADIAL_DIAMETER = 5, /**<@brief  diametric dimension */
        ZW_RADIAL_LINEAR   = 6  /**<@brief  linear diameter */
    } ezwRadialDimensionType;

    /**
    @brief radial or diametric dimension data
    @ingroup ZwDimensionData
    */
    typedef struct szwRadialDimensionData
    {
        ezwRadialDimensionType type; /**<@brief  radial or diametric type */

        szwPointOnEntity entity; /**<@brief  the entity you want to add dimension */

        szwPointOnEntity breakPoint; /**<@brief  break point.
                                 if type = ZW_RADIAL_BROKEN, the line through entity and the entity center will be cut at
                                 the intersection of above line and the line through breakPoint vertical to
                                 above line
                                 other type will be ignored */
        szwPointOnEntity textPoint;  /**<@brief  text point: specify the location the dimension text */
    } szwRadialDimensionData;

    /**
    @brief arc dimension data
    @ingroup ZwDimensionData
    */
    typedef struct szwDrawingArcDimensionData
    {
        szwPointOnEntity arcEntity; /**<@brief  arc entity */
        szwPointOnEntity textPoint; /**<@brief  text point : specify the location of the dimension text.*/
    } szwDrawingArcDimensionData;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_DIMENSION_DATA_H */
