/**
@file zwapi_edge.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D ENTITY API
*/

#pragma once
#ifndef ZW_API_EDGE_H /* this ifndef surrounds entire header */
#define ZW_API_EDGE_H

#include "zwapi_util.h"
#include "zwapi_edge_data.h"
#include "zwapi_curve_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Edge Query */
    //====================================================================================================================
    /**
    @ingroup ZwEdge

    Gets the type of specified edge.

    @param [in] edgeHandle edge handle data (in active file)
    @param [out] edgeType edge type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwEdgeTypeGet(szwEntityHandle edgeHandle, ezwEdgeType *edgeType);

    /**
    @ingroup ZwEdge

    Outputs a list of handles of the faces connected to an edge in the active file.

    @note
    The caller is responsible to free the faceHandle by using ZwEntityHandleListFree().

    @param [in] edgeHandle edge handle data
    @param [out] countFace number of faces
    @param [out] faceList list of face handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEdgeFaceListGet(szwEntityHandle edgeHandle, int *countFace, szwEntityHandle **faceList);

    /**
    @ingroup ZwEdge

    Outputs the edge's curve handle.

    @note
    The caller is responsible to free the edgeList by using ZwEntityHandleFree.
    You can pass "curveHandle" to the api like ZwCurveContinuityGet and ZwCurveLengthGet to get geometry data.

    @param [in] edgeHandle edge handle
    @param [out] curveHandle curve handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEdgeCurveGet(szwEntityHandle edgeHandle, szwEntityHandle *curveHandle);

    //====================================================================================================================
    /** @name Edge Data */
    //====================================================================================================================
    /**
    @ingroup ZwEdge

    Outputs the NURBS curve geometry of the specified edge in the active part.

    If "faceHandle == NULL", the 3D definition of the edge is output.

    If "faceHandle != NULL", the UV definition of the edge corresponding to the
    specified face or loop is output.

    The direction of UV curves output by this function follow the direction
    of their parent loops.  3D curves are not given a specific orientation.

    Outer loops proceed counterclockwise relative to the natural normal of
    the parent surface.  Inner loops are clockwise.

    It is assumed the specified edge (edgeHandle) resides in the active part.

    @note
    The caller is responsible to free the curve by using ZwCurveFree().

    @param [in] edgeHandle edge handle data
    @param [in] faceHandle optional face or loop handle for retrieving UV geometry (else NULL)
    @param [out] curve edge's curve geometry

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEdgeNURBSDataGet(szwEntityHandle edgeHandle, const szwEntityHandle *faceHandle, szwCurve *curve);

    /**
    @ingroup ZwEdge

    Gets the discrete data of all edges from specified face.

    @note
    The caller is responsible to free struct inside the discreteData by using ZwEdgeDiscreteDataFree,
    and free the discreteData by using ZwMemeoryFree.

    @see ZwEdgeDiscreteDataFree.

    @param [in] refineData refine data
    @param [out] number number of discrete data in list
    @param [out] discreteData discrete data list of all edges in active file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR

    @code
    // some code to init the refine data
    szwRefineFacets refineData = {};
    ...

    // get the discrete data
    int number = 0;
    szwEdgeDiscreteData *discreteData = nullprt;
    ezwErrors ret = ZwEdgeDiscreteDataGet(refineData, &number, &discreteData);

    // free memory of discrete data
    for (int i = 0; i < number; i++)
        ZwEdgeDiscreteDataFree(&discreteData[i]);
    ZwMemoryFree((void**)&edgeData);
    @endcode
    */
    ZW_API_C ezwErrors ZwEdgeDiscreteDataGet(szwRefineFacets refineData, int *number, szwEdgeDiscreteData **discreteData);

    /**
    @ingroup ZwEdge

    Free the discrete data of all edges from specified face.

    @param [out] data discrete data list of all edges in active file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEdgeDiscreteDataFree(szwEdgeDiscreteData *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_EDGE_H */
