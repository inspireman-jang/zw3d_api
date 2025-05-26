/**
@file zwapi_sketch_general.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch API
*/

#pragma once
#ifndef ZW_API_SKETCH_GENERAL_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_GENERAL_H

#include "zwapi_sketch_general_data.h"
#include "zwapi_matrix_data.h"
#include "zwapi_sketch_wireframe.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Get */
    //====================================================================================================================
    /**
    @ingroup ZwSketchGeneral

    Outputs a list of database id's of sketches in the active part's history in the order they are
    listed there.If there are no sketches, "*countSketch" is output as zero and "*sketchList" as NULL.

    @note
    The caller is responsible to free the "sketchList" by using ZwEntityHandleListFree.

    @param [out] countSketch number of sketches in the active part
    @param [out] sketchList list of id's of sketches in the active part history

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    @code
        int countSketch = -1;
        szwEntityHandle *sketchList = nullptr;
        ...
        ZwSketchListGet(&countSketch,&sketchList);
        ...
        ZwEntityHandleListFree(countSketch,&sketchList);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchListGet(int *countSketch, szwEntityHandle **sketchList);

    //====================================================================================================================
    /** @name Sketch Create */
    //====================================================================================================================
    /**
    @ingroup ZwSketchGeneral

    Adds a new sketch to the active part, aligned with the
    specified insertion plane.  The sketch is activated for
    editing.

    Exit the sketch edit mode (back to edit the
    parent part) using ZwSketchActivate().
    If "sketchHandle" is not NULL, the handle of the new sketch is
    output.

    Function Guide: shape->Sketch

    @note
    The caller is responsible to free the sketch by using ZwEntityHandleFree().

    @param [in] matrix sketch insertion plane
    @param [out] sketchHandle handle data of new sketch (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwSketchCreateByMatrix(szwMatrix matrix, szwEntityHandle *sketchHandle);

    /**
    @ingroup ZwSketchGeneral

    Initialize variables of ZwSketchCreateByData().

    @param [out] sketchData sketch data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwSketchCreateByDataInit(szwSketchData *sketchData);

    /**
    @ingroup ZwSketchGeneral

    Adds a new sketch to the active part, aligned with the
    specified insertion plane.  The sketch is activated for
    editing.

    Exit the sketch edit mode (back to editing the
    parent part) using ZwSketchActivate().
    If "sketch" is not NULL, the handle data of the new sketch is
    output.

    Function Guide: Shape->Sketch

    @note
    Interface ZwSketchCreateByDataInit() can initialize variables of this function.
    The caller is responsible to free the sketch by using ZwEntityHandleFree().

    @param [in] sketchData sketch input data
    @param [out] sketch handle of new sketch (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwSketchCreateByData(szwSketchData sketchData, szwEntityHandle *sketch);

    //====================================================================================================================
    /** @name Sketch Activate */
    //====================================================================================================================
    /**
    @ingroup ZwSketchGeneral

    Activates the specified sketch for query or editing.

    Call this function with "sketchHandle == NULL" to exit the
    sketch back to its parent object.

    @param [in] sketchHandle handle data of sketch in active file (NULL to exit active sketch)
    @param [in] updateGUI 1 to update GUI; 0 to leave GUI unchanged

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    ZW_API_C ezwErrors ZwSketchActivate(const szwEntityHandle *sketchHandle, int updateGUI);

    /**
    @ingroup ZwSketchGeneral

    Quits the current sketch without saving changes in sketch.  
    Function Guide: Sketch->Cancel

    @note
    This API won't modify current file.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwSketchCancel();

    //====================================================================================================================
    /** @name Sketch Qurey */
    //====================================================================================================================
    /**
    @ingroup ZwSketchGeneral

    Outputs a list of indices of geometry entities in current active sketch.

    @note
    The caller is responsible to free the geometryList by using ZwEntityHandleListFree().

    @param [in] sketchHandle handle of sketch,NULL to the current active sketch
    @param [out] countGeometry number of geometry entities
    @param [out] geometryList list of geometry entity handle's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwSketch2DCurveListGet(const szwEntityHandle *sketchHandle, int *countGeometry, szwEntityHandle **geometryList); 

    /**
    @ingroup ZwSketchGeneral

    Outputs a list of handle data of text entities in the active sketch.
    It can get all the text in the sketch.

    @note
    The caller is responsible to free the textHandles by using ZwEntityHandleListFree().

    @param [in] sketchHandle handle of sketch,NULL to the current active sketch
    @param [out] textCount number of text entities
    @param [out] textHandles list of text entity handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwSketchTextListGet(const szwEntityHandle *sketchHandle, int *textCount, szwEntityHandle **textHandles);

    /**
    @ingroup ZwSketchGeneral

    Gets the tables in the specified sketch.

    @note
    The caller is responsible to free the tableList by using ZwEntityHandleListFree().

    @param [in] sketchHandle sketch handle (input NULL to query active sketch)
    @param [out] count count number of tables
    @param [out] tableList list of table handles 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwSketchGeneralTableListGet(const szwEntityHandle *sketchHandle, int *count, szwEntityHandle **tableList);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_H */
