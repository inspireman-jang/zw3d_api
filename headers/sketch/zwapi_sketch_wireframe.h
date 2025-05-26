/**
@file zwapi_sketch_wireframe.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch Wireframe API
*/

#pragma once
#ifndef ZW_API_SKETCH_WIREFRAME_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_WIREFRAME_H

#include "zwapi_sketch_wireframe_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Wireframe */
    //====================================================================================================================
    /**
    @ingroup ZwSketchWireframe

    Initializes the variables of ZwSketchArcCreateByThreePoints().  
    Default to create an 2D Arc:  
    Start Point: (0,0)  
    End Point: (20,0)  
    Through : (10,10)  
    isG2Arc: 0  

    @param [out] data data to create a 2D arc by three points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwSketchArcCreateByThreePointsInit(szwSketchArcCreateByThreePoints *data);

    /**
    @ingroup ZwSketchWireframe

    Adds a 2D arc to the active sketch or sheet.   If "entity" is not
    NULL, the handle data of the new arc entity is output.

    Function Guide: Sketch->Sketch->Drawing->Arc

    @note
    Interface ZwSketchArcCreateByThreePointsInit() can initialize variables of this function.
    The caller is responsible to free the entity by using ZwEntityHandleFree().

    @param [in] data data to create a 2D arc by three points
    @param [out] entity entity handle of new 2D arc entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    ZW_API_C ezwErrors ZwSketchArcCreateByThreePoints(szwSketchArcCreateByThreePoints data, szwEntityHandle *entity);

    /**
    @ingroup ZwSketchWireframe

    Initializes the variables of ZwSketchCircleCreateByRadius().  
    Default to an 2D Circle: 
    Center Point: (0,0)  
    Radius: 20  

    @param [out] data data to create a 2D circle by radius

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwSketchCircleCreateByRadiusInit(szwSketchCircleCreateByRadius *data);

    /**
    @ingroup ZwSketchWireframe

    Adds a 2D circle to the active sketch or sheet by radius.   If "entity" is not
    NULL, the handle data of the new entity is output.

    Function Guide: Sketch->Sketch->Drawing->Circle

    @param [in] data  sketch circle create data By Radius
    @param [out] entity handle data of new 2D circle entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwSketchCircleCreateByRadius(szwSketchCircleCreateByRadius data, szwEntityHandle *entity);

    /**
    @ingroup ZwSketchWireframe

    Adds a 2D line to the active sketch.   
    If "lineHandle" is not NULL, the handle of the new line entity is output.

    Guide Function: Sketch->Sketch->Drawing->Line

    @note
    The caller is responsible to free the lineHandle by using ZwEntityHandleFree().

    @param [in] startPoint start point
    @param [in] endPoint end point
    @param [out] lineHandle handle data of new 2D line entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwSketchLineCreateBy2DPoints(szwPoint2 startPoint, szwPoint2 endPoint, szwEntityHandle *lineHandle);
    
    /**
    @ingroup ZwSketchWireframe

    Initializes the variable of ZwSketchReadyTextCreate().  

    @note
    Do not assign a value to variable "data" before calling the function, the ZwMemoryZero() is called inside the interface to empty everything.

    @param [in] method method to create ready text
    @param [out] data data to create ready text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwSketchReadyTextCreateInit(ezwReadyTextMethods method, szwReadyTextCreate *data);

    /**
    @ingroup ZwSketchWireframe

    Creates an exploded text in active sketch, that is great for designing text logos and other text that you want to use in design features.

    Function Guide: Sketch -> Sketch -> Drawing -> ReadySketch Text

    @note
    The caller is responsible to free the readyText by using ZwEntityHandleFree().

    @param [in] data data to create ready text
    @param [out] entityHandle handle of new ready text entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_STRING
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwSketchReadyTextCreate(szwReadyTextCreate data, szwEntityHandle *entityHandle);

    //====================================================================================================================
    /** @name ReadySketch Text */
    //====================================================================================================================
    /**
    @ingroup ZwSketchWireframe

    Frees memory associated with the specified ready sketch text structure.

    @param [in] readyText ready sketch text structure

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwReadyTextDataFree(szwReadyText *readyText);

    /**
    @ingroup ZwSketchWireframe

    Gets ready text data of the specified ready sketch text.

    @note
    The caller is responsible to free the readyText by using ZwReadyTextDataFree().

    @param [in] readyTextHandle handle of the ready sketch text
    @param [out] readyText data of ready sketch text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwSketchReadyTextDataGet(szwEntityHandle readyTextHandle, szwReadyText *readyText);  

    /**
    @ingroup ZwSketchWireframe

    Gets the outlines of the specified ready text entity, only ready text entity created with the in box method (ZW_BOX) have outlines.

    @note
    The caller is responsible to free the outlines by using ZwEntityHandleListFree().

    @param [in] readyTextHandle handle of the ready sketch text
    @param [out] count number of outlines
    @param [out] outlines list of entity handles for the outlines

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwSketchReadyTextOutlineListGet(szwEntityHandle readyTextHandle, int *count, szwEntityHandle **outlines);  
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_WIREFRAME_H */
