/**
@file zwapi_table.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Table API  
*/


#pragma once
#ifndef ZW_API_TABLE_H /* this ifndef surrounds entire header */
#define ZW_API_TABLE_H

#include "zwapi_table_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Table Create and Insert */
    //====================================================================================================================
    /**
    @ingroup ZwTable

    Create a user table by specifying the number of rows and columns in the table in active part or drawing environment.

    @see ZwTableInsert

    @param [in] name the table name
    @param [in] rows the number of rows in the table
    @param [in] columns the number of columns in the table
    @param [out] table handle of the new table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OUT_OF_RANGE

    @code
    // create table
    szwEntityHandle table = {};
    ezwErrors ret = ZwUserTableCreateByRowAndColumn("UserTable1", 3, 3, &table);

    // insert table
    szwTableInsertData insertData = {};
    ...
    ret = ZwTableInsert(table, insertData);

    // free memory
    ZwEntityHandleFree(&table);
    @endcode
    */
    ZW_API_C ezwErrors ZwUserTableCreateByRowAndColumn(const zwString32 name, int rows, int columns, szwEntityHandle *table);

    /**
    @ingroup ZwTable

    Create a user table using the specified template in active drawing environment.

    @see ZwTableInsert

    @param [in] name the table name
    @param [in] templatePath the full path of the template file
    @param [out] table handle of the new table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OUT_OF_RANGE

    @code
    // create table
    szwEntityHandle table = {};
    zwPath templatePath = "";
    ...
    ezwErrors ret = ZwUserTableCreateByTemplate("UserTable1", templatePath, &table);

    // insert table
    szwTableInsertData insertData = {};
    ...
    ret = ZwTableInsert(table, insertData);

    // free memory
    ZwEntityHandleFree(&table);
    @endcode
    */
    ZW_API_C ezwErrors ZwUserTableCreateByTemplate(const zwString32 name, const zwPath templatePath, szwEntityHandle *table);

    /**
    @ingroup ZwTable

    Insert the specified table to active environment.

    @see ZwUserTableCreateByRowAndColumn
    @see ZwUserTableCreateByTemplate

    @param [in] table handle of the table to insert
    @param [in] data the table insert data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwTableInsert(szwEntityHandle table, szwTableInsertData data);

    //====================================================================================================================
    /** @name Table Edit */
    //====================================================================================================================
    /**
    @ingroup ZwTable

    Gets the number of rows for the specified table.

    @see ZwTableRowInsert
    @see ZwTableRowDelete

    @param [in] table handle of the table
    @param [out] count the number of rows in the table

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
    */
    ZW_API_C ezwErrors ZwTableRowCountGet(szwEntityHandle table, int *count);
    
    /**
    @ingroup ZwTable

    Gets the number of columns for the specified table.

    @see ZwTableColumnInsert
    @see ZwTableColumnDelete

    @param [in] table handle of the table
    @param [out] count the number of columns in the table

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
    */
    ZW_API_C ezwErrors ZwTableColumnCountGet(szwEntityHandle table, int *count);
        
    /**
    @ingroup ZwTable

    Inserts an empty row into the table at the specified row.

    @note
    Row is not allowed to be inserted before header row.

    @see ZwTableRowCountGet
    @see ZwTableRowDelete

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwTableRowInsert(szwEntityHandle table, int row);

    /**
    @ingroup ZwTable

    Inserts an empty column into the table at the specified column.

    @see ZwTableColumnCountGet
    @see ZwTableColumnDelete

    @param [in] table handle of the table
    @param [in] column row number (starting from 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwTableColumnInsert(szwEntityHandle table, int column);

    /**
    @ingroup ZwTable

    Removes the specified row from the table.

    @note
    1. The header row can not be deleted.
    2. The only visible non-header row can not be deleted.

    @see ZwTableRowCountGet
    @see ZwTableRowInsert

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwTableRowDelete(szwEntityHandle table, int row);

    /**
    @ingroup ZwTable

    Removes the specified column from the table.

    @note
    The only visible column can not be deleted.

    @see ZwTableColumnCountGet
    @see ZwTableColumnInsert

    @param [in] table handle of the table
    @param [in] column column number (starting from 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwTableColumnDelete(szwEntityHandle table, int column);

    /**
    @ingroup ZwTable

    Gets text of the specified cell in the table.

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)
    @param [in] column column number (starting from 0)
    @param [out] text cell text
    @param [in] size string max size of cell text

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
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle table = {};
    // some code to get the data of table handle
    ...

    zwString256 text = "";
    ezwErrors ret = ZwTableCellTextGet(table, 0, 0, text, sizeof(text));
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwTableCellTextGet(szwEntityHandle table, int row, int column, char *text, int size);

    /**
    @ingroup ZwTable

    Sets text of the specified cell in the table.

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)
    @param [in] column column number (starting from 0)
    @param [in] text cell text

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
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwTableCellTextSet(szwEntityHandle table, int row, int column, const char *text);

    /**
    @ingroup ZwTable

    Gets data type of the specified cell in the table.

    @see ZwTableCellDataTypeSet

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)
    @param [in] column column number (starting from 0)
    @param [out] dataType cell data type

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
    */
    ZW_API_C ezwErrors ZwTableCellDataTypeGet(szwEntityHandle table, int row, int column, ezwTableCellDataType *dataType);

    /**
    @ingroup ZwTable

    Sets data type of the specified cell in the table.

    @see ZwTableCellDataTypeGet

    @param [in] table handle of the table
    @param [in] row row number (starting from 0, -1 to set specified column)
    @param [in] column column number (starting from 0, -1 to set specified row)
    @param [in] dataType cell data type

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
    */
    ZW_API_C ezwErrors ZwTableCellDataTypeSet(szwEntityHandle table, int row, int column, ezwTableCellDataType dataType);

    /**
    @ingroup ZwTable

    Gets the row height of the specified row in the table.

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)
    @param [out] height row height

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
    */
    ZW_API_C ezwErrors ZwTableRowHeightGet(szwEntityHandle table, int row, double *height);

    /**
    @ingroup ZwTable

    Sets the row height of the specified row in the table.

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)
    @param [in] height row height (0.0 to resize row height to contexts)

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
    */
    ZW_API_C ezwErrors ZwTableRowHeightSet(szwEntityHandle table, int row, double height);

    /**
    @ingroup ZwTable

    Gets the column width of the specified column in the table.

    @param [in] table handle of the table
    @param [in] column column number (starting from 0)
    @param [out] width column width

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
    */
    ZW_API_C ezwErrors ZwTableColumnWidthGet(szwEntityHandle table, int column, double *width);

    /**
    @ingroup ZwTable

    Sets the column width of the specified column in the table.

    @param [in] table handle of the table
    @param [in] column column number (starting from 0)
    @param [in] width column width (0.0 to resize column width to contexts)

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
    */
    ZW_API_C ezwErrors ZwTableColumnWidthSet(szwEntityHandle table, int column, double width);

    /**
    @ingroup ZwTable

    Merges the specified cells of the table into one cell.

    @note
    1. The header row can not be merged with the another row.
    2. Locked cell can not be merged with other cells.

    @see ZwTableCellUnMerge

    @param [in] table handle of the table
    @param [in] startRow start row number (starting from 0)
    @param [in] endRow end row number (starting from 0)
    @param [in] startColumn start column number (starting from 0)
    @param [in] endColumn end column number (starting from 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwTableCellMerge(szwEntityHandle table, int startRow, int endRow, int startColumn, int endColumn);

    /**
    @ingroup ZwTable

    Splits cell from the merged cell in the table.

    @see ZwTableCellMerge

    @param [in] table handle of the table
    @param [in] startRow start row number (starting from 0)
    @param [in] endRow end row number (starting from 0)
    @param [in] startColumn start column number (starting from 0)
    @param [in] endColumn end column number (starting from 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwTableCellUnMerge(szwEntityHandle table, int startRow, int endRow, int startColumn, int endColumn);

    /**
    @ingroup ZwTable

    Gets attributes of the specified cell in the table.

    @see ZwTableCellAttributeSet
    @see ZwTableAttributeGet
    @see ZwTableAttributeSet

    @param [in] table handle of the table
    @param [in] row row number (starting from 0)
    @param [in] column column number (starting from 0)
    @param [out] cellAttribute cell attribute (nullptr to ignore)
    @param [out] textAttribute cell text attribute (nullptr to ignore)

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
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle tableHandle = {};
    // some code to get the data of table handle
    ...

    szwTableCellAttribute cellAttribute = {};
    szwTableTextAttribute textAttribute = {};
    ezwErrors ret = ZwTableCellAttributeGet(tableHandle, 0, 0, &cellAttribute, &textAttribute);
    ...

    // free memory of table handle
    ZwEntityHandleFree(&tableHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwTableCellAttributeGet(szwEntityHandle table, int row, int column, szwTableCellAttribute *cellAttribute, szwTableTextAttribute *textAttribute);

    /**
    @ingroup ZwTable

    Sets attributes of the specified cell in the table.

    @note
    As for borderDisplay.mode of cellAttribute, only ZW_DISPLAY_BLANK and ZW_DISPLAY_NORMAL take effect in this case, if you set other value, this function will not  
    throw error and you can get the value by ZwTableCellAttributeGet(), but the real display status can only be blank(ZW_DISPLAY_BLANK) or un-blank(value >=0).

    @see ZwTableCellAttributeGet
    @see ZwTableAttributeGet
    @see ZwTableAttributeSet

    @param [in] table handle of the table
    @param [in] row row number (starting from 0, -1 to set specified column)
    @param [in] column column number (starting from 0, -1 to set specified row)
    @param [in] cellAttribute cell attribute (nullptr to ignore)
    @param [in] textAttribute cell text attribute (nullptr to ignore)

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
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle tableHandle = {};
    // some code to get the data of table handle
    ...

    szwTableCellAttribute cellAttribute = {};
    szwTableTextAttribute textAttribute = {};
    ezwErrors ret = ZwTableCellAttributeGet(tableHandle, 0, 0, &cellAttribute, &textAttribute);
    ...
    ret = ZwTableCellAttributeSet(tableHandle, 0, 0, &cellAttribute, &textAttribute);

    // free memory of table handle
    ZwEntityHandleFree(&tableHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwTableCellAttributeSet(szwEntityHandle table, int row, int column, const szwTableCellAttribute *cellAttribute, const szwTableTextAttribute *textAttribute);

    /**
    @ingroup ZwTable

    Gets attributes of the specified table.

    @see ZwTableAttributeSet
    @see ZwTableCellAttributeGet
    @see ZwTableCellAttributeSet

    @param [in] table handle of the table
    @param [out] tableAttribute table attribute (nullptr to ignore)
    @param [out] textAttribute table text attribute (nullptr to ignore)

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
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle tableHandle = {};
    // some code to get the data of table handle
    ...

    szwTableAttribute tableAttribute = {};
    szwTableTextAttribute textAttribute = {};
    ezwErrors ret = ZwTableAttributeGet(tableHandle, &tableAttribute, &textAttribute);
    ...

    // free memory of table handle
    ZwEntityHandleFree(&tableHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwTableAttributeGet(szwEntityHandle table, szwTableAttribute *tableAttribute, szwTableTextAttribute *textAttribute);

    /**
    @ingroup ZwTable

    Sets attributes of the specified table.

    @see ZwTableAttributeGet
    @see ZwTableCellAttributeGet
    @see ZwTableCellAttributeSet

    @param [in] table handle of the table
    @param [in] tableAttribute table attribute (nullptr to ignore)
    @param [in] textAttribute table text attribute (nullptr to ignore)
    @param [in] updateAllCell update all cells attribute (1: update all cells attribute; 0: update only the cells attribute that are same with the table attribute)

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
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle tableHandle = {};
    // some code to get the data of table handle
    ...

    szwTableAttribute tableAttribute = {};
    szwTableTextAttribute textAttribute = {};
    ezwErrors ret = ZwTableAttributeGet(tableHandle, &tableAttribute, &textAttribute);
    ...
    ret = ZwTableAttributeSet(tableHandle, &tableAttribute, &textAttribute);

    // free memory of table handle
    ZwEntityHandleFree(&tableHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwTableAttributeSet(szwEntityHandle table, const szwTableAttribute *tableAttribute, const szwTableTextAttribute *textAttribute, int updateAllCell);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TABLE_H */
