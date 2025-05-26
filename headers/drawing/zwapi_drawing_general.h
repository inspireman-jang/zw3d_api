/**
@file zwapi_drawing_general.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D ENTITY API
*/

#pragma once
#ifndef ZW_API_DRAWING_GENERAL_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_GENERAL_H

#include "zwapi_drawing_general_data.h"
#include "zwapi_drawing_view_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Drawing Query */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingGeneral

    Gets handle data of parent view of specified geometry.

    @note
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] geometryHandle handle data of geometry in view
    @param [out] viewHandle handle data of parent view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingGeometryParentViewGet(szwEntityHandle geometryHandle, szwEntityHandle *viewHandle);


    //====================================================================================================================
    /** @name Drawing Hatch */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingGeneral

    Gets an array of associative boundary curves of given hatch entity.

    @note
    The caller is responsible to free the curveList by using ZwEntityHandleListFree.

    @param [in] hatchHandle handle data of hatch object
    @param [out] countCurve number of associative boundary curves
    @param [out]  curveList associative boundary curves

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwDrawingHatchAssociateCurveListGet(szwEntityHandle hatchHandle, int *countCurve, szwEntityHandle **curveList);
    
    /**
    @ingroup ZwDrawingGeneral

    Sets hatch attribute.

    @param [in] hatchHandle hatch handle data
    @param [in] hatchAttribute hatch attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingHatchAttributeSet(szwEntityHandle hatchHandle, szwCrossHatchData hatchAttribute);

    /**
    @ingroup ZwDrawingGeneral

    Gets hatch attribute.

    @param [in] hatchHandle hatch data
    @param [out] hatchAttribute hatch attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingHatchAttributeGet(szwEntityHandle hatchHandle, szwCrossHatchData *hatchAttribute);

    /**
    @ingroup ZwDrawingGeneral

    Sets attribute of the break line of the specified break line view.

    @see ZwDrawingBreakLineAttributeGet

    @param [in] breakLineHandle handle of the break line
    @param [in] data attribute of the break line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
    szwEntityHandle breakLineHandle = {};
    // some code to get the data of breakLineHandle
    ...

    szwBreakLineAttribute data = {};
    ezwErrors ret = ZwDrawingBreakLineAttributeGet(breakLineHandle, &data);
    ...
    ret = ZwDrawingBreakLineAttributeSet(breakLineHandle, &data);

    // free memory of handle
    ZwEntityHandleFree(&breakLineHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingBreakLineAttributeSet(szwEntityHandle breakLineHandle, szwBreakLineAttribute data);

    /**
    @ingroup ZwDrawingGeneral

    Gets attribute of the break line of the specified break line view.

    @see ZwDrawingBreakLineAttributeSet

    @param [in] breakLineHandle handle of the break line
    @param [out] data attribute of the break line

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

    @code
    szwEntityHandle breakLineHandle = {};
    // some code to get the data of breakLineHandle
    ...

    szwBreakLineAttribute data = {};
    ezwErrors ret = ZwDrawingBreakLineAttributeGet(breakLineHandle, &data);
    ...

    // free memory of handle
    ZwEntityHandleFree(&breakLineHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingBreakLineAttributeGet(szwEntityHandle breakLineHandle, szwBreakLineAttribute *data);

    /**
    @ingroup ZwDrawingGeneral

    Outputs the handle of the assembly component associated with the
    specified entity in a 2D drawing view layout from a 3D assembly.  

    Assumes that "entityHandle" resides in the active target file.  

    Outputs "compHandle->innerData = nullptr" if no assembly component is found.  

    Outputs the names of the component's parent file and object (i.e. part)
    if non-NULL pointers are input to the "char *" variables for "file" and
    "parent".

    @param [in] entityHandle entity handle
    @param [out] componentHandle component handle
    @param [in] nFileBytes string size of file name
    @param [out] file if not NULL, output name of component's parent file
    @param [in] nParentBytes string size of parent object name
    @param [out] parent if not NULL, output name of component's parent object


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOR_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle entityHandle=...;
    szwEntityHandle componentHandle{};
    zwString256 fileName={};
    zwString256 parentName={};
    int nFileBytes=sizeof(zwString256);
    int nParentBytes=sizeof(zwString256);
    ZwDrawingEntityComponentGet(entityHandle,&componentHandle, nFileBytes, file,nParentBytes, parent);
    ...
    //free the handle you get
    ZwEntityHandleFree(&componentHandle);

    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingEntityComponentGet(szwEntityHandle entityHandle, szwEntityHandle *componentHandle, int nFileBytes, char *file, int nParentBytes, char *parent);

    /**
    @ingroup ZwDrawingGeneral

    When the projection mode of drawing view is still discrete and you want to get some entities  
    for creating dimension directly, you can use this api to get discrete data handle to do that.  
    (there is no data generated in drawing view in this mode, you can't get entity from drawing view  
    by using ZwDrawingViewGeometryListGet())

    @note
    The caller is responsible to free the discreteEntityHandle by using ZwEntityHandleFree().  
    You need to use this api in drawing environment.  

    @param [in] drawingViewHandle drawing view handle
    @param [in] fileName name of 3d file
    @param [in] sketchHandle sketch handle in 3d environment, NULL if entityHandle is not from sketch
    @param [in] entityHandle entity handle in 3d environment which is projected to drawing
    @param [out] discreteEntityHandle discrete entity in drawing view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOR_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle drawingViewHandle=...;
    szwEntityHandle sketchHandle=...;
    szwEntityHandle entityHandle=...;

    szwEntityHandle discreteEntityHandle{};
    ZwDrawingDiscreteEntityGet(drawingViewHandle, &sketchHandle, entityHandle, &discreteEntityHandle);
    ...
    //free the handle you get
    ZwEntityHandleFree(&discreteEntityHandle);

    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingDiscreteEntityGet(szwEntityHandle drawingViewHandle, const zwPath fileName, const szwEntityHandle *sketchHandle, szwEntityHandle entityHandle, szwEntityHandle *discreteEntityHandle);

    //====================================================================================================================
    /** @name Drawing Regen */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingGeneral

    Regenerates layout views as well as any 2D tables and user embedded text associated with layout view.

    @param [in] count number of views (input 0 to regen all views)
    @param [in] viewList list of view handles (input NULL to regen all views)
    @param [in] regenUnmodifiedViews whether to force the regeneration of views whose referenced part models have not been modified (1: yes; 0: no)
    @param [in] regenTables whether to update BOM, hole and electrode tables (1: yes; 0: no)
    @param [in] promptViewRegen whether to display the the regenerate tips when the part is changed and goes into 2D sheet (1: yes; 0: no)
    @param [in] regenSketch whether to update standalone sketch (1: yes; 0: no)
    @param [in] regenAllSheets whether to update all sheets (1: yes; 0: no)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingRegen(int count, const szwEntityHandle *viewList, int regenUnmodifiedViews, int regenTables, int promptViewRegen, int regenSketch, int regenAllSheets);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_GENERAL_H */
