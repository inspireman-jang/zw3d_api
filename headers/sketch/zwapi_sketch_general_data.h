/**
@file zwapi_sketch_general_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Sketch
*/

#pragma once
#ifndef ZW_API_SKETCH_GENERAL_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_GENERAL_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Data */
    //====================================================================================================================
    /**
    @brief Sketch Create Redefine Up 
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchUpRedefine
    {
        ZW_USE_DEFAULT_DIRCTION       = 0, /**<@brief  use the default direction of the insertion plane */
        ZW_USE_SKETCH_XY_WORKING_LCS  = 1, /**<@brief  use Sketch XY refers to working LCS */
        ZW_USE_INPUT_DATA_REDEFINE_UP = 2, /**<@brief  use input data to redefine the Y-axis of sketch */
    } ezwSketchUpRedefine;

    /**
    @brief Sketch Create Redefine Origin 
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchOriginRedefine
    {
        ZW_USE_DEFAULT_ORIGIN             = 0, /**<@brief  Use the default origin of the insertion plane */
        ZW_USE_CENTROID                   = 1, /**<@brief  Use centroid of the insertion plane as the origin of sketch */
        ZW_USE_INPUT_DATA_REDEFINE_ORIGIN = 2, /**<@brief  Use input data to redefine the origin of sketch */
    } ezwSketchOriginRedefine;

    /**
    @brief sketch definition data
    @ingroup ZwSketchData
    */
    typedef struct szwSketchData
    {
        szwEntityHandle plane; /**<@brief  handle data of insertion to locate the sketch (datum plane,planar face,sketch) */


        /*  The following parameters are used to define the Y-axis direction of the sketch */
        ezwSketchUpRedefine isRedefineUpDirection; /**<@brief  whether to redefine Y-axis of sketch
                          (0: use the default direction of the insertion plane
                          1: use Sketch XY refers to working LCS) 
                          2: use input data to redefine the Y-axis of sketch, use "upData")  */

        struct SketchCreateUp
        {
            szwVector upDirection;     /**<@brief  direction of Y-axis, can be ignored if upEntity is not NULL */
            szwEntityHandle *upEntity; /**<@brief  specify the entity used to define the Y-axis, NULL to ignore (edge,curve,axis,datum plane) */
            int upParameter;           /**<@brief  specify direction of Y-axis
                          (0: use the positive direction of the edge or curve, or X-axis of datum plane
                          1: use the negative direction of the edge or curve, or Y-axis of datum plane) */
        } upData;

        /*  The following parameters are used to define the XY origin of the sketch */
        ezwSketchOriginRedefine isRedefineOrigin; /**<@brief  whether to redefine origin of sketch  
                          (0: use the default origin of the insertion plane  
                          1: use centroid of the insertion plane as the origin of sketch, calculate automatically  
                          2: use input data to redefine the origin of sketch) , use "originData" */
        struct SketchCreateOrigin
        {
            szwPoint origin;                        /**<@brief  origin of sketch, can be ignored if originEntity != NULL and use the critical point of entity */
            szwEntityHandle *originEntity;          /**<@brief  specify the parent entity where the origin locate, NULL to ignore (edge,curve,face,datum plane,point) */
            ezwGeometryCriticalPoint criticalPoint; /**<@brief  specify the critical point of edge or curve */
            int controlPoint;                       /**<@brief  id of the control point of the spline (starting from 0), only used when criticalPoint is ZW_SPLINE_DEFINING_POINT */
        } originData;

        int isReverseHorizontalDirection; /**<@brief  whether to reverse horizontal X-axis direction, default to be 0*/
        int isOrientTheActiveView;        /**<@brief  whether to orient the active view, default to be 0*/
        int isReferenceFaceEdges;         /**<@brief  whether to reference face edges, default to be 0*/
    } szwSketchData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_GENERAL_DATA_H */
