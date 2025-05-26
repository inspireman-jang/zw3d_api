/**
@file zwapi_drawing_wireframe.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR ZW3D Drawing Wireframe API
*/

#pragma once
#ifndef ZW_API_DRAWING_WIREFRAME_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_WIREFRAME_H

#include "zwapi_drawing_wireframe_data.h"
#include "zwapi_drawing_general_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing*/
    //====================================================================================================================

    /**
    @ingroup ZwDrawingWireframe
    
    Initialize the parameters of the szwCrossHatchData.
    
    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwDrawingCrossHatchCreate
    
    @param [out] data hatch attributes(drawing)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingCrossHatchInit(szwCrossHatchData *data);

    /**
    @ingroup ZwDrawingWireframe

    Creates a hatch pattern within a boundary.
    Function Guide: Drawing->Drawing->Drawing->Cross Hatch

    @note
    Interface ZwDrawingCrossHatchInit() initializes the szwCrossHatchData structure.

    @see ZwDrawingCrossHatchInit

    @param [in] entityCount count of "entityList"
    @param [in] entityList list of entity handle
    @param [in] insideCount count of "insideList"
    @param [in] insideList list of inside point
    @param [in] isSplit 1 if split boundary ,else 0
    @param [in] data hatch data
    @param [out] hatch handle of hatch (NULL to ignore).

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwCrossHatchData data{};
    //init the parameters of the szwCrossHatchData.
    ZwDrawingCrossHatchInit(&data);
    int entityCount=...;
    //the entities that you want to add hatch.
    szwEntityHandle*entityList=...;//remember to free the memory if you alloc.

    int insideCount=...;
    //the points to mark areas that you want to add hatch.
    szwPoint2*insideList=...;//remember to free the memory if you alloc.

    //split boundary
    int isSplit=...;

    //new hatch handle
    szwEntityHandle hatch=...;
    ...
    ZwDrawingCrossHatchCreate(entityCount,entityList,insideCount,insideList,isSplit,data,&hatch);

    //if hatch is not NULL, free the handle
    ZwEntityHandleFree(&hatch);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingCrossHatchCreate(int entityCount, const szwEntityHandle *entityList, int insideCount, const szwPoint2 *insideList, int isSplit, szwCrossHatchData data, szwEntityHandle *hatch);

    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_WIREFRAME_H */
