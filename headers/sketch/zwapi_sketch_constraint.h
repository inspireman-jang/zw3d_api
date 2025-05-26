/**
@file zwapi_sketch_constraint.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch Constraint API
*/

#pragma once
#ifndef ZW_API_SKETCH_CONSTRAINT_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_CONSTRAINT_H

#include "zwapi_sketch_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Constraint Query */
    //====================================================================================================================

    /**
    @ingroup ZwSketchConstraint

    Solves the constraints of the active sketch.  

    @note
    This function will make the file be modified as the command 'Constraint Status' does.  

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwSketchConstraintSolve();

    /**
    @ingroup ZwSketchConstraint

    Inquires the constraint status of the active sketch and retrieves the geometries.  

    Function Guide: Sketch->Settings->Constraint Status  

    @see ZwSketchConstraintStatusDataFree

    @note
    The caller is responsible to free the geometryData by using ZwSketchConstraintStatusDataFree().  
    To get a correct result, it's recommended that to use this function with 'solveConstraints = 1'.  
    When the input parameter 'solveConstraints' is 1, this function will make the file be modified as 
    the command 'Constraint Status' does.  

    @param [in] solveConstraints whether to solve the constraints before inquire the data, 1-yes, 0-no
    @param [out] status constraint status, 1 for all geometries are well defined, else 0
    @param [out] geometryData geometry list with over defined, under defined and well defined constraints(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    int status = 0;
    szwSketchGeometryConstraintData data{};
    ezwErrors err = ZwSketchConstraintStatusGet(1, &status, &data);
    ...
    // free the data
    err = ZwSketchConstraintStatusDataFree(&data);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchConstraintStatusGet(int solveConstraints, int *status, szwSketchGeometryConstraintData *geometryData);

    /**
    @ingroup ZwSketchConstraint

    Frees the data of szwSketchGeometryConstraintData.

    @see ZwSketchConstraintStatusGet

    @param [in] geometryData data of szwSketchGeometryConstraintData

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwSketchConstraintStatusDataFree(szwSketchGeometryConstraintData *geometryData);

    /**
    @ingroup ZwSketchConstraint

    Retrieves all constraints of the specified geometry.

    @note
    The caller is responsible to free the constraintList by using ZwEntityHandleListFree().

    @param [in] geometry a geometry object of sketch environment
    @param [out] count count of the constraints
    @param [out] constraintList handles of constraintList

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwSketchGeometryConstraintListGet(szwEntityHandle geometry, int *count, szwEntityHandle **constraintList);

    /**
    @ingroup ZwSketchConstraint

    Outputs the data of the specified pattern constraint.

    @param [in] constraint handle of pattern constraint
    @param [out] patternData data of pattern constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwSketchPatternConstraintDataGet(szwEntityHandle constraint, szwSketchPatternData *patternData);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_CONSTRAINT_H */
