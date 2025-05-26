/**
@file zwapi_sk_var.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch Variable API
*/
/**
@defgroup zwapi_sk_var Sketch Variable API
@ingroup SketchObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Sketch Variable API
*/

#pragma once
#ifndef ZW_API_SK_VAR_H /* this ifndef surrounds entire header */
#define ZW_API_SK_VAR_H

#include "zwapi_sk_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Variable */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_var

    Adds the specified variable to the active sketch or drawing.

    Expression format of string type :"\"str\"";  
    Also, string type can also store expression which is concatenated with substrings, like "num2str(A)+\"-\"+num2str(B)";  
    Expression format of point type :"Point(1,2,3)";  
    Expression format of vector type :"Vector(1,2,3)";  

    @deprecated This API will not be updated anymore, please use ZwVariableCreate()
    @see ZwVariableCreate

    @param [in] Variable definition of a variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxSkVarAdd(svxVariable *Variable);

    /**
    @ingroup zwapi_sk_var

    Searches the active sketch or drawing for the variable named "Variable->Name".

    The value of the specified variable is output via  
    "Variable->Value" in database units (mm, deg).

    If "Variable->Name" is a string variable, the associated  
    text is output via "Variable->Expression".  Strings longer  
    than 256 bytes are truncated.

    @deprecated This API will not be updated anymore, please use ZwVariableListGet()
    @see ZwVariableListGet

    @param [in,out] Variable variable data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxSkVarGet(svxVariable *Variable);

    /**
    @ingroup zwapi_sk_var

    Updates the sketch or drawing variables specified by "Variables".

    @deprecated This API will not be updated anymore, please use ZwVariableListSet()
    @see ZwVariableListSet

    @param [in] Count number of variables
    @param [in] Variables list of variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxSkVarSet(int Count, svxVariable *Variables);

    /**
    @ingroup zwapi_sk_var

    Outputs a list of variables that belong to the active sketch or drawing.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] Count number of variables
    @param [out] Variables list of variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxSkInqVars(int *Count, svxVariable **Variables);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_VAR_H */
