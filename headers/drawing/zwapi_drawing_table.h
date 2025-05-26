/**
@file zwapi_drawing_table.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR ZW3D Drawing Table API
*/

#pragma once
#ifndef ZW_API_DRAWING_TABLE_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_TABLE_H

#include "zwapi_drawing_table_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Table Create */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingTable

    Initialize the drawing BOM data for ZwDrawingTableBOMCreate().

    @note
    Do not assign a value to variable "data" before calling the function, the ZwMemoryZero() is called inside the interface to empty everything.

    @see
    ZwDrawingTableBOMCreate

    @param [out] data drawing BOM data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingTableBOMInit(szwDrawingBOMData *data);

    /**
    @ingroup ZwDrawingTable

    Creates one a BOM table from a layout view including detail and section views and outputs the handles of new BOM.   
    Function Guide: Drawing -> Layout -> Table -> BOM

    @note  
    Interface ZwDrawingTableBOMInit() can initialize variable of the function.  
    The caller is responsible to free the BOMHandle by using ZwEntityHandleFree().

    @see
    ZwDrawingTableBOMInit

    @param [in] data drawing BOM data
    @param [out] BOMHandle new BOM handle (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
    // some code to init the data of BOM
    szwDrawingBOMData data = {};
    ezwErrors ret = ZwDrawingTableBOMInit(&data);
    ...

    // create BOM
    szwEntityHandle BOMHandle = {};
    ret = ZwDrawingTableBOMCreate(data, &BOMHandle);

    // some code to init the data
    szwTableInsertData tableInsertData = {};
    ...

    // insert BOM to the active sheet
    ret = ZwTableInsert(BOMHandle, tableInsertData);

    // free memory of handles
    ZwEntityHandleFree(&BOMHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingTableBOMCreate(szwDrawingBOMData data, szwEntityHandle *BOMHandle);

    /**
    @ingroup ZwDrawingTable

    Initialize the drawing Annotation Table data, with the default table format data being outputted, for ZwDrawingTableAnnotationCreate().  
    Function Guide: Drawing -> Layout -> Table -> Annotation

    @note
    No need to assign value for "data" before calling the function, since ZwMemoryZero() is called inside.  
    The default data of tableFormat.selectedList include the list of the whole optional names. If you just need some of them, please call ZwMemoryFree()  
    to free it first, since this function will alloc memory for it as long as the tableFormat.selectedCount > 0, and then call ZwApiMemAlloc() to realloc  
    memory and reset data for it, as long as the new size is not larger than that of the the original default. 

    @see ZwDrawingTableAnnotationCreate

    @param [in] type Annotation Table type
    @param [out] data Annotation Table data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingTableAnnotationInit(ezwDrawingTableType type, szwDrawingTableAnnotation *data);

    /**
    @ingroup ZwDrawingTableData

    Create an Annotation Table from a layout view, and output the table handle and the handle list of new created dimensions, respectively, if needed.  
    Function Guide: Drawing -> Layout -> Table -> Annotation

    @note
    Please use ZwDrawingTableAnnotationInit() to init the the drawing Annotation Table data as well as get the default table format data.  
    This function can only create a table object, without inserting it into the drawing, please use ZwTableInsert() if needed. 
    
    @see ZwDrawingTableAnnotationInit, ZwTableInsert

    @param [in] data Annotation Table data
    @param [out] table new table handle (input NULL to ignore)
    @param [out] annotationNumber number of new annotations (input NULL to ignore)
    @param [out] annotationList handle list of the new annotations (input NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_STRING
    -        ZW_API_MEMORY_ERROR

    @code
    // init the data of Annotation Table(include its table format data)
    szwDrawingTableAnnotation data = {};
    data.type = ZW_TABLE_DIMENSION ;
    ezwErrors ret = ZwDrawingTableAnnotationInit(data.type, &data);

    //data modify
    data.type = ZW_TABLE_DIMENSION;
    strcpy_s(data.name, "aaa");
    szwEntityHandle dims[2];

    //some code for getting each entity handle

    data.entityList = dims;
    data.number = 2;

    //assume that the default selectedList size is 3, but you just need the first an the third.
    zwString64 sel[2] = {};
    strcpy_s(sel[0], data.tableFormat.selectedList[0]);
    strcpy_s(sel[1], data.tableFormat.selectedList[2]);

    ZwMemoryFree((void**)&data.tableFormat.selectedList);
    data.tableFormat.selectedList = sel;
    data.tableFormat.selectedCount = 2;

    // create new Annotation Table
    szwEntityHandle table = 0, *annos = nullptr;
    int annoNum = 0;
    ret = ZwDrawingTableAnnotationCreate(data, &table, &annoNum, &annos);

    ZwEntityHandleListFree(annoNum, &annoList);
    // insert table to the active sheet if needed
    szwTableInsertData tableInsertData = {};

    //some code to set tableInsertData
     ....
    ret = ZwTableInsert(table, tableInsertData);
    ZwEntityHandleFree(&table);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingTableAnnotationCreate(szwDrawingTableAnnotation data, szwEntityHandle *table, int *annotationNumber, szwEntityHandle **annotationList);

    //====================================================================================================================
    /** @name Table Query */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingTable

    Gets the associated reference view of the specified BOM table.

    @note
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] BOMHandle handle of the BOM table
    @param [out] viewHandle handle of the reference view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingTableBOMReferenceViewGet(szwEntityHandle BOMHandle, szwEntityHandle *viewHandle);


    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_TABLE_H */
