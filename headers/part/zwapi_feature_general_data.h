/**
@file zwapi_feature_general_data.h
@copyright (C) Copyright 2024, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the All
Commands of Sketch functions.
*/

#pragma once
#ifndef ZW_API_FEATURE_GENERAL_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_FEATURE_GENERAL_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Feature Shape Data */
    //====================================================================================================================

    /**
    @brief sweep Zaxis option
    @ingroup ZwFeatureGeneralData
    */
    typedef enum ezwSweepZOption
    {
        ZW_SWEEP_Z_TANGENT_TO_PATH  = 0, /**<@brief  tangent to path (default) */
        ZW_SWEEP_Z_TANGENT_TO_CURVE = 1, /**<@brief  tangent to curve */
        ZW_SWEEP_Z_FIXED_DIRECTION  = 2, /**<@brief  parallel with the fixed direction */
    } ezwSweepZOption;

    /**
    @brief sweep Xaxis option
    @ingroup ZwFeatureGeneralData
    */
    typedef enum ezwSweepXOption
    {
        ZW_SWEEP_X_MININUM_TWIST   = 0, /**<@brief  minimum twist (default)*/
        ZW_SWEEP_X_FIXED_DIRECTION = 1, /**<@brief  fixed direction */
        ZW_SWEEP_X_XAXIS_CURVE     = 2, /**<@brief  X-axis curve */
        ZW_SWEEP_X_FACE_NORMAL     = 3, /**<@brief  face normal */
    } ezwSweepXOption;

    /**
    @brief boolean combination method
    @ingroup ZwFeatureGeneralData
    */
    typedef enum ezwBoolType
    {
        ZW_BOOL_BASE      = 0, /**< @brief base */
        ZW_BOOL_ADD       = 1, /**< @brief add */
        ZW_BOOL_REMOVE    = 2, /**< @brief remove */
        ZW_BOOL_INTERSECT = 3  /**< @brief intersect */
    } ezwBoolType;

    /**
    @brief Move and Copy Methods
    @ingroup ZwFeatureGeneralData
    */
    typedef enum ezwMoveType
    {
        ZW_POINT_TO_POINT   = 1, /**<@brief  copy/move entities form point to point */
        ZW_ALONG_DIRECTION  = 2, /**<@brief  copy/move entities along a direction */
        ZW_ALIGN_FRAMES     = 3, /**<@brief  copy/move entities by aligning frames */
        ZW_SWEEP_ALONG_PATH = 4, /**<@brief  copy/move entities along path */
        ZW_AROUND_DIRECTION = 5, /**<@brief  rotate entities around a direction */
        ZW_DYNAMIC_MOVE     = 6, /**<@brief  dynamic copy/move entities */
    } ezwMoveType;

    /**
    @brief dynamic copy/move entities
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwDynamicMove
    {
        int moveHandOnly;  /**<@brief  move handle only(default 0)*/
        szwPoint position; /**<@brief  Position */
        szwVector xAxis;   /**<@brief  X Axis */
        szwVector yAxis;   /**<@brief  Y Axis */
        szwVector zAxis;   /**<@brief  Z Axis */
    } szwDynamicMove;

    /**
    @brief copy/move entities by aligning frames
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwAlignFrame
    {
        szwEntityHandle fromFrame; /**<@brief  from frame*/
        szwEntityHandle toFrame;   /**<@brief  to frames*/
    } szwAlignFrame;

    /**
    @brief copy/move entities form point to point
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwMovePointToPoint
    {
        szwPointOnEntity fromPoint; /**<@brief  from point */
        szwPointOnEntity toPoint;   /**<@brief  to point */
        /*modify the alignment while moving or copying*/
        szwDirection *fromVector; /**<@brief  from vector */
        szwDirection *toVector;   /**<@brief  to vector */
    } szwMovePointToPoint;

    /**
    @brief copy/move entities along a direction
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwAlongDirection
    {
        szwDirection direction; /**<@brief  direction */
        double distance;        /**<@brief  distance value */
        int unuseAngle;         /**<@brief  angle enable (default 0) */
        double angle;           /**<@brief  angle value */
    } szwAlongDirection;

    /**
    @brief rotate entities around a direction
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwAroundDirection
    {
        szwDirection direction;        /**<@brief  direction */
        szwPointOnEntity axisLocation; /**<@brief  axis location */
        double angle;                  /**<@brief  angle value */
    } szwAroundDirection;

    /**
    @brief copy/move entities along path
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwAlongPath
    {
        szwPointOnEntity path;       /**<@brief  path */
        szwPointOnEntity toPoint;    /**<@brief  to points */
        int frameOption;             /**<@brief  frame option(0-default frame, 1-at path, 2-selected) */
        szwEntityHandle frame;       /**<@brief  frame is selected( if frameOption = 2) */
        ezwSweepZOption zAxisOption; /**<@brief  Z Axis option*/
        szwPointOnEntity zAxisCurve; /**<@brief  entity data of z-axis (ignore when zAxisOption = ZW_SWEEP_Z_TANGENT_TO_PATH)
                               ZW_SWEEP_Z_TANGENT_TO_CURVE- curve(set parent if the curve from the sketch)
                               ZW_SWEEP_Z_FIXED_DIRECTION - use direction (just direction or direction from an curve/edge) */
        ezwSweepXOption xAxisOption; /**<@brief  X Axis option (exclude ZW_SWEEP_X_FACE_NORMAL) */
        szwPointOnEntity xAxisCurve; /**<@brief  entity data of x-axis (ignore when xAxisOption = ZW_SWEEP_X_MININUM_TWIST )
                               ZW_SWEEP_X_FIXED_DIRECTION- use direction (just direction or direction from an curve/edge) */
    } szwAlongPath;

    /**
    @brief template command Move data
    @ingroup ZwFeatureGeneralData
    */
    typedef struct szwMoveData
    {
        ezwMoveType method;    /**<@brief  move methods */
        int count;             /**<@brief  entity count */
        szwEntityHandle *list; /**<@brief  entities handles */
        union ezwMethodsUnion  /**<@brief union of move data */
        {
            szwDynamicMove dynamicMove;         /**<@brief  dynamic move */
            szwMovePointToPoint pointToPoint;   /**<@brief  point to point */
            szwAlongDirection alongDirection;   /**<@brief  along direction data*/
            szwAroundDirection aroundDirection; /**<@brief  around direction data*/
            szwAlignFrame alignFrame;           /**<@brief  copy entities by aligning frames */
            szwAlongPath sweep;                 /**<@brief  sweep along path */
        } methodUnion;
        double tolerance; /**<@brief  tolerance */
    } szwMoveData;


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FEATURE_GENERAL_DATA_H */
