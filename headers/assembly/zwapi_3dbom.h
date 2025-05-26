/**
@file zwapi_3dbom.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D 3D BOM API
*/

#pragma once
#ifndef ZWAPI_3DBOM_H /* this ifndef surrounds entire header */
#define ZWAPI_3DBOM_H

#include "zwapi_asm_data.h"
#include "zwapi_3dbom_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name 3D BOM Data */
    //====================================================================================================================
    
    /**
    @ingroup Zw3DBOM

    Gets row information for display in 3D BOM table.

    @note
    The caller is responsible to free the data by using Zw3DBomDataFree().

    @see Zw3DBomDataFree

    @param [out] data table data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_TABLE_GETDATA_ERROR

    @code
    szw3DBomData data{};
    Zw3DBomDataGet(&data);
    ...
    Zw3DBomDataFree(&data);

    @endcode
    */
    ZW_API_C ezwErrors Zw3DBomDataGet(szw3DBomData *data);

    /**
    @ingroup Zw3DBOM

    Frees memory associated with the specified szw3DBomData structure.

    @see Zw3DBomDataGet

    @param [in,out] data szw3DBomData structure

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors Zw3DBomDataFree(szw3DBomData *data);

    /**
    @ingroup Zw3DBOM

    Exports the data of 3D BOM into an excel file.  

    @note
    The file must use one of the extensions xls, xlsx and csv.  

    @param [in] filePath  path of excel file to export

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors Zw3DBomDataExport(const char *filePath);


    //====================================================================================================================
    /** @name 3D BOM Setting */
    //====================================================================================================================

    /**
    @ingroup Zw3DBOM
    
    Gets the display content of the 3D BOM table through the interface.
    
    @note
    The caller is responsible to free the data by using Zw3DBomSettingDataFree().

    @see Zw3DBomSettingSet Zw3DBomSettingDataFree
    
    @param [out] data  settings data of 3D BOM table
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    
    @code
    szw3DBomSettingsData data{};
    Zw3DBomSettingGet(&data);
    ...
    Zw3DBomSettingDataFree(szw3DBomSettingsData *data);
    @endcode
    */
    ZW_API_C ezwErrors Zw3DBomSettingGet(szw3DBomSettingsData *data);

    /**
    @ingroup Zw3DBOM
    
    Sets the display content of the 3D BOM table through the interface.

    @note
    The caller is responsible to free the data by using Zw3DBomSettingDataFree().

    @see Zw3DBomSettingGet Zw3DBomSettingDataFree
    
    @param [in] data  settings data of 3D BOM table
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_FUCNTION_CB_EXECUTION_ERROR
    -        ZW_API_FUNCTION_CB_GET_ERROR
    -        ZW_API_FUCNTION_CB_EXIST_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    ZW_API_C ezwErrors Zw3DBomSettingSet(szw3DBomSettingsData data);

    /**
    @ingroup Zw3DBOM
    
    Frees memory associated with the specified szw3DBomSettingsData structure.
    
    @param [in,out] data szw3DBomSettingsData structure
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors Zw3DBomSettingDataFree(szw3DBomSettingsData *data);

    /**
    @ingroup Zw3DBOM

    Gets the format data of the 3D BOM about how to show the row data.  

    @param [out] formatData data to get the format settings about 3D BOM
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors Zw3DBomFormatDataGet(szw3DBomFormatData *formatData);

    /**
    @ingroup Zw3DBOM

    Sets the format data of the 3D BOM about how to show the row data.  

    @param [in] formatData data to set the format settings about 3D BOM
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors Zw3DBomFormatDataSet(szw3DBomFormatData formatData);

    /**
    @ingroup Zw3DBOM
    
    Excludes the specified component from 3D BOM table.  
    It will find the row which contains the component, then 
    exclude the row with all components that includes.
    
    If the component was excluded, it will do nothing.  

    @param [in] component component in active file
    @param [in] excludeOption exclude option(0 - exclude the item and all children, 1 - exclude the item only)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors Zw3DBomExcludedStateSet(szwEntityHandle component, int excludeOption);

    /**
    @ingroup Zw3DBOM

    Set the default template file of 3D BOM and apply it.  

    @note
    The template file must be a format file of BOM that exported by ZW3D. It's extension should be 'Z3DBOMTT'.  

    @param [in] templateFile path of template format file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors Zw3DBomTemplateSet(const char *templateFile);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_3DBOM_H */