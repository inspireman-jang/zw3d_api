/**
@file zwapi_feature_wireframe_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the wireframe feature
*/
#pragma once

#ifndef ZW_API_FEATURE_WIREFRAME_DATA_H
#define ZW_API_FEATURE_WIREFRAME_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief 3D line type
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezw3DLineType
    {
        ZW_LINE_2POINT          = 0, /**<@brief  create a line between two points */
        ZW_LINE_ALONG_DIRECTION = 1, /**<@brief  create a line in the same direction as the reference by start point and length */
        ZW_LINE_PARALLEL        = 2, /**<@brief  create a line parallel to the reference direction by point and length */
        ZW_LINE_PERPENDICULAR   = 3, /**<@brief  create a line between two points and perpendicular to the reference direction */
        ZW_LINE_ANGLE           = 4, /**<@brief  create a line between two points and at an angle to the reference direction */
        ZW_LINE_MIDDLE          = 5, /**<@brief  create a line by conforming the middle point and a end point */
    } ezw3DLineType;
    
    /**
    @brief 3D line data
    @ingroup ZwFeatureWireFrame
    */
    typedef struct szwLineData
    {
        ezw3DLineType lineType;             /**<@brief  type to create line */
        svxDirOnEntPath referenceDirection; /**<@brief  reference direction, used when type is ZW_LINE_ALONG_DIR, ZW_LINE_PARALLEL, ZW_LINE_PERPENDICULAR, ZW_LINE_ANGLE */
        szwPointOnEntity point1;            /**<@brief  start point or middle point */
        szwPointOnEntity point2;            /**<@brief  the end point, used when type is ZW_LINE_2POINT, ZW_LINE_PERPENDICULAR, ZW_LINE_ANGLE, ZW_LINE_MIDDLE */
        double length;                      /**<@brief  length of line, used when type is ZW_LINE_ALONG_DIR, ZW_LINE_PARALLEL */
        double offset;                      /**<@brief  offset distance from the reference direction, used when type is ZW_LINE_PARALLEL */
        double angle;                       /**<@brief  angle from the reference direction, used when type is ZW_LINE_ANGLE */
        szwEntityHandle alignPlane;         /**<@brief  handle of the alignment datum plane or planar face(innerData null to ignore), used when type is ZW_LINE_2POINT, ZW_LINE_MIDDLE */
        int projectToPlane;                 /**<@brief  whether to project line to alignment plane, used when type is ZW_LINE_2POINT, ZW_LINE_MIDDLE */
    } szwLineData;

    /**
    @brief silhouette curves method
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSilhouetteCurvesMethod
    {
        ZW_PROJECT_SILHOUETTE_CURVES_TO_PLANE,    /**<@brief  project silhouette curves to plane */
        ZW_CREATE_SILHOUETTE_CURVES_BY_DIRECTION, /**<@brief  create silhouette curves by direction */
    } ezwSilhouetteCurvesMethod;

    /**
    @brief silhouette curves type
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSilhouetteCurvesType
    {
        ZW_EXTERIOR_SILHOUETTE_CURVES, /**<@brief  exterior silhouette curves */
        ZW_INTERIOR_SILHOUETTE_CURVES, /**<@brief  interior silhouette curves */
        ZW_ALL_SILHOUETTE_CURVES,      /**<@brief  all silhouette curves */
    } ezwSilhouetteCurvesType;

    /**
    @brief feature silhouette curves data
    @ingroup ZwFeatureWireFrame
    */
    typedef struct szwSilhouetteCurvesData
    {
        ezwSilhouetteCurvesMethod method; /**<@brief  method of creating silhouette curves */
        ezwSilhouetteCurvesType type;     /**<@brief  type of silhouette curves to extract */

        int nEntities;                 /**<@brief  number of shapes or faces to extract silhouette curves */
        szwEntityHandle *entities;     /**<@brief  list of shapes or faces to extract silhouette curves */
        szwEntityHandle projectPlane;  /**<@brief  project plane, used when method = ZW_PROJECT_SILHOUETTE_CURVES_TO_PLANE */
        szwDirection projectDirection; /**<@brief  project direction, used when method = ZW_CREATE_SILHOUETTE_CURVES_BY_DIRECTION */
    } szwSilhouetteCurvesData;

    //====================================================================================================================
    /** @name Spiral Helix Data */
    //====================================================================================================================

    /**
    @brief option of radius type(decide whether the size is radius or diameter) 
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSpiralHelixRadiusType
    {
        ZW_SPIRALHELIX_RADIUS   = 0, /**<@brief by radius */
        ZW_SPIRALHELIX_DIAMETER = 1, /**<@brief by diameter */
    } ezwSpiralHelixRadiusType;

    /**
    @brief option of axis type 
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSpiralHelixAxisType
    {
        ZW_SPIRALHELIX_AXIS_VECTOR = 0, /**<@brief  the axis type is vector */
        ZW_SPIRALHELIX_AXIS_PATH   = 1, /**<@brief  the axis type is path, */
    } ezwSpiralHelixAxisType;

    /**
    @brief option of regulation type 
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSpiralHelixRegulationType
    {
        /*General regulation of radius and pitch*/
        ZW_SPIRALHELIX_REGULATIONTYPE_CONSTANT = 0, /**<@brief  the regulation type is constant, */
        ZW_SPIRALHELIX_REGULATIONTYPE_LINEAR,       /**<@brief  the regulation type is linear */
        ZW_SPIRALHELIX_REGULATIONTYPE_DEGREE2,      /**<@brief  the regulation type is degree 2 */
        ZW_SPIRALHELIX_REGULATIONTYPE_DEGREE3,      /**<@brief  the regulation type, is degree 3*/

        /*Customize regulation of radius and pitch with data list*/
        ZW_SPIRALHELIX_REGULATIONTYPE_CUSTOMLINEAR,  /**<@brief  the regulation type is customer linear*/
        ZW_SPIRALHELIX_REGULATIONTYPE_CUSTOMDEGREE3, /**<@brief  the regulation type is customer degree 3*/

        /*law curve*/
        ZW_SPIRALHELIX_REGULATIONTYPE_ACCORDING_LAWCURVE = 6, /**<@brief  the spiral axis type is according law curve*/
    } ezwSpiralHelixRegulationType;

    /**
    @brief option of size type 
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSpiralHelixSizeType
    {
        ZW_SPIRALHELIX_SIZETYPE_POINT      = 0, /**<@brief  the size is measured by point */
        ZW_SPIRALHELIX_SIZETYPE_DISTANCE   = 1, /**<@brief  the size is measured by distance */
        ZW_SPIRALHELIX_SIZETYPE_PERCENTAGE = 2, /**<@brief  the size is measured by percentage (can be chosen when axis type is by curve )*/
    } ezwSpiralHelixSizeType;

    /**
    @brief option of length type 
    @ingroup ZwFeatureWireFrame
    */
    typedef enum ezwSpiralHelixLengthType
    {
        ZW_SPIRALHELIX_LENGTHTYPE_HEIGHT_REVOLUTION = 0, /**<@brief  the length type is height and regulation */
        ZW_SPIRALHELIX_LENGTHTYPE_HEIGHT_PITCH      = 1, /**<@brief  the length type is height and pitch */
        ZW_SPIRALHELIX_LENGTHTYPE_REVOLUTION_PITCH  = 2, /**<@brief  the length type is pitch and regulation */
    } ezwSpiralHelixLengthType;

    /**
    @brief the interval for the Spiral Helix 
    @ingroup ZwFeatureWireFrame
    */
    typedef struct szwSpiralHelixInterval
    {
        double taper; /**<@brief  radius regulation taper, from -90  to 42.6141,
                       only used when radiusRegulationType == ZW_SPIRALHELIX_REGULATIONTYPE_LINEAR, otherwise, it is 0 as default*/
        double start; /**<@brief  the start of the Spiral Helix */
        double end;   /**<@brief  the end of the Spiral Helix, used when taper == 0*/
    } szwSpiralHelixInterval;

    /**
    @brief the size/pitch data for the Spiral Helix  
    (used when ezwSpiralHelixRegulationType >=ZW_SPIRALHELIX_REGULATIONTYPE_CUSTOMLINEAR)
    @ingroup ZwFeatureWireFrame
    */
    typedef struct szwSpiralHelixSize
    {
        ezwSpiralHelixSizeType sizeType; /**<@brief  size type */
        double percentage;               /**<@brief  percentage, from 0 to 100, used when sizeType == ZW_SPIRALHELIX_SIZETYPE_PERCENTAGE */
        szwPoint point;                  /**<@brief  point, used when sizeType == ZW_SPIRALHELIX_SIZETYPE_POINT */
        double distance;                 /**<@brief  distance, used when sizeType == ZW_SPIRALHELIX_SIZETYPE_DISTANCE */
        double size;                     /**<@brief  size number */
    } szwSpiralHelixSize;

    /**
    @brief the union data for the regulation data of size or pitch
    @ingroup ZwFeatureWireFrame
    */
    typedef union uzwSpiralHelixRegulationSize
    {
        double size;                      /**<@brief  size number when sizeRegulationType == ZW_SPIRALHELIX_REGULATIONTYPE_CONSTANT*/
        szwSpiralHelixInterval interval;  /**<@brief  size interval when sizeRegulationType from linear to degree3*/
        struct szwSpiralHelixSizeCustomer /**<@brief  customer size when sizeRegulationType is customer*/
        {
            int sizeCount;                /**<@brief  size/pitch count, used when regulation type is customized*/
            szwSpiralHelixSize *sizeList; /**<@brief  size/pitch list, used when sizeCount > 0*/
        } customer;

        struct szwSpiralHelixSizeLawCurve
        {
            int curveCount;             /**<@brief  the number of law curve handle, used when regulation type is law-curve*/
            szwEntityHandle *curveList; /**<@brief  law curve handle list, used when curveCount > 0 */
        } lawCurve;
    } uzwSpiralHelixRegulationSize;

    /**
    @brief the Spiral Helix data  (this structure can use ZwFeatureSpiralHelixFree to free)
    @ingroup ZwFeatureWireFrame 
    */
    typedef struct szwSpiralHelix
    {
        /*Required member*/
        ezwSpiralHelixAxisType axisType; /**<@brief  axis type */
        szwVector vector;                /**<@brief  spiral axis, it can be the coordinate axis, line or point , can not be {0,0,0}*/
        int pathCount;                   /**<@brief  number of spiral path, used when axisType == ZW_SPIRALHELIX_AXIS_PATH*/
        szwEntityHandle *pathList;       /**<@brief  spiral path, used when pathCount > 0 */
        szwPoint startPoint;             /**<@brief  the start point. It is invalid when sizeRegulationType is by lawCurve.*/
        double startAngle;               /**<@brief  the start angle */

        /*Size */
        int isDiameter;                                  /**<@brief  1:by diameter: 0 by radius*/
        ezwSpiralHelixRegulationType sizeRegulationType; /**<@brief  size regulation type */
        uzwSpiralHelixRegulationSize sizeRegulation;     /**<@brief  size regulation data */

        /*Length*/
        ezwSpiralHelixLengthType lenghthType;             /**<@brief  length type. ZW_SPIRALHELIX_LENGTHTYPE_REVOLUTION_PITCH cannot to be chosen when sizeRegulationType is by lawCurve.*/
        szwSpiralHelixInterval height;                    /**<@brief  height data. It is invalid when sizeRegulationType is by lawCurve. */
        ezwSpiralHelixRegulationType pitchRegulationType; /**<@brief  pitch regulation type */
        uzwSpiralHelixRegulationSize pitchRegulation;     /**<@brief  pitch regulation data */
        double revolution;                                /**<@brief  revolution */

        /*Settings */
        int clockwise;            /**<@brief  option for the resolve direction,1: clockwise, 0 -anti-clockwise.*/
        int curvatureCombDisplay; /**<@brief  option for if display the curvature comb, 1:display, 0: not display */
        double distanceTolerance; /**<@brief  distance tolerance(just for query) */
        double angleTolerance;    /**<@brief  angle tolerance(just for query) */
    } szwSpiralHelix;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_FEATURE_WIREFRAME_DATA_H */
