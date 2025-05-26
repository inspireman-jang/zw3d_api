/**
@file zwapi_face.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D loop API
*/

#pragma once
#ifndef ZW_API_LOOP_H /* this ifndef surrounds entire header */
#define ZW_API_LOOP_H

#include "zwapi_geometry_surface_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Loop Query */
    //====================================================================================================================
    /**
    @ingroup ZwLoop

    Outputs a list of handle of the edges that belong to a loop on a face in the active file.  
    Edges are output in the order they occur in the loop. And outer loops proceed counterclockwise relative  
    to the natural normal of the parent surface.  Inner loops are clockwise relative to the natural surface normal.  
    Function Guide: Loop -> Edge

    @note  
    The caller is responsible to free the edges by using ZwEntityHandleListFree()

    @see ZwEntityHandleListFree

    @param [in] loop loop handle
    @param [out] count number of edges
    @param [out] edgeList list of edge handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwLoopEdgeListGet(szwEntityHandle loop, int *count, szwEntityHandle **edgeList);

    /**
    @ingroup ZwLoop

    Outputs a list of handles of the PreEdges that belong to a loop on a face in the active file.  
    PreEdges are output in the order they occur in the loop. Outer loops proceed counterclockwise  
    relative to the natural normal of the parent surface. Inner loops are clockwise relative to the  
    natural surface normal.  
    Function Guide: Loop -> PreEdge

    @note  
    The caller is responsible to free the edges by using ZwEntityHandleListFree()

    @see ZwEntityHandleListFree

    @param [in] loop loop handle
    @param [out] count number of edges
    @param [out] preEdgeList list of preEdge handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwLoopPreEdgeListGet(szwEntityHandle loop, int *count, szwEntityHandle **preEdgeList);

    /**
    @ingroup ZwLoop

    Determine whether a given loop is an inner loop or not.

    @param [in] loop loop handle
    @param [out] isInner inner loop flag (1=inner, 0=outer)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwLoopIsInner(szwEntityHandle loop, int *isInner);

    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LOOP_H */
#pragma once
