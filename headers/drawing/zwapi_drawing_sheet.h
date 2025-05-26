/**
@file zwapi_drawing_sheet.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR ZW3D Drawing Sheet API
*/

#pragma once
#ifndef ZW_API_DRAWING_SHEET_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_SHEET_H

#include "zwapi_dimension_data.h"
#include "zwapi_drawing_data.h"
#include "zwapi_drawing_view_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Sheet Activate*/
    //====================================================================================================================

    /**
    @ingroup ZwDrawingSheet

    Activates the special drawing sheet in the current open drawing file.

    @param [in] sheetName drawing sheet name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwDrawingSheetActivate(const zwString256 sheetName);

    /**
    @ingroup ZwDrawingSheet

    Activates the special drawing sheet in the current open drawing file.

    @note
    Inputs NULL can activate the first sheet in drawing.

    @param [in] sheetHandle drawing sheet handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingSheetActivateByHandle(const szwEntityHandle *sheetHandle);

    //====================================================================================================================
    /** @name Sheet Query */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingSheet

    Gets sheet list from drawing.

    @note
    The caller is responsible to free the sheetList by using ZwEntityHandleListFree().

    @param [out] count count of sheet handles in list
    @param [out] sheetList drawing sheet handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingSheetListGet(int *count, szwEntityHandle **sheetList);
    
    /**
    @ingroup ZwDrawingSheet

    Gets all dimensions in the specified drawing sheet, both visible and hidden.

    @note  
    The caller is responsible to free the dimensions by using ZwEntityHandleListFree().

    @see ZwEntityBlankGet

    @param [in] sheetHandle sheet handle (input NULL to query active sheet)
    @param [in] viewDimension whether to get dimensions associated to view (1: yes; 0: no)
    @param [in] dimensionTypeCount number of dimension types (input 0 to query all dimensions)
    @param [in] dimensionTypeList list of dimension types (input NULL to query all dimensions)
    @param [out] count number of dimensions
    @param [out] dimensions list of dimension handles 

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

    @code
    szwEntityHandle sheetHandle;
    // some code to get the data of sheetHandle
    ...

    int dimensionTypeCount = 3;
    ezwDimensionType dimensionTypeList[3] = { ZW_LINEAR_DIMENSION, ZW_LINEAR_OFFSET_DIMENSION, ZW_RADIAL_DIAMETRIC_DIMENSION };
    int count = 0;
    szwEntityHandle* dimensions = NULL;
    ezwErrors ret = ZwDrawingSheetDimensionListGet(&sheetHandle, 1, dimensionTypeCount, dimensionTypeList, &count, &dimensions);

    // free memory of handles
    ZwEntityHandleListFree(count, &dimensions);
    ZwEntityHandleFree(&sheetHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingSheetDimensionListGet(const szwEntityHandle *sheetHandle, int viewDimension, int dimensionTypeCount, const ezwDimensionType *dimensionTypeList, int *count, szwEntityHandle **dimensions);

    /**
    @ingroup ZwDrawingSheet
    Retrieve the view list in the specified sheet.

    @note
    The calling procedure MUST deallocate the output list with ZwEntityHandleListFree().

    @param [in] sheet entity handle of sheet, NULL to use the active one
    @param [in] type view type
    @param [out] count count of the view list
    @param [out] viewList view list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    int count = 0;
    szwEntityHandle *viewList = nullptr;
    ezwErrors ret = ZwDrawingSheetViewListGet(nullptr, ZW_DRAWING_ALL_VIEW, &count, &viewList);
    ...
    ZwEntityHandleListFree(count, &viewList);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingSheetViewListGet(const szwEntityHandle *sheet, ezwDrawingViewType type, int *count, szwEntityHandle **viewList);
    //====================================================================================================================
    /** @name Sheet State */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingSheet

    Check whether the views in the specified sheet have outdated and need to be updated,
    output 1 if one of the views need to be updated.

    @param [in] sheet the sheet in the active drawing
    @param [out] modified 1 if one of the views in specified drawing need to be updated, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR

    @code
    szwEntityHandle sheet;
    int modified = 0;
    ... // code to get the innerData of sheet
    ezwErrors ret = ZwDrawingSheetModifiedStateCheck(sheet, &modified);
    ...
    ZwEntityHandleFree(&sheet);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingSheetModifiedStateCheck(szwEntityHandle sheet, int *modified);

    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_SHEET_H */
