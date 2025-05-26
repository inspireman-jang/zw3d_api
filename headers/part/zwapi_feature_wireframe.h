/**
@file zwapi_feature_wireframe.h
@copyright (C) Copyright 2023, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Path API
*/

#pragma once
#ifndef ZW_API_FEATURE_WIREFRAME_H /* this ifndef surrounds entire header */
#define ZW_API_FEATURE_WIREFRAME_H

#include "zwapi_feature_wireframe_data.h"
#include "zwapi_face.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Curve */
    //====================================================================================================================
	/**
    @ingroup ZwFeatureWireframe

    Adds a 3D curve-list entity which groups the specified curves.
    Features like Sweep, Revolve and Extrude may be applied to 3D
    curve-lists as well as 2D sketches.  If "curveListEntity" is not NULL,
    the handle data of the new entity is output. 
    
    "curvelistEntity" is Parametric List.

    @note
    "curveList" and "curvelistEntity" are different.
    "curveList" is a list of several curves.
    "curvelistEntity" is that several curves formed an entity and output the 
    handle data of the entity.
    The caller is responsible to free the curvelistEntity by using ZwEntityHandleFree.

    @param [in] countCurve number of curves in curve-list
    @param [in] curveList pointer to list of 3D curve handle's
    @param [out] curvelistEntity handle data of new curve-list entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureCurvelistCreate(int countCurve, const szwEntityHandle *curveList, szwEntityHandle *curvelistEntity);

    
    /**
    @ingroup ZwFeatureWireframe

    Use this function to create silhouette curves.

    @note
    The caller is responsible to free the curves by using ZwEntityHandleListFree.

    @param [in] data silhouette curves data
    @param [out] count number of project curves (input nullptr to ignore)
    @param [out] curves list of project curve handles (input nullptr to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureSilhouetteCurves(szwSilhouetteCurvesData data, int *count, szwEntityHandle **curves);

    //====================================================================================================================
    /** @name Drawing */
    //====================================================================================================================

    /**
    @ingroup ZwFeatureWireframe

    Initializes the parameters of the szwLineData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @param [out] data template command line data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureLineDataInit(szwLineData *data);

    /**
    @ingroup ZwFeatureWireframe

    Adds a 3D line to the active part. If "handle" is not
    NULL, the handle of the new line entity is output.  
    Function Guide: Wireframe->Drawing->Line

    @note
    The caller is responsible to free the handle by using ZwEntityHandleFree().  
    Interface ZwFeatureLineDataInit() can initialize variables of this function.

    @param [in] data 3D line data
    @param [out] handle handle of new 3D line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureLineCreate(szwLineData data, szwEntityHandle *handle);

    /**
    @ingroup ZwFeatureWireframe

    Adds a 3D line to the active part.
    If "handle" is not NULL, the handle of the new line entity is output.  
    Function Guide: Wireframe->Drawing->Line

    @note
    The caller is responsible to free the handle by using ZwEntityHandleFree().

    @param [in] start start point
    @param [in] end end point
    @param [out] handle handle of new 3D line entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureLineCreateBy2Point(szwPoint start, szwPoint end, szwEntityHandle *handle);

    /**
    @ingroup ZwFeatureWireframe

    Adds a list 3D point entities to the active part.
    Function Guide: Wireframe->Drawing->Point

    @note
    The caller is responsible to free the handleList by using ZwEntityHandleListFree().

    @param [in] count number of points
    @param [in] points list of points position
    @param [out] handleList list of new points handles(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeaturePointsCreateByAbsolute(int count, const szwPoint *points, szwEntityHandle **handleList);

    //====================================================================================================================
    /** @name Spiral Helix */
    //====================================================================================================================
    /**
    @ingroup ZwFeatureWireframe

    Initialize the Spiral Helix data for ZwFeatureSpiralHelixCreate().  
    Function Guide: Wireframe -> Curve -> Spiral Helix

    @param [out] data Spiral Helix curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureSpiralHelixCreateInit(szwSpiralHelix *data);

    /**
    @ingroup ZwFeatureWireframe

    Create a Spiral Helix.  
    Function Guide: Wireframe -> Curve -> Spiral Helix

    @note
    The caller is responsible to free the Spiral by using ZwEntityHandleFree().  
    A path can be single-segment lines, arcs, free curves, or multiple lines.  
    And multiple lines must be continuous and tangential.  
    If the sizeRegulationType == ZW_SPIRALHELIX_REGULATIONTYPE_ACCORDING_LAWCURVE,  
    there are some rules as follows:  
        (1) Law curves must be consecutive curves;
        (2) Path or axis must be coplanar with lawCurves;  
        (3) Path must be straight line but bot bend curve in this case, even if there is only one path.

    @param [in] data Spiral Helix data
    @param [out] spiral new Spiral Helix entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureSpiralHelixCreate(szwSpiralHelix data, szwEntityHandle *spiral);

    /**
    @ingroup ZwFeatureWireframe

    Free memory associated with the specified Spiral Helix structure.  
    Free the memory of data->pathList if needed.  
    Free the memory of data->sizeRegulation.customer.sizeList if needed.  
    Free the memory of data->pitchRegulation.customer.sizeList if needed.  
    Function Guide: Wireframe -> Curve -> Spiral Helix

    @param [in] data Spiral Helix structure

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureSpiralHelixFree(szwSpiralHelix *data);

    /**********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FEATURE_WIREFRAME_H */
