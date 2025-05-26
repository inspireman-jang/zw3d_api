/**
@file zwapi_drawing_symbol.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Symbol API
*/

#pragma once
#ifndef ZW_API_DRAWING_SYMBOL_H
#define ZW_API_DRAWING_SYMBOL_H

#include "zwapi_drawing_symbol_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Symbol Create */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingSymbol

    Initializes the szwDrawingSymbolHoleMark structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwDrawingSymbolHoleMarkCreate

    @param [in] type  drawing sheet hole mark type
    @param [out] data drawing sheet hole mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingSymbolHoleMarkInit(ezwDrawingSymbolHoleMarkType type, szwDrawingSymbolHoleMark *data);
    
    /**
    @ingroup ZwDrawingSymbol

    Uses this function to mark holes in drawing sheet.  

    Function Guide: Drawing -> Dimension -> Symbol -> Hole Mark

    @note
    Interface ZwDrawingSymbolHoleMarkInit() can initialize variables hole mark
    of this function.  
    The caller is responsible to free the symbolList by using ZwEntityHandleListFree().

    @see ZwDrawingSymbolHoleMarkInit

    @param [in] data  data of hole mark
    @param [out] numberSymbol number of symbol in list (input NULL to ignore)
    @param [out] symbolList handle list of the symbol created (input NULL to ignore)

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
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingSymbolHoleMarkCreate(szwDrawingSymbolHoleMark data, int *numberSymbol, szwEntityHandle **symbolList);

    /**
    @ingroup ZwDrawingSymbol

    Creates an OLE object by embedding or linking an existing file to the active drawing sheet. The OLE object is displayed as an icon, click the icon to open and edit the object.  
    Function Guide: Drawing -> Dimension -> Symbol -> OLE Object

    @note
    The caller is responsible to free the symbolHandle by using ZwEntityHandleFree().

    @param [in] filePath the full path to the embedded or linked file, which must already exist
    @param [in] linkFlag link flag (0: embed file; 1: link file)
    @param [in] insertPoint the insertion point of the OLE object icon (NULL to insert into the left bottom corner of the sheet by default)
    @param [out] symbolHandle handle of new OLE object (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingSymbolOLEObjectCreate(const zwPath filePath, int linkFlag, const szwPoint2 *insertPoint, szwEntityHandle *symbolHandle);

    /**
    @ingroup ZwDrawingSymbol

    Inquires the data of an OLE object in drawing environment, the data contains the link flag the the file path of the OLE file.  

    @note
    This function will return ZW_API_OBJ_TYPE_ERROR if the input 'symbolHandle' is not an OLE symbol.

    @param [in] symbolHandle handle of new OLE object
    @param [out] linkFlag link flag (0: embed file; 1: link file)
    @param [in] size the size of filePath (0 to ignore)
    @param [out] filePath file path of the OLE object (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingSymbolOLEObjectDataGet(szwEntityHandle symbolHandle, int *linkFlag, int size, char *filePath);

    /**
    @ingroup ZwDrawingSymbol

    Exports an OLE symbol object to the specified path.  

    @note
    This function will return ZW_API_OBJ_TYPE_ERROR if the input 'symbolHandle' is not an OLE symbol.

    @warning
    This function can only exports the OLE symbol object with embed file, it will return ZW_API_OBJ_TYPE_ERROR if 
    with link file type.  
    The input filePath should use the same extension of the OLE symbol file, this function will export the file 
    by the extension of the OLE symbol file forcibly if the type is not correct.  
    This function DO NOT support to export the excel files now.  

    @see ZwDrawingSymbolOLEObjectDataGet

    @param [in] symbolHandle handle of new OLE object
    @param [in] filePath path to export the OLE

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingSymbolOLEObjectExport(szwEntityHandle symbolHandle, const char *filePath);

    /**
    @ingroup ZwDrawingSymbol

    Initializes the parameters of the szwSymbolWeldData.

    @see ZwDrawingSymbolWeldCreate

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @param [out] data weld symbol data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingSymbolWeldInit(szwSymbolWeldData *data);

    /**
    @ingroup ZwDrawingSymbol

    Creates a standard weld symbol with specified data.
    Function Guide: Drawing->Dimension->Symbol->Weld

    @see ZwDrawingSymbolWeldInit

    @note
    Interface ZwDrawingSymbolWeldInit() can initialize variables of this function.
    The caller is responsible to free the symbolWeld by using ZwEntityHandleFree().

    @see ZwDrawingSymbolWeldInit

    @param [in] data weld symbol data
    @param [out] symbolWeld handle of new symbol (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingSymbolWeldCreate(szwSymbolWeldData data, szwEntityHandle *symbolWeld);

    /**
    @ingroup ZwDrawingSymbol

    Frees memory associated with the specified weld structure.

    @see ZwDrawingSymbolWeldDataGet ZwDrawingSymbolWeldDataSet

    @param [in] data weld data structure

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwDrawingSymbolWeldFree(szwSymbolWeldData *data);

    /**
    @ingroup ZwDrawingSymbol

    Initializes the parameters of the ZwDrawingSymbolSurfaceFinishCreate().

    @see ZwDrawingSymbolSurfaceFinishCreate

    @param [out] data surface finish symbol data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingSymbolSurfaceFinishInit(szwDrawingSymbolSurfaceFinish *data);

    /**
    @ingroup ZwDrawingSymbol

    Creates a surface finish symbol with specified data.

    @note
    Interface ZwDrawingSymbolSurfaceFinishInit() can initialize variables of this function.

    @param [in] data surface finish symbol data
    @param [out] surfaceFinishHandle handle of new symbol (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingSymbolSurfaceFinishCreate(szwDrawingSymbolSurfaceFinish data, szwEntityHandle *surfaceFinishHandle);

    //====================================================================================================================
    /** @name Symbol Weld*/
    //====================================================================================================================
    /**
    @ingroup ZwDrawingSymbol

    Gets the weld data of the specified symbol.

    This function allocates memory for "jogPoints" and "leaderPoints"
    in szwSymbolWeldData struct. 
    @note
    The caller is responsible to free the data by using ZwDrawingSymbolWeldFree().

    @see ZwDrawingSymbolWeldFree ZwDrawingSymbolWeldDataSet

    @param [in] symbolWeld symbol handle
    @param [out] data weld data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingSymbolWeldDataGet(szwEntityHandle symbolWeld, szwSymbolWeldData *data);

    /**
    @ingroup ZwDrawingSymbol

    Sets the weld data of the specified symbol.

    @see ZwDrawingSymbolWeldFree ZwDrawingSymbolWeldDataGet

    @param [in] symbolWeld symbol handle
    @param [in] data weld data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingSymbolWeldDataSet(szwEntityHandle symbolWeld, szwSymbolWeldData data);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !ZW_API_DRAWING_SYMBOL_H */