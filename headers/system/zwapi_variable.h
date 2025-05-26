/**
@file zwapi_variable.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Variables API
*/

#pragma once
#ifndef ZW_API_VARIABLE_H /* this ifndef surrounds entire header */
#define ZW_API_VARIABLE_H

#include "zwapi_variable_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Variable Get */
    //====================================================================================================================

    /**
    @ingroup ZwVariable

    Searches the active part for the variable with the name.  
    If name is NULL, variableList will return all variable in this active file.  

    If the variable is a string variable, the associated text is output via stringValue in szwVariableData.  
    Strings longer than 512 bytes are truncated.

    @note
    The calling procedure MUST deallocate the output list with ZwMemoryFree().

    @param [in] name variable name
    @param [out] count the size of variable list
    @param [out] variableList variable list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    int count=0;
    szwVariableData *variableList=NULL;
    const char* name=...;//NULL if get all variables.
    ZwVariableListGet(name, &count, &variableList);
    ...
    ZwMemoryFree((void**)&variableList);
    @endcode
    */
    ZW_API_C ezwErrors ZwVariableListGet(const zwString32 name, int *count, szwVariableData **variableList);

    //====================================================================================================================
    /** @name Variable Set */
    //====================================================================================================================

    /**
    @ingroup ZwVariable

    Updates the variables (e.g. dimensions, parameters) specified  
    by "variableList" in the specified root object within the active  
    file.  The root object is then regenerated.  

    You can disable the object regeneration normally performed by  
    this function by inputing "working = -1".  

    This function can not change the type of variable.  

    expression format of string type :"\"str\"";  
    Also, string type can also store expression which is concatenated with substrings, like "num2str(A)+\"-\"+num2str(B)";  
    expression format of point type :"Point(1,2,3)";  
    expression format of vector type :"Vector(1,2,3)";  
    If you fill the value of szwVariableData, the expression will be filled too.  

    If the type of variable is set to 0,then the sub_type must be set,else ignore.  
    If the subType of variable is set to 1 or 2,then the unitType must be set,else ignore.  

    ezwUnitType for length unit and evxAngUnitType for angle unit.

    @param [in] count number of variables
    @param [in] variableList list of variables
    @param [in] working 1 to display "working..." message, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwVariableListSet(int count, const szwVariableData *variableList, int working);

    //====================================================================================================================
    /** @name Variable Create */
    //====================================================================================================================

    /**
    @ingroup ZwVariable
    
    Adds the specified variable to the active file.
    
    expression format of string type :"\"str\"";  
    Also, string type can also store expression which is concatenated with substrings, like "num2str(A)+\"-\"+num2str(B)";  
    expression format of point type :"Point(1,2,3)";  
    expression format of vector type :"Vector(1,2,3)";  
    If you fill the value of szwVariableData, the expression will be filled too. 
    
    If the type of variable is set to 0,then the subType must be set,else ignore.  
    If the subType of variable is set to 1 or 2,then the unitType must be set,else ignore.  
    
    @param [in] variable definition of a variable
    
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
    */
    ZW_API_C ezwErrors ZwVariableCreate(szwVariableData variable);

    //====================================================================================================================
    /** @name Variable in Variable Browser */
    //====================================================================================================================

    /**
    @ingroup ZwVariable

    Outputs the value of the specified standard attribute variable in current file.  
    Enumeration ezwVariableStandardAttributeItem corresponds to the variables in the  
    variable browser one by one. 

    @note
    In drawing file, all items are supported 
    In part file, ZW_VARIABLE_PART_NAME~ZW_VARIABLE_PART_SHEET_METAL_WIDTH are supported.  
    In sketch file, only ZW_VARIABLE_PROP_NAME ~ZW_VARIABLE_PROP_DESCRIPTION are supported.  

    @param [in] itemId item id of standard attribute variable
    @param [in] size length of bytes to be get
    @param [out] value value of the specified standard attribute variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwVariableStandardAttributeItemGet(ezwVariableStandardAttributeItem itemId, int size, char *value);


    //====================================================================================================================
    /** @name Variable Text */
    //====================================================================================================================

    /**
    @ingroup ZwVariable

    Solves all variables in the active root object, the text objects showed in drawing area which refers the variables will be 
    updated.  

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwVariableTextRefresh();

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VARIABLE_H */
