/**
@file zwapi_sketch_dimension_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures of the functions
of Sketch Dimension objects.
*/

#pragma once
#ifndef ZW_API_SKETCH_DIMENSION_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_DIMENSION_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Dimension Data */
    //====================================================================================================================
    
    /**
    @brief invalid dimension value
    @ingroup ZwSketchData
    */
#define zwInvalidDimensionValue 1.0e+20
    
    /**
    @brief type of sketch dimension
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchDimensionType
    {
        ZW_SKETCH_DIMENSION_UNKNOW = -1,   /**<@brief  undefined */
        ZW_SKETCH_DIMENSION_LINEAR,        /**<@brief  sketch linear dimension */
        ZW_SKETCH_DIMENSION_LINEAR_OFFSET, /**<@brief  sketch linear offset dimension */
        ZW_SKETCH_DIMENSION_ANGULAR,       /**<@brief  sketch angular dimension */
        ZW_SKETCH_DIMENSION_RADIAL,        /**<@brief  sketch radial/diametric dimension */
        ZW_SKETCH_DIMENSION_ARC_LENGTH,    /**<@brief  sketch arc length dimension */
        ZW_SKETCH_DIMENSION_SYMMETRY,      /**<@brief  sketch symmetry dimension */
        ZW_SKETCH_DIMENSION_PERIMETER,     /**<@brief  sketch perimeter dimension */
    } ezwSketchDimensionType;

    /**
    @brief type of sketch geometry critical point
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchDimensionPointType
    {
        ZW_SKETCH_DIMENSION_FREE_POINT,         /**<@brief  the free point on curve */
        ZW_SKETCH_DIMENSION_START_POINT,        /**<@brief  start point of curve */
        ZW_SKETCH_DIMENSION_END_POINT,          /**<@brief  end point of curve */
        ZW_SKETCH_DIMENSION_MIDDLE_POINT,       /**<@brief  middle point, entity must be line or arc */
        ZW_SKETCH_DIMENSION_ARC_CENTER,         /**<@brief  center of arc, entity must be an arc or circle */
        ZW_SKETCH_DIMENSION_ARC_PROXIMAL_POINT, /**<@brief  the minimum distance point or proximal tangent point of arc, entity must be an arc or circle */
        ZW_SKETCH_DIMENSION_ARC_DISTAL_POINT,   /**<@brief  the maximum distance point or distal tangent point of arc, entity must be an arc or circle */
        ZW_SKETCH_DIMENSION_SPLINE_POINT,       /**<@brief  the defining point of spline, entity must be a spline */
    } ezwSketchDimensionPointType;

    /**
    @brief data of sketch dimension point
    @ingroup ZwSketchData
    */
    typedef struct szwSketchDimensionPoint
    {
        szwEntityHandle entityHandle;          /**<@brief  entity handle to dimension to */
        ezwSketchDimensionPointType pointType; /**<@brief  type of dimension point */
        int definingPoint;                     /**<@brief  the index number of the defining point of the spline (starting from 0), if pointType = ZW_SKETCH_DIMENSION_SPLINE_POINT */
        szwPoint2 freePoint;                   /**<@brief  the free point coordinate, if pointType = ZW_SKETCH_DIMENSION_FREE_POINT */
    } szwSketchDimensionPoint;

    /**
    @brief type of sketch linear dimension
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchLinearDimensionType
    {
        ZW_SKETCH_LINEAR_HORIZONTAL = 1, /**<@brief  sketch linear horizontal dimension */
        ZW_SKETCH_LINEAR_VERTICAL,       /**<@brief  sketch linear vertical dimension */
        ZW_SKETCH_LINEAR_ALIGNED,        /**<@brief  sketch linear aligned dimension */
    } ezwSketchLinearDimensionType;

    /**
    @brief type of sketch linear offset dimension
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchLinearOffsetDimensionType
    {
        ZW_SKETCH_LINEAR_OFFSET = 1,  /**<@brief  sketch linear offset dimension */
        ZW_SKETCH_PROJECTED_DISTANCE, /**<@brief  sketch projected distance dimension */
    } ezwSketchLinearOffsetDimensionType;

    /**
    @brief type of sketch angular dimension
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchAngularDimensionType
    {
        ZW_SKETCH_TWO_CURVE_ANGULAR = 1,    /**<@brief  sketch 2 curves angular dimension */
        ZW_SKETCH_CURVE_HORIZONTAL_ANGULAR, /**<@brief  sketch curve horizontal angular dimension */
        ZW_SKETCH_CURVE_VERTICAL_ANGULAR,   /**<@brief  sketch curve vertical angular dimension */
        ZW_SKETCH_THREE_POINT_ANGULAR,      /**<@brief  sketch 3 points angular dimension */
        ZW_SKETCH_ARC_ANGULAR,              /**<@brief  sketch arc angular dimension */
    } ezwSketchAngularDimensionType;

    /**
    @brief type of sketch radial/diametric dimension
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchRadialDimensionType
    {
        ZW_SKETCH_RADIAL_DIMENSION = 1, /**<@brief  sketch radial dimension */
        ZW_SKETCH_DIAMETRIC_DIMENSION,  /**<@brief  sketch diametric dimension */
    } ezwSketchRadialDimensionType;

    /**
    @brief type of sketch symmetry dimension
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchSymmetryDimensionType
    {
        ZW_SKETCH_LINEAR_SYMMETRY = 1, /**<@brief  sketch linear symmetry dimension */
        ZW_SKETCH_ANGULAR_SYMMETRY,    /**<@brief  sketch angular symmetry dimension */
    } ezwSketchSymmetryDimensionType;

    /**
    @brief image data
    @ingroup ZwSketchData
    */
    typedef struct szwSymbolImage
    {
        /*  required inputs */
        zwPath path;         /**<@brief  image path or user define string */
        int firstPointType;  /**<@brief  type of 1st input point (0 corner, 1 center) */
        szwPoint2 points[2]; /**<@brief  2 input points depend on "firstPointType" */
        int width;           /**<@brief  width */
        int height;          /**<@brief  height */
        double angle;        /**<@brief  rotation angle(degree) */
        int opaque;          /**<@brief  opaque factor */
        int flip;            /**<@brief  flip flag (0-none, 1-with x, 2-with y ) */
        int lock;            /**<@brief  1-lock aspect ratio,0 not */
    } szwSymbolImage;

    /**
    @brief data of perimeter dimension
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct szwPerimeterDimensionData
    {
        int countCurve;                     /**<@brief count of curveList */
        szwSketchDimensionPoint *curveList; /**<@brief list of curve list */
        szwPoint2 textPoint;                /**<@brief text point */
        int variant;                        /**<@brief 0 is auto,the system will atutomatically modify the selected curves' length according to the perimeter. 
                         1 is manual,the perimeter is defined by moved curve field.user can modify the length of the selected 
                         curve to define the perimeter. */
        szwEntityHandle variantCurveHandle; /**<@brief variant curve handle.apply it if variant = 1. */
    } szwPerimeterDimensionData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_DIMENSION_DATA_H */
