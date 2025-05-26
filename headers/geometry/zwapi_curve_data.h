/**
@file zwapi_curve_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures
*/

#pragma once
#ifndef ZW_API_CURVE_DATA_H
#define ZW_API_CURVE_DATA_H

#include "zwapi_util.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    /**
    @brief data of curve continuity.
    @ingroup ZwCurveData
    */
    typedef struct szwCurveContinuityData
    {
        szwEntityHandle curve1;    /**<@brief id of curve1 */
        szwEntityHandle curve2;    /**<@brief id of curve2 */
        double position;           /**<@brief Check this variable to inquire the continuity of G0 position between the picked curves. */
        int isPositionContinuous;  /**<@brief 1 is continuous position, else 0. */
        double tangent;            /**<@brief Check this variable to inquire the continuity of G1 tangent between the picked curves. */
        int isTangentContinuous;   /**<@brief 1 is continuous tangent, else 0. */
        double curvature;          /**<@brief Check this variable to inquire the continuity of G2 curvature between the picked curves. */
        int isCurvatureContinuous; /**<@brief 1 is continuous curvature, else 0. */
        double flow;               /**<@brief Check this variable to inquire the continuity of G3 flow between the picked curves. */
        int isFlowContinuous;      /**<@brief 1 is continuous flow, else 0. */
    } szwCurveContinuityData;

    /**
    @brief curve continuity tolerance list
    @ingroup ZwCurveData
    */
    typedef enum ezwCurveChainType
    {
        ZW_CURVE_TANGENT_EDGE        = 0, /**<@brief find continuously tangent edges that may be bound by any number of faces */
        ZW_CURVE_CONNECTED_OPEN_EDGE = 1, /**<@brief find connected open edges */
        ZW_CURVE_SHARED_EDGE         = 2, /**<@brief find continuously tangent manifold edges that are shared by exactly two
                                             faces or are seams having the same face on both sides */
    } ezwCurveChainType;

    /**
    @brief level of evaluation(0 ~ 3)
    @ingroup ZwCurveData
    */
    typedef enum ezwCurveEvaluationLevel
    {
        ZW_CURVE_EVALUATION_LEVEL_0 = 0, /**<@brief level 0 */
        ZW_CURVE_EVALUATION_LEVEL_1 = 1, /**<@brief level 1 */
        ZW_CURVE_EVALUATION_LEVEL_2 = 2, /**<@brief level 2 */
        ZW_CURVE_EVALUATION_LEVEL_3 = 3  /**<@brief level 3 */
    } ezwCurveEvaluationLevel;

    /**
    @brief curve continuity tolerance list
    @ingroup ZwCurveData
    */
    typedef struct szwCurveContinuityToleranceList
    {
        double tolerancePosition;  /**<@brief tolerance of position.default:0.01
                            Judge whether the two curves are G0 continuous tolerance.(in millimeters). */
        double toleranceTangent;   /**<@brief tolerance of tangent.default:0.5
                            Judge whether the two curves are G2 continuous tolerance.(degrees). */
        double toleranceCurvature; /**<@brief 1tolerance of curvature.default:0.05
                            Judge whether the two curves are G2 continuous tolerance. */
        double toleranceFlow;      /**<@brief tolerance of flew.default:0.05
                            Judge whether the two curves are G3 continuous tolerance. */
    } szwCurveContinuityToleranceList;

    /**
    @brief nurbs parameter space data
    @ingroup ZwCurveData
    */
    typedef struct szwNurbsParameter
    {
        int closed;        /**<@brief  1=closed curve, 0=open curve */
        int degree;        /**<@brief  degree (order = deg + 1) */
        int numberKnots;   /**<@brief  number of knots */
        szwLimit boundary; /**<@brief  boundaries of parameter space */
        double *knots;     /**<@brief  array of knot values */
        int freeMemory;    /**<@brief  1 if memory referenced by "knots" should
                            ** be free'd by ZwCurveFree() or ZwSurfaceDataFree()
                            */
    } szwNurbsParameter;

    /**
    @brief nurbs control point data
    @ingroup ZwCurveData
    */
    typedef struct szwNurbsControlPoint
    {
        int rational;                   /**<@brief  1=RATIONAL, 0=NONRATIONAL control points  */
        int numberCoordinate;           /**<@brief  number of coordinates per control point (1-4) */
        int plane;                      /**<@brief  cp hyper plane type: 1:pnt, 2:line, 3:plane  */
        int numberControlPoint;         /**<@brief  number of control points in list */
        szwBoundingBox boundingBox;     /**<@brief  bounding box of control points */
        double *controlPointCoordinate; /**<@brief  control point coordinates  (possibly weighted) */
                                        /**<@brief  if RATIONAL, points are of form (wx,wy,wz,w) */
        int freeMemory;                 /**<@brief  1 if memory referenced by "coord" should
                                         ** be free'd by ZwCurveFree() or ZwSurfaceDataFree()
                                         */
    } szwNurbsControlPoint;

    /**
    @brief 2D or 3D curvilinear geometry
    @ingroup ZwCurveData
    */
    typedef struct szwCurve
    {
        ezwCurveType type; /**<@brief  curve type */
        szwMatrix frame;   /**<@brief  local frame (origin is center of 3D circle/arc) */

        union szwCurveInformation
        {
            struct szwCurveLine
            {
                szwPoint startPoint; /**<@brief  line start points*/
                szwPoint endPoint;   /**<@brief  line end points*/
            } line;
            struct szwCurveArc
            {
                double radius;               /**<@brief  circle/arc radius */
                szwPoint startPoint;         /**<@brief  line start points*/
                szwPoint endPoint;           /**<@brief  line end points*/
                double startAngle, endAngle; /**<@brief  arc start/end angles (degrees) */
                szwPoint centerPoint;        /**<@brief   center point */
            } arc;

            struct szwCurveCircle
            {
                double radius;        /**<@brief  circle/arc radius */
                szwPoint centerPoint; /**<@brief  center point*/
                szwVector normal;     /**<@brief  plane normal*/
            } circle;
            struct szwCurveEllipse2
            {
                double radius;        /**<@brief  circle/arc radius */
                szwPoint centerPoint; /**<@brief  center point*/
                szwPoint startPoint;  /**<@brief  line start points*/
                szwPoint endPoint;    /**<@brief  line end points*/

                double majorAxis;             /**<@brief  the radius of the major axis */
                double minorAxis;             /**<@brief  the radius of the minor axis */
                double startAngle;            /**<@brief  start angle (degrees) */
                double endAngle;              /**<@brief  end angle (degrees) */
                szwVector majorAxisDirection; /**<@brief  major axis unit direction vector (local x axis) */
            } ellipse2;
            struct szwCurveNURB
            {
                szwPoint startPoint;    /**<@brief  line start points*/
                szwPoint endPoint;      /**<@brief  line end points*/
                szwVector startTangent; /**<@brief  line start tangent*/
                szwVector endTangent;   /**<@brief  line end tangent*/
            } nurb;


        } curveInformation;

        szwNurbsParameter parameter;       /**<@brief  NURB parameter space data */
        szwNurbsControlPoint controlPoint; /**<@brief  NURB control point data (mm) */
    } szwCurve;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_GEOMETRY_CURVE_DATA_H */
