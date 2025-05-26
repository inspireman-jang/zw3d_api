/**
@file zwapi_assembly_constraint.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Constraints Query API
*/

#pragma once
#ifndef ZW_API_ASSEMBLY_CONSTRAINT_H /* this ifndef surrounds entire header */
#define ZW_API_ASSEMBLY_CONSTRAINT_H

#include "zwapi_assembly_constraint_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Constraint Operate */
    //====================================================================================================================
    /**
    @ingroup ZwAssemblyConstraint
    
    Creates a coincident constraint, the components will remain coincident.
    Function Guide: Assembly->Constraint->Coincident

    @note 
    The caller is responsible to free the handle by using ZwEntityHandleFree().
    
    @param [in] entity1 the first entity handle(edge,curve,face,datum,point,datum axis)
    @param [in] point1 coordinate of the coincidence point on the first entity (NULL to ignore)
    @param [in] entity2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] point2 coordinate of the coincidence point on the second entity (NULL to ignore)
    @param [in] constraintData constraint custom data (NULL to use default value)
    @param [out] constraintHandle new constraint handle (NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwConstraintCoincidentAdd(szwEntityHandle entity1, const szwPoint *point1, szwEntityHandle entity2, const szwPoint *point2, const szwAssemblyConstraintData *constraintData, szwEntityHandle *constraintHandle);

    /**
    @ingroup ZwAssemblyConstraint

    Get the dimension associated with constraint.

    @note
    If the constraint doesn't have a dimension, the innerData of dimensionHandle is null, but return no error.
    In this function, dimensionHandle will be allocated memory, so remember to deallocate it by ZwEntityHandleFree.

    @code
    //get the handle of the constraint that you want to get.
    szwEntityHandle constraintHandle=...;
    //the handle you will get by constraint handle.
    szwEntityHandle dimensionHandle;
    ZwAssemblyConstraintDimensionGet(constranintHandle,&dimensionHandle);
    //free handle.
    ZwEntityHandleFree(&dimensionHandle);
    @endcode

    @param [in] constraintHandle constraint handle
    @param [out] dimensionHandle dimension handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR

    */
    ZW_API_C ezwErrors ZwAssemblyConstraintDimensionGet(szwEntityHandle constraintHandle, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwAssemblyConstraint

    Gets constraint data of the specified constraint.

    @note
    The angle constraint type does not support getting the szwAssemblyConstraintData::sameDirection flag.

    @see ZwAssemblyConstraintDataSet

    @param [in] constraintHandle constraint handle
    @param [out] data constraint data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR

    @code
    //get the handle of the constraint that you want to get.
    szwEntityHandle constraintHandle = {};
    ...

    //get constraint data.
    szwAssemblyConstraintData data = {};
    ezwErrors ret = ZwAssemblyConstraintDataGet(constranintHandle, &data);

    //free handle.
    ZwEntityHandleFree(&constraintHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwAssemblyConstraintDataGet(szwEntityHandle constraintHandle, szwAssemblyConstraintData *data);

    /**
    @ingroup ZwAssemblyConstraint

    Sets constraint data of the specified constraint.

    @see ZwAssemblyConstraintDataGet

    @param [in] constraintHandle constraint handle
    @param [in] data constraint data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwAssemblyConstraintDataSet(szwEntityHandle constraintHandle, szwAssemblyConstraintData data);

    /**
    @ingroup ZwAssemblyConstraint

    Gets the constraint type of specified constraint.

    @param [in] constraintHandle handle of constraint
    @param [out] type constraint type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DAT_GET_ERROR
    */
    ZW_API_C ezwErrors ZwAssemblyConstraintTypeGet(szwEntityHandle constraintHandle, ezwAssemblyConstraintType *type);

    /**
    @ingroup ZwAssemblyConstraint

    Outputs a list of handles of entities associated with the specified constraint.

    @note
    The calling procedure MUST deallocate the output list with ZwEntityHandleListFree().

    @param [in] constraintHandle handle of constraint
    @param [out] count number of entities associated with constraint
    @param [out] referenceList list of entity paths associated with constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwAssemblyConstraintReferenceListGet(szwEntityHandle constraintHandle, int *count, szwEntityHandle **referenceList);

    /**
    @ingroup ZwAssemblyConstraint

    Gets the UI node name of the specified constraint, which is displayed on assembly tree.

    @param [in] constraintHandle handle of constraint
    @param [in] nameSize max size of nodeName
    @param [out] nodeName node name of the constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwAssemblyConstraintNodeNameGet(szwEntityHandle constraintHandle, int nameSize, char *nodeName);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ASSEMBLY_CONSTRAINT_H */
